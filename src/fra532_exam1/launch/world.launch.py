#!/usr/bin/python3

import os
import xacro
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription, DeclareLaunchArgument, LogInfo
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.actions import TimerAction


def generate_launch_description():
    # Path to the world file
    world_file_name = 'pole.world'
    try:
        world_path = os.path.join(get_package_share_directory('fra532_exam1'), 'worlds', world_file_name)
    except Exception as e:
        return LaunchDescription([
            LogInfo(msg=f"Error: Could not find fra532_exam1 package. {str(e)}")
        ])

    # Process Xacro file
    try:
        xacro_file = os.path.join(get_package_share_directory('mir_description'), 'urdf', 'mir.urdf.xacro')
        if not os.path.exists(xacro_file):
            raise FileNotFoundError(f"Xacro file not found: {xacro_file}")
        
        robot_description_config = xacro.process_file(xacro_file)
        robot_description = {'robot_description': robot_description_config.toxml()}

    except Exception as e:
        return LaunchDescription([
            LogInfo(msg=f"Error: {str(e)}")
        ])

    # Declare world argument
    world_arg = DeclareLaunchArgument(
        'world', default_value=world_path, description='Gazebo world file')

    # Declare spawn position arguments
    spawn_x_arg = DeclareLaunchArgument('spawn_x', default_value='1.0', description='X position of the robot')
    spawn_y_arg = DeclareLaunchArgument('spawn_y', default_value='1.0', description='Y position of the robot')
    spawn_z_arg = DeclareLaunchArgument('spawn_z', default_value='0.1', description='Z position of the robot')
    spawn_yaw_arg = DeclareLaunchArgument('spawn_yaw', default_value='0.0', description='Yaw rotation (radians)')

    # Include Gazebo server launch
    gazebo_server = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gzserver.launch.py')
        ),
        launch_arguments={'world': LaunchConfiguration('world')}.items()
    )

    # Include Gazebo GUI launch
    gazebo_client = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(get_package_share_directory('gazebo_ros'), 'launch', 'gzclient.launch.py')
        )
    )

    # Robot State Publisher
    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        output='screen',
        parameters=[robot_description]
    )

    # Spawn MiR robot in Gazebo with custom position
    spawn_robot = TimerAction(
        period=3.0,  # Delay 3 seconds before spawning
        actions=[
            Node(
                package='gazebo_ros',
                executable='spawn_entity.py',
                arguments=[
                    '-entity', 'mir_robot',
                    '-topic', 'robot_description',
                    '-x', LaunchConfiguration('spawn_x'),
                    '-y', LaunchConfiguration('spawn_y'),
                    '-z', LaunchConfiguration('spawn_z'),
                    '-Y', LaunchConfiguration('spawn_yaw'),
                    '-b'
                ],
                namespace='',
                output='screen'
            )
        ]
    )

    # Launch teleoperation node
    launch_teleop = Node(
        package='teleop_twist_keyboard',
        executable='teleop_twist_keyboard',
        namespace='',
        output='screen',
        prefix='xterm -e'
    )

    return LaunchDescription([
        world_arg,
        spawn_x_arg,
        spawn_y_arg,
        spawn_z_arg,
        spawn_yaw_arg,
        gazebo_server,
        gazebo_client,
        robot_state_publisher,
        spawn_robot,
        launch_teleop
    ])
