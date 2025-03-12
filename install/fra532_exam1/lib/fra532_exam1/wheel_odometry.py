#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import TransformStamped
from geometry_msgs.msg import Quaternion
from tf2_ros import TransformBroadcaster
import math

class WheelOdometry(Node):
    def __init__(self):
        super().__init__('wheel_odometry')

        # Parameters
        self.declare_parameter('wheel_separation', 0.5)  # ระยะห่างระหว่างล้อ (เมตร)
        self.declare_parameter('wheel_radius', 0.0625)  # รัศมีล้อ (เมตร)


        self.wheel_separation = self.get_parameter('wheel_separation').value
        self.wheel_radius = self.get_parameter('wheel_radius').value

        # Subscribe to wheel encoder velocities
        self.create_subscription(Odometry, '/wheel_encoder', self.encoder_callback, 10)

        # Publisher for Odometry
        self.odom_pub = self.create_publisher(Odometry, '/odom', 10)

        # TF Broadcaster for odom -> base_footprint
        self.tf_broadcaster = TransformBroadcaster(self)

        # Robot Pose
        self.x = 0.0
        self.y = 0.0
        self.theta = 0.0
        self.last_time = self.get_clock().now()

    def encoder_callback(self, msg):
        current_time = self.get_clock().now()
        dt = (current_time - self.last_time).nanoseconds / 1e9  # Convert to seconds
        self.last_time = current_time

        # Wheel velocities (linear velocity of left and right wheels)
        v_left = msg.twist.twist.linear.x - (msg.twist.twist.angular.z * self.wheel_separation / 2.0)
        v_right = msg.twist.twist.linear.x + (msg.twist.twist.angular.z * self.wheel_separation / 2.0)

        # Compute linear and angular velocity of the robot
        v = (v_right + v_left) / 2.0  # Linear velocity
        w = (v_right - v_left) / self.wheel_separation  # Angular velocity

        # Update robot pose using kinematics
        delta_x = v * math.cos(self.theta) * dt
        delta_y = v * math.sin(self.theta) * dt
        delta_theta = w * dt

        self.x += delta_x
        self.y += delta_y
        self.theta += delta_theta

        # Publish Odometry
        odom_msg = Odometry()
        odom_msg.header.stamp = self.get_clock().now().to_msg()
        odom_msg.header.frame_id = 'odom'
        odom_msg.child_frame_id = 'base_footprint'
        odom_msg.pose.pose.position.x = self.x
        odom_msg.pose.pose.position.y = self.y
        odom_msg.pose.pose.orientation = self.quaternion_from_euler(0, 0, self.theta)
        odom_msg.twist.twist.linear.x = v
        odom_msg.twist.twist.angular.z = w
        self.odom_pub.publish(odom_msg)

        # Publish TF transform
        self.broadcast_tf()

    def quaternion_from_euler(self, roll, pitch, yaw):
        """ Convert Euler angles to Quaternion """
        q = Quaternion()
        cy = math.cos(yaw * 0.5)
        sy = math.sin(yaw * 0.5)
        cp = math.cos(pitch * 0.5)
        sp = math.sin(pitch * 0.5)
        cr = math.cos(roll * 0.5)
        sr = math.sin(roll * 0.5)

        q.w = cr * cp * cy + sr * sp * sy
        q.x = sr * cp * cy - cr * sp * sy
        q.y = cr * sp * cy + sr * cp * sy
        q.z = cr * cp * sy - sr * sp * cy
        return q

    def broadcast_tf(self):
        """ Broadcast odom -> base_footprint transform """
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'base_footprint'
        t.transform.translation.x = self.x
        t.transform.translation.y = self.y
        t.transform.translation.z = 0.0
        t.transform.rotation = self.quaternion_from_euler(0, 0, self.theta)

        self.tf_broadcaster.sendTransform(t)

def main(args=None):
    rclpy.init(args=args)
    node = WheelOdometry()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
