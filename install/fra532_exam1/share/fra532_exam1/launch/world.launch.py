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

        # Debug: Print robot description to check if it's valid
        print("========== ROBOT DESCRIPTION ==========")
        print(robot_description['robot_description'])
        print("=======================================")

    except Exception as e:
        return LaunchDescription([
            LogInfo(msg=f"Error: {str(e)}")
        ])

    # Declare world argument
    world_arg = DeclareLaunchArgument(
        'world', default_value=world_path, description='Gazebo world file')

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

    # Spawn MiR robot in Gazebo
    spawn_robot = TimerAction(
    period=3.0,  # Delay 3 seconds before spawning
    actions=[
        Node(
            package='gazebo_ros',
            executable='spawn_entity.py',
            arguments=['-entity', 'mir_robot',
                       '-topic', 'robot_description',
                       '-b'],
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
        prefix='xterm -e')


    return LaunchDescription([
        world_arg,
        gazebo_server,
        gazebo_client,
        robot_state_publisher,
        spawn_robot,
        launch_teleop
    ])
