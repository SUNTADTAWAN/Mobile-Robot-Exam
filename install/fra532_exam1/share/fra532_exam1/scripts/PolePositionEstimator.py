#!/usr/bin/python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import tf2_ros
import tf2_geometry_msgs
import math

class PolePositionEstimator(Node):
    def __init__(self):
        super().__init__('pole_position_estimator')
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)

        self.pose_sub = self.create_subscription(
            PoseStamped, '/aruco_marker_pose_base', self.pose_callback, 10)

    def pose_callback(self, msg):
        try:
            # หา Transform จากเสา (pole_link) ไปยังหุ่นยนต์ (base_footprint)
            transform = self.tf_buffer.lookup_transform(
                'pole_link', 'base_footprint', rclpy.time.Time())

            # คำนวณตำแหน่งหุ่นยนต์เทียบกับเสา
            x = transform.transform.translation.x
            y = transform.transform.translation.y
            distance = math.sqrt(x**2 + y**2)
            angle = math.atan2(y, x)  # มุมระหว่างเสากับหุ่นยนต์

            self.get_logger().info(f"Distance to pole: {distance:.2f} meters, Angle: {math.degrees(angle):.2f} degrees")

        except tf2_ros.LookupException as e:
            self.get_logger().warn(f"TF Lookup failed: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = PolePositionEstimator()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
