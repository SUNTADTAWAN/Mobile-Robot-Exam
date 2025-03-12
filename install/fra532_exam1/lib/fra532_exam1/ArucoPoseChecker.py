#!/usr/bin/python3


import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import tf2_ros
import tf2_geometry_msgs

class ArucoPoseChecker(Node):
    def __init__(self):
        super().__init__('aruco_pose_checker')
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        self.aruco_sub = self.create_subscription(
            PoseStamped, '/aruco_marker_pose', self.aruco_callback, 10)
        self.odom_sub = self.create_subscription(
            PoseStamped, '/odom', self.odom_callback, 10)

        self.aruco_pose = None
        self.odom_pose = None

    def aruco_callback(self, msg):
        try:
            transform = self.tf_buffer.lookup_transform(
                'base_footprint', msg.header.frame_id, rclpy.time.Time())

            transformed_pose = tf2_geometry_msgs.do_transform_pose(msg, transform)
            self.aruco_pose = transformed_pose.pose

        except tf2_ros.LookupException as e:
            self.get_logger().warn(f"TF Lookup failed: {e}")

    def odom_callback(self, msg):
        self.odom_pose = msg.pose

        if self.aruco_pose and self.odom_pose:
            self.compare_positions()

    def compare_positions(self):
        error_x = abs(self.aruco_pose.position.x - self.odom_pose.position.x)
        error_y = abs(self.aruco_pose.position.y - self.odom_pose.position.y)
        self.get_logger().info(f"Error X: {error_x:.3f} m, Error Y: {error_y:.3f} m")

def main(args=None):
    rclpy.init(args=args)
    node = ArucoPoseChecker()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
