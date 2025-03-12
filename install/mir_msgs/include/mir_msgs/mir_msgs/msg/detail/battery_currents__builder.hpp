// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mir_msgs:msg/BatteryCurrents.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__BUILDER_HPP_
#define MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mir_msgs/msg/detail/battery_currents__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mir_msgs
{

namespace msg
{

namespace builder
{

class Init_BatteryCurrents_battery2_current
{
public:
  explicit Init_BatteryCurrents_battery2_current(::mir_msgs::msg::BatteryCurrents & msg)
  : msg_(msg)
  {}
  ::mir_msgs::msg::BatteryCurrents battery2_current(::mir_msgs::msg::BatteryCurrents::_battery2_current_type arg)
  {
    msg_.battery2_current = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mir_msgs::msg::BatteryCurrents msg_;
};

class Init_BatteryCurrents_battery1_current
{
public:
  Init_BatteryCurrents_battery1_current()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BatteryCurrents_battery2_current battery1_current(::mir_msgs::msg::BatteryCurrents::_battery1_current_type arg)
  {
    msg_.battery1_current = std::move(arg);
    return Init_BatteryCurrents_battery2_current(msg_);
  }

private:
  ::mir_msgs::msg::BatteryCurrents msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mir_msgs::msg::BatteryCurrents>()
{
  return mir_msgs::msg::builder::Init_BatteryCurrents_battery1_current();
}

}  // namespace mir_msgs

#endif  // MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__BUILDER_HPP_
