#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import tf2_ros
import tf2_geometry_msgs

class ArucoPoseTransformer(Node):
    def __init__(self):
        super().__init__('aruco_pose_transformer')
        self.tf_buffer = tf2_ros.Buffer()
        self.tf_listener = tf2_ros.TransformListener(self.tf_buffer, self)
        
        self.pose_sub = self.create_subscription(
            PoseStamped, '/aruco_marker_pose', self.pose_callback, 10)
        self.pose_pub = self.create_publisher(
            PoseStamped, '/aruco_marker_pose_base', 10)

    def pose_callback(self, msg):
        try:
            transform = self.tf_buffer.lookup_transform(
                'base_footprint', msg.header.frame_id, rclpy.time.Time())

            transformed_pose = tf2_geometry_msgs.do_transform_pose(msg, transform)
            transformed_pose.header.frame_id = 'base_footprint'
            self.pose_pub.publish(transformed_pose)
        
        except tf2_ros.LookupException as e:
            self.get_logger().warn(f"TF Lookup failed: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = ArucoPoseTransformer()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
