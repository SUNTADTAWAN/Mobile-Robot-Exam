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

        # ROS2 image subscribers (4 Cameras)
        self.image_subs = {
            "front_camera": self.create_subscription(Image, "/front_camera/image_raw", self.image_callback, 10),
            "rear_camera": self.create_subscription(Image, "/rear_camera/image_raw", self.image_callback, 10),
            "left_camera": self.create_subscription(Image, "/left_camera/image_raw", self.image_callback, 10),
            "right_camera": self.create_subscription(Image, "/right_camera/image_raw", self.image_callback, 10),
        }

        # Publishers
        self.image_pub = self.create_publisher(Image, '/aruco_detected_image', 10)
        self.pose_pub = self.create_publisher(PoseStamped, '/pole_pose', 10)
        self.tf_broadcaster = tf2_ros.TransformBroadcaster(self)

        self.bridge = CvBridge()

        # Load the Aruco dictionary
        self.aruco_dict = aruco.getPredefinedDictionary(aruco.DICT_4X4_50)
        self.parameters = aruco.DetectorParameters_create()

        # Camera Intrinsic Parameters (Adjust based on calibration)
        self.camera_matrix = np.array([[320.2549, 0, 320.5],
                                       [0, 320.2549, 240.5],
                                       [0, 0, 1]], dtype=np.float32)

        self.dist_coeffs = np.zeros((5, 1))  # Assume no lens distortion

        # Marker size (20 cm = 0.2 meters)
        self.marker_size = 0.2

        # List to store detected marker positions
        self.detected_markers = {}

        self.get_logger().info("Aruco Pole Localization Node Initialized.")

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

                # Pose estimation
                rvecs, tvecs, _ = aruco.estimatePoseSingleMarkers(
                    corners, self.marker_size, self.camera_matrix, self.dist_coeffs
                )

                for i, marker_id in enumerate(ids.flatten()):
                    rvec, tvec = rvecs[i], tvecs[i]

                    # Store detected marker positions
                    self.detected_markers[marker_id] = tvec[0]

                    # Draw the axis on the marker
                    cv2.drawFrameAxes(cv_image, self.camera_matrix, self.dist_coeffs, rvec, tvec, 0.05)

                    # Publish marker transform
                    self.publish_marker_tf(marker_id, tvec[0], rvec)

            # Convert back to ROS2 Image message and publish
            detected_image_msg = self.bridge.cv2_to_imgmsg(cv_image, encoding="bgr8")
            self.image_pub.publish(detected_image_msg)

            # If at least two markers are detected, estimate the pole position
            if len(self.detected_markers) >= 2:
                self.estimate_pole_position()

        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

    def publish_marker_tf(self, marker_id, tvec, rvec):
        """ Publish TF transform of the detected marker """
        rotation_matrix, _ = cv2.Rodrigues(rvec)
        quaternion = tf_transformations.quaternion_from_matrix(
            np.vstack((np.hstack((rotation_matrix, [[0], [0], [0]])), [0, 0, 0, 1]))
        )

        transform_stamped = TransformStamped()
        transform_stamped.header.stamp = self.get_clock().now().to_msg()
        transform_stamped.header.frame_id = "world"  # Ensure the world frame is used
        transform_stamped.child_frame_id = f"aruco_marker_{marker_id}"
        transform_stamped.transform.translation.x = tvec[0]
        transform_stamped.transform.translation.y = tvec[1]
        transform_stamped.transform.translation.z = tvec[2]
        transform_stamped.transform.rotation.x = quaternion[0]
        transform_stamped.transform.rotation.y = quaternion[1]
        transform_stamped.transform.rotation.z = quaternion[2]
        transform_stamped.transform.rotation.w = quaternion[3]

        self.tf_broadcaster.sendTransform(transform_stamped)


    def estimate_pole_position(self):
        """ Compute the pole's position by averaging marker positions """
        x_values, y_values, z_values = [], [], []

        for marker_id, position in self.detected_markers.items():
            x_values.append(position[0])
            y_values.append(position[1])
            z_values.append(position[2])

        pole_x = np.mean(x_values)
        pole_y = np.mean(y_values)
        pole_z = np.mean(z_values) - 0.2  # Adjust for marker placement

        self.get_logger().info(f"Estimated Pole Position: x={pole_x:.2f}, y={pole_y:.2f}, z={pole_z:.2f}")

        # Publish pole pose as a PoseStamped message
        pole_pose = PoseStamped()
        pole_pose.header.stamp = self.get_clock().now().to_msg()
        pole_pose.header.frame_id = "base_link"
        pole_pose.pose.position.x = pole_x
        pole_pose.pose.position.y = pole_y
        pole_pose.pose.position.z = pole_z
        pole_pose.pose.orientation.w = 1.0  # No rotation assumed

        self.pose_pub.publish(pole_pose)

        # ✅ NEW: Publish a TF Transform from "world" to "pole"
        transform_stamped = TransformStamped()
        transform_stamped.header.stamp = self.get_clock().now().to_msg()
        transform_stamped.header.frame_id = "world"  # Fix frame
        transform_stamped.child_frame_id = "pole"  # Pole frame
        transform_stamped.transform.translation.x = pole_x
        transform_stamped.transform.translation.y = pole_y
        transform_stamped.transform.translation.z = pole_z
        transform_stamped.transform.rotation.w = 1.0  # No rotation

        self.tf_broadcaster.sendTransform(transform_stamped)



def main(args=None):
    rclpy.init(args=args)
    node = ArucoPoleLocalization()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
