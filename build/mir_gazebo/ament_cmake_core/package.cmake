set(_AMENT_PACKAGE_NAME "mir_gazebo")
set(mir_gazebo_VERSION "1.1.3")
set(mir_gazebo_MAINTAINER "Martin Günther <martin.guenther@dfki.de>")
set(mir_gazebo_BUILD_DEPENDS "gazebo" "gazebo_ros" "rviz2" "ira_laser_tools" "teleop_twist_keyboard" "xterm" "xacro" "mir_description" "gazebo_ros_pkgs" "robot_localization")
set(mir_gazebo_BUILDTOOL_DEPENDS "ament_cmake")
set(mir_gazebo_BUILD_EXPORT_DEPENDS "gazebo" "gazebo_ros" "rviz2" "ira_laser_tools" "teleop_twist_keyboard" "xterm" "xacro" "mir_description" "gazebo_ros_pkgs" "robot_localization")
set(mir_gazebo_BUILDTOOL_EXPORT_DEPENDS )
set(mir_gazebo_EXEC_DEPENDS "gazebo" "gazebo_ros" "rviz2" "ira_laser_tools" "teleop_twist_keyboard" "xterm" "xacro" "mir_description" "gazebo_ros_pkgs" "robot_localization")
set(mir_gazebo_TEST_DEPENDS "ament_lint_auto" "ament_lint_common")
set(mir_gazebo_GROUP_DEPENDS )
set(mir_gazebo_MEMBER_OF_GROUPS )
set(mir_gazebo_DEPRECATED "")
set(mir_gazebo_EXPORT_TAGS)
list(APPEND mir_gazebo_EXPORT_TAGS "<build_type>ament_cmake</build_type>")
list(APPEND mir_gazebo_EXPORT_TAGS "<gazebo_ros gazebo_model_path=\"worlds/include\"/>")
