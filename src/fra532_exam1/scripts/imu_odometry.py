#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Imu
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Quaternion, TransformStamped
from tf2_ros import TransformBroadcaster
import transforms3d
import math

class IMUOdometry(Node):
    def __init__(self):
        super().__init__('imu_odometry')

        # Subscribe to IMU data
        self.imu_sub = self.create_subscription(Imu, '/imu_data/data', self.imu_callback, 10)

        # Publisher for Odometry
        self.odom_pub = self.create_publisher(Odometry, '/odom_imu', 10)

        # TF Broadcaster for odom -> base_footprint
        self.tf_broadcaster = TransformBroadcaster(self)

        # Robot Pose & Velocity
        self.x = 1.0
        self.y = 1.0
        self.theta = 0.0
        self.vx = 0.0
        self.vy = 0.0
        self.wz = 0.0
        self.last_time = self.get_clock().now()

        # Complementary Filter
        self.ALPHA = 0.98

    def imu_callback(self, msg):
        current_time = self.get_clock().now()
        dt = (current_time - self.last_time).nanoseconds / 1e9  # Convert to seconds
        self.last_time = current_time

        # Extract IMU data
        ax = msg.linear_acceleration.x
        ay = msg.linear_acceleration.y
        wz = msg.angular_velocity.z

        # Get orientation directly from IMU
        q = msg.orientation
        _, _, self.theta = transforms3d.euler.quat2euler([q.w, q.x, q.y, q.z])

        # Apply Complementary Filter
        self.vx = self.ALPHA * self.vx + (1 - self.ALPHA) * ax * dt
        self.vy = self.ALPHA * self.vy + (1 - self.ALPHA) * ay * dt
        self.wz = self.ALPHA * self.wz + (1 - self.ALPHA) * wz

        # If acceleration is too low, assume robot is stationary
        if abs(ax) < 0.05 and abs(ay) < 0.05:
            self.vx, self.vy = 0.0, 0.0

        # Integrate velocity to get position
        self.x += self.vx * dt
        self.y += self.vy * dt

        # Publish Odometry
        odom_msg = Odometry()
        odom_msg.header.stamp = self.get_clock().now().to_msg()
        odom_msg.header.frame_id = 'odom'
        odom_msg.child_frame_id = 'base_footprint'
        odom_msg.pose.pose.position.x = self.x
        odom_msg.pose.pose.position.y = self.y
        odom_msg.pose.pose.orientation = self.quaternion_from_euler(0, 0, self.theta)
        odom_msg.twist.twist.linear.x = self.vx
        odom_msg.twist.twist.linear.y = self.vy
        odom_msg.twist.twist.angular.z = self.wz
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
    node = IMUOdometry()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
