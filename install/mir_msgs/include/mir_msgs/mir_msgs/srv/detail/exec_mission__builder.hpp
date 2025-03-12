// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mir_msgs:srv/ExecMission.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__SRV__DETAIL__EXEC_MISSION__BUILDER_HPP_
#define MIR_MSGS__SRV__DETAIL__EXEC_MISSION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mir_msgs/srv/detail/exec_mission__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mir_msgs
{

namespace srv
{

namespace builder
{

class Init_ExecMission_Request_mission_name
{
public:
  Init_ExecMission_Request_mission_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::mir_msgs::srv::ExecMission_Request mission_name(::mir_msgs::srv::ExecMission_Request::_mission_name_type arg)
  {
    msg_.mission_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mir_msgs::srv::ExecMission_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mir_msgs::srv::ExecMission_Request>()
{
  return mir_msgs::srv::builder::Init_ExecMission_Request_mission_name();
}

}  // namespace mir_msgs


namespace mir_msgs
{

namespace srv
{

namespace builder
{

class Init_ExecMission_Response_success
{
public:
  explicit Init_ExecMission_Response_success(::mir_msgs::srv::ExecMission_Response & msg)
  : msg_(msg)
  {}
  ::mir_msgs::srv::ExecMission_Response success(::mir_msgs::srv::ExecMission_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mir_msgs::srv::ExecMission_Response msg_;
};

class Init_ExecMission_Response_message
{
public:
  Init_ExecMission_Response_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ExecMission_Response_success message(::mir_msgs::srv::ExecMission_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_ExecMission_Response_success(msg_);
  }

private:
  ::mir_msgs::srv::ExecMission_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::mir_msgs::srv::ExecMission_Response>()
{
  return mir_msgs::srv::builder::Init_ExecMission_Response_message();
}

}  // namespace mir_msgs

#endif  // MIR_MSGS__SRV__DETAIL__EXEC_MISSION__BUILDER_HPP_
