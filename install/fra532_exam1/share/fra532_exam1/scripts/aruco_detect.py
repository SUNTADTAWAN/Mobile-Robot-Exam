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

        # TF Buffer & Listener
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        # Load the Aruco dictionary
        self.aruco_dict = aruco.getPredefinedDictionary(aruco.DICT_ARUCO_ORIGINAL)
        self.parameters = aruco.DetectorParameters_create()

        # Camera Intrinsic Parameters (From `/camera_info`)
        self.camera_matrix = np.array([[320.2549, 0, 320.5],
                                       [0, 320.2549, 240.5],
                                       [0, 0, 1]], dtype=np.float32)

        self.dist_coeffs = np.zeros((5, 1))  # Assume no lens distortion

        # Marker size (20 cm)
        self.marker_size = 0.20

        # List to store detected marker positions
        self.detected_markers = {}

        self.get_logger().info("Aruco Pole Localization Node Initialized.")

    def image_callback(self, msg):
        try:
            # Identify camera frame
            camera_frame = msg.header.frame_id if msg.header.frame_id else "unknown_camera"

            if camera_frame not in ["front_link", "rear_link", "left_link", "right_link"]:
                self.get_logger().warn(f"Unknown camera frame: {camera_frame}, using default 'front_link'")
                camera_frame = "front_link"

            # Convert ROS2 Image to OpenCV format
            cv_image = self.bridge.imgmsg_to_cv2(msg, desired_encoding="bgr8")

            # Convert to grayscale
            gray = cv2.cvtColor(cv_image, cv2.COLOR_BGR2GRAY)

            # Detect Aruco markers
            corners, ids, _ = aruco.detectMarkers(gray, self.aruco_dict, parameters=self.parameters)

            if ids is not None:
                self.get_logger().info(f"[{camera_frame}] Detected ArUco IDs: {ids.flatten()}")
                aruco.drawDetectedMarkers(cv_image, corners, ids)

                # Pose estimation
                rvecs, tvecs, _ = aruco.estimatePoseSingleMarkers(
                    corners, self.marker_size, self.camera_matrix, self.dist_coeffs
                )

                for i, marker_id in enumerate(ids.flatten()):
                    rvec, tvec = rvecs[i], tvecs[i]
                    self.detected_markers[marker_id] = tvec[0]
                    self.publish_marker_tf(marker_id, tvec[0], rvec, camera_frame)

            # Convert back to ROS2 Image message and publish
            detected_image_msg = self.bridge.cv2_to_imgmsg(cv_image, encoding="bgr8")
            self.image_pub.publish(detected_image_msg)

            # Estimate pole position
            if len(self.detected_markers) >= 1:
                self.estimate_pole_position()

        except Exception as e:
            self.get_logger().error(f"Error processing image: {str(e)}")

    def publish_marker_tf(self, marker_id, tvec, rvec, camera_frame):
        """ Publish TF transform of the detected marker """
        rotation_matrix, _ = cv2.Rodrigues(rvec)
        quaternion = tf_transformations.quaternion_from_matrix(
            np.vstack((np.hstack((rotation_matrix, [[0], [0], [0]])), [0, 0, 0, 1]))
        )

        transform_stamped = TransformStamped()
        transform_stamped.header.stamp = self.get_clock().now().to_msg()
        transform_stamped.header.frame_id = camera_frame
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
        """ Compute the pole's position in world frame using TF """
        x_values, y_values, z_values = [], [], []

        for marker_id, position in self.detected_markers.items():
            try:
                # Lookup TF transform from camera frame to world
                trans = self.tf_buffer.lookup_transform("world", f"aruco_marker_{marker_id}", rclpy.time.Time())

                world_x = trans.transform.translation.x
                world_y = trans.transform.translation.y
                world_z = trans.transform.translation.z

                x_values.append(world_x)
                y_values.append(world_y)
                z_values.append(world_z)

            except tf2_ros.LookupException as e:
                self.get_logger().warn(f"TF lookup failed for marker {marker_id}: {e}")

        if len(x_values) < 2:
            self.get_logger().warn("Not enough markers detected for pole localization.")
            return

        pole_x = np.mean(x_values)
        pole_y = np.mean(y_values)
        pole_z = np.mean(z_values)

        self.get_logger().info(f"Estimated Pole Position (world frame): x={pole_x:.2f}, y={pole_y:.2f}, z={pole_z:.2f}")

        # Publish PoseStamped
        pole_pose = PoseStamped()
        pole_pose.header.stamp = self.get_clock().now().to_msg()
        pole_pose.header.frame_id = "world"
        pole_pose.pose.position.x = pole_x
        pole_pose.pose.position.y = pole_y
        pole_pose.pose.position.z = pole_z
        pole_pose.pose.orientation.w = 1.0  # No rotation assumed

        self.pose_pub.publish(pole_pose)

        # Publish TF transform for pole
        transform_stamped = TransformStamped()
        transform_stamped.header.stamp = self.get_clock().now().to_msg()
        transform_stamped.header.frame_id = "world"
        transform_stamped.child_frame_id = "pole"
        transform_stamped.transform.translation.x = pole_x
        transform_stamped.transform.translation.y = pole_y
        transform_stamped.transform.translation.z = pole_z
        transform_stamped.transform.rotation.w = 1.0

        self.tf_broadcaster.sendTransform(transform_stamped)


def main(args=None):
    rclpy.init(args=args)
    node = ArucoPoleLocalization()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
