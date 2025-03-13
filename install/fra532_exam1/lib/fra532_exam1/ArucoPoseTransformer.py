#!/usr/bin/python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped, Pose
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
            source_frame = msg.header.frame_id
            self.get_logger().info(f"Transforming from {source_frame} to base_footprint")

            if not source_frame:
                self.get_logger().error("Error: Received empty frame_id")
                return

            # ตรวจสอบว่า msg.pose มีค่าหรือไม่
            if not hasattr(msg, "pose") or not hasattr(msg.pose, "position"):
                self.get_logger().error("Received PoseStamped message without pose attribute")
                return

            # รอ TF Transform ให้พร้อม
            transform = self.tf_buffer.lookup_transform(
                'base_footprint', source_frame, rclpy.time.Time())

            self.get_logger().info(f"TF Transform: {transform}")

            # Transform only the Pose (ไม่ใช้ PoseStamped)
            transformed_pose = tf2_geometry_msgs.do_transform_pose(msg.pose, transform)

            # Create a new PoseStamped message
            transformed_pose_stamped = PoseStamped()
            transformed_pose_stamped.header.stamp = self.get_clock().now().to_msg()
            transformed_pose_stamped.header.frame_id = 'base_footprint'
            transformed_pose_stamped.pose = transformed_pose  # กำหนดค่า pose ให้ถูกต้อง

            # Publish transformed pose
            self.pose_pub.publish(transformed_pose_stamped)

            self.get_logger().info(f"Transformed Pose: x={transformed_pose_stamped.pose.position.x}, y={transformed_pose_stamped.pose.position.y}, z={transformed_pose_stamped.pose.position.z}")

        except tf2_ros.LookupException as e:
            self.get_logger().warn(f"TF Lookup failed: {e}")
        except AttributeError as e:
            self.get_logger().error(f"Attribute Error: {e}")
        except Exception as e:
            self.get_logger().error(f"Unexpected error: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = ArucoPoseTransformer()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
