#!/usr/bin/python3

import rclpy
from rclpy.node import Node
import cv2
import numpy as np
from cv_bridge import CvBridge
from sensor_msgs.msg import Image
from geometry_msgs.msg import PoseStamped, TransformStamped
from cv2 import aruco
import tf2_ros
import tf_transformations


class ArucoPoleLocalization(Node):
    def __init__(self):
        super().__init__('aruco_pole_localization')

        # ROS2 image subscriber
        self.image_sub = self.create_subscription(
            Image, 
            '/front_camera/image_raw',  # Change to the correct topic if needed
            self.image_callback, 
            10)
        
        self.image_pub = self.create_publisher(
            Image, 
            '/aruco_detected_image', 
            10)

        self.pose_pub = self.create_publisher(
            PoseStamped,
            '/pole_pose',
            10
        )

        self.tf_broadcaster = tf2_ros.TransformBroadcaster(self)
        self.bridge = CvBridge()

        # Load the Aruco dictionary
        self.aruco_dict = aruco.getPredefinedDictionary(aruco.DICT_ARUCO_ORIGINAL)
        self.parameters = aruco.DetectorParameters_create()

        # Camera Intrinsic Parameters
        self.camera_matrix = np.array([[600, 0, 320],
                                       [0, 600, 240],
                                       [0, 0, 1]], dtype=np.float32)
        self.dist_coeffs = np.zeros((5, 1))  # Assume no lens distortion
        
        # Marker size in meters
        self.marker_size = 0.1  # 10 cm
        
        self.get_logger().info("Aruco Pole Localization Node Initialized.")

    def image_callback(self, msg):
        try:
            # Convert ROS2 Image to OpenCV format
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

            # Convert to grayscale
            gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)

            # Detect Aruco markers
            corners, ids, _ = aruco.detectMarkers(gray, self.aruco_dict, parameters=self.parameters)

            if ids is not None:
                self.get_logger().info(f"Detected ArUco IDs: {ids.flatten()}")

                # Draw detected markers on the image
                aruco.drawDetectedMarkers(cv_image, corners, ids)

                # Pose estimation
                rvecs, tvecs, _ = aruco.estimatePoseSingleMarkers(
                    corners, self.marker_size, self.camera_matrix, self.dist_coeffs
                )

                for i, marker_id in enumerate(ids.flatten()):
                    rvec, tvec = rvecs[i], tvecs[i]

                    # Draw the axis on the marker
                    cv2.drawFrameAxes(cv_image, self.camera_matrix, self.dist_coeffs, rvec, tvec, 0.05)

                    # Publish marker position as a PoseStamped message
                    self.publish_pose(marker_id, tvec, rvec)

            # Convert back to ROS2 Image message and publish
            detected_image_msg = self.bridge.cv2_to_imgmsg(cv_image, encoding="bgr8")
            self.image_pub.publish(detected_image_msg)

        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

    def publish_pose(self, marker_id, tvec, rvec):
        pose_msg = PoseStamped()
        pose_msg.header.stamp = self.get_clock().now().to_msg()
        pose_msg.header.frame_id = "camera_link"
        pose_msg.pose.position.x = tvec[0][0]
        pose_msg.pose.position.y = tvec[0][1]
        pose_msg.pose.position.z = tvec[0][2]

        # Convert rotation vector to quaternion
        rotation_matrix, _ = cv2.Rodrigues(rvec)
        quaternion = tf_transformations.quaternion_from_matrix(
            np.vstack((np.hstack((rotation_matrix, [[0], [0], [0]])), [0, 0, 0, 1]))
        )

        pose_msg.pose.orientation.x = quaternion[0]
        pose_msg.pose.orientation.y = quaternion[1]
        pose_msg.pose.orientation.z = quaternion[2]
        pose_msg.pose.orientation.w = quaternion[3]

        self.pose_pub.publish(pose_msg)
        self.get_logger().info(f"Published Pose for Marker {marker_id}: {pose_msg.pose.position}")

        # Publish TF transform
        transform_stamped = TransformStamped()
        transform_stamped.header.stamp = self.get_clock().now().to_msg()
        transform_stamped.header.frame_id = "world"
        transform_stamped.child_frame_id = f"aruco_marker_{marker_id}"
        transform_stamped.transform.translation.x = tvec[0][0]
        transform_stamped.transform.translation.y = tvec[0][1]
        transform_stamped.transform.translation.z = tvec[0][2]
        transform_stamped.transform.rotation.x = quaternion[0]
        transform_stamped.transform.rotation.y = quaternion[1]
        transform_stamped.transform.rotation.z = quaternion[2]
        transform_stamped.transform.rotation.w = quaternion[3]

        self.tf_broadcaster.sendTransform(transform_stamped)


def main(args=None):
    rclpy.init(args=args)
    node = ArucoPoleLocalization()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()