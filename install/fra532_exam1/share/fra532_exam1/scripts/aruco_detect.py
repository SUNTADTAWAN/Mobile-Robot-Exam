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


class ArucoLocalization(Node):
    def __init__(self):
        super().__init__('aruco_localization')

        # ROS2 image subscribers (4 Cameras)
        self.image_subs = {
            "front_camera": self.create_subscription(Image, "/front_camera/image_raw", self.image_callback, 10),
            "rear_camera": self.create_subscription(Image, "/rear_camera/image_raw", self.image_callback, 10),
            "left_camera": self.create_subscription(Image, "/left_camera/image_raw", self.image_callback, 10),
            "right_camera": self.create_subscription(Image, "/right_camera/image_raw", self.image_callback, 10),
        }

        # Publishers
        self.image_pub = self.create_publisher(Image, '/aruco_detected_image', 10)
        self.pose_pub = self.create_publisher(PoseStamped, '/aruco_marker_pose', 10)
        self.tf_broadcaster = tf2_ros.TransformBroadcaster(self)

        self.bridge = CvBridge()

        # Load the Aruco dictionary
        self.aruco_dict = aruco.getPredefinedDictionary(aruco.DICT_ARUCO_ORIGINAL)
        self.parameters = aruco.DetectorParameters_create()

        # Camera Intrinsic Parameters (Adjust based on calibration)
        self.camera_matrix = np.array([[320.2549, 0, 320.5],
                                       [0, 320.2549, 240.5],
                                       [0, 0, 1]], dtype=np.float32)

        self.dist_coeffs = np.zeros((5, 1))  # Assume no lens distortion

        self.get_logger().info("Aruco Localization Node Initialized.")

    def image_callback(self, msg):
        try:
            # Identify which camera the image came from
            camera_frame = msg.header.frame_id if msg.header.frame_id else "unknown_camera"

            # Convert ROS2 Image to OpenCV format
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

            # Convert to grayscale
            gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)

            # Detect Aruco markers
            corners, ids, _ = aruco.detectMarkers(gray, self.aruco_dict, parameters=self.parameters)

            if ids is not None:
                self.get_logger().info(f"[{camera_frame}] Detected ArUco IDs: {ids.flatten()}")

                # Draw detected markers on the image
                aruco.drawDetectedMarkers(cv_image, corners, ids)

                # Pose estimation (20 cm marker size)
                marker_size = 0.1778   # 20 cm
                rvecs, tvecs, _ = aruco.estimatePoseSingleMarkers(
                    corners, marker_size, self.camera_matrix, self.dist_coeffs
                )

                for i, marker_id in enumerate(ids.flatten()):
                    rvec, tvec = rvecs[i], tvecs[i]

                    # Draw the axis on the marker
                    cv2.drawFrameAxes(cv_image, self.camera_matrix, self.dist_coeffs, rvec, tvec, 0.05)

                    # Publish marker position as a PoseStamped message
                    pose_msg = PoseStamped()
                    pose_msg.header.stamp = self.get_clock().now().to_msg()
                    pose_msg.header.frame_id = camera_frame  # Frame of the detecting camera
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

                    self.get_logger().info(f"[{camera_frame}] Marker {marker_id} Position: x={tvec[0][0]:.2f}, y={tvec[0][1]:.2f}, z={tvec[0][2]:.2f}")

                    # Broadcast TF transform from "aruco_marker_X" to "world"
                    transform_stamped = TransformStamped()
                    transform_stamped.header.stamp = self.get_clock().now().to_msg()
                    transform_stamped.header.frame_id = "world"  # Fixed world frame
                    transform_stamped.child_frame_id = f"aruco_marker_{marker_id}"
                    transform_stamped.transform.translation.x = tvec[0][0]
                    transform_stamped.transform.translation.y = tvec[0][1]
                    transform_stamped.transform.translation.z = tvec[0][2]
                    transform_stamped.transform.rotation.x = quaternion[0]
                    transform_stamped.transform.rotation.y = quaternion[1]
                    transform_stamped.transform.rotation.z = quaternion[2]
                    transform_stamped.transform.rotation.w = quaternion[3]

                    self.tf_broadcaster.sendTransform(transform_stamped)

            # Convert back to ROS2 Image message and publish
            detected_image_msg = self.bridge.cv2_to_imgmsg(cv_image, encoding="bgr8")
            self.image_pub.publish(detected_image_msg)

        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

def main(args=None):
    rclpy.init(args=args)
    node = ArucoLocalization()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
