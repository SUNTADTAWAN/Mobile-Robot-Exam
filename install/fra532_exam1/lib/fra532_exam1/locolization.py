#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from gazebo_msgs.msg import ModelStates
from geometry_msgs.msg import PoseStamped
import numpy as np
import tf_transformations


class PoleRelativePose(Node):
    def __init__(self):
        super().__init__('pole_relative_pose')

        # Subscribe to Gazebo model states
        self.model_states_sub = self.create_subscription(
            ModelStates, '/gazebo/model_states', self.model_states_callback, 10
        )

        # Publisher for pole relative pose
        self.pose_pub = self.create_publisher(PoseStamped, '/pole_pose_relative', 10)

        self.pole_pose = None
        self.robot_pose = None

        self.get_logger().info("Pole Relative Pose Node Initialized.")

    def model_states_callback(self, msg):
        try:
            # Get indices of the pole and the robot
            if 'pole' in msg.name and 'mir_robot' in msg.name:
                pole_index = msg.name.index('pole')
                robot_index = msg.name.index('mir_robot')

                # Get their absolute poses
                self.pole_pose = msg.pose[pole_index]
                self.robot_pose = msg.pose[robot_index]

                # Compute relative pose
                self.compute_relative_pose()
            else:
                self.get_logger().warn("Pole or MiR Robot not found in model states.")

        except Exception as e:
            self.get_logger().error(f"Error in model_states_callback: {str(e)}")

    def compute_relative_pose(self):
        """ Compute pole's pose relative to MiR robot. """
        if self.pole_pose is None or self.robot_pose is None:
            return

        # Convert poses to numpy arrays
        pole_pos = np.array([self.pole_pose.position.x, self.pole_pose.position.y, self.pole_pose.position.z])
        robot_pos = np.array([self.robot_pose.position.x, self.robot_pose.position.y, self.robot_pose.position.z])

        pole_quat = [
            self.pole_pose.orientation.x,
            self.pole_pose.orientation.y,
            self.pole_pose.orientation.z,
            self.pole_pose.orientation.w,
        ]
        robot_quat = [
            self.robot_pose.orientation.x,
            self.robot_pose.orientation.y,
            self.robot_pose.orientation.z,
            self.robot_pose.orientation.w,
        ]

        # Convert quaternions to transformation matrices
        pole_tf = tf_transformations.quaternion_matrix(pole_quat)
        pole_tf[:3, 3] = pole_pos

        robot_tf = tf_transformations.quaternion_matrix(robot_quat)
        robot_tf[:3, 3] = robot_pos

        # Compute relative transformation
        relative_tf = np.linalg.inv(robot_tf) @ pole_tf

        # Extract position
        relative_pos = relative_tf[:3, 3]

        # Extract rotation as quaternion
        relative_quat = tf_transformations.quaternion_from_matrix(relative_tf)

        # Publish the relative pose
        pose_msg = PoseStamped()
        pose_msg.header.stamp = self.get_clock().now().to_msg()
        pose_msg.header.frame_id = "mir_robot"

        pose_msg.pose.position.x = relative_pos[0]
        pose_msg.pose.position.y = relative_pos[1]
        pose_msg.pose.position.z = relative_pos[2]

        pose_msg.pose.orientation.x = relative_quat[0]
        pose_msg.pose.orientation.y = relative_quat[1]
        pose_msg.pose.orientation.z = relative_quat[2]
        pose_msg.pose.orientation.w = relative_quat[3]

        self.pose_pub.publish(pose_msg)

        self.get_logger().info(f"Pole relative position: x={relative_pos[0]:.2f}, y={relative_pos[1]:.2f}, z={relative_pos[2]:.2f}")


def main(args=None):
    rclpy.init(args=args)
    node = PoleRelativePose()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
