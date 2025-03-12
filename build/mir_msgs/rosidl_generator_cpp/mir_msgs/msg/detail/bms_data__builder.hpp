// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from mir_msgs:msg/BMSData.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__MSG__DETAIL__BMS_DATA__BUILDER_HPP_
#define MIR_MSGS__MSG__DETAIL__BMS_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "mir_msgs/msg/detail/bms_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace mir_msgs
{

namespace msg
{

namespace builder
{

class Init_BMSData_last_battery_msg_time
{
public:
  explicit Init_BMSData_last_battery_msg_time(::mir_msgs::msg::BMSData & msg)
  : msg_(msg)
  {}
  ::mir_msgs::msg::BMSData last_battery_msg_time(::mir_msgs::msg::BMSData::_last_battery_msg_time_type arg)
  {
    msg_.last_battery_msg_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

class Init_BMSData_cell_voltage
{
public:
  explicit Init_BMSData_cell_voltage(::mir_msgs::msg::BMSData & msg)
  : msg_(msg)
  {}
  Init_BMSData_last_battery_msg_time cell_voltage(::mir_msgs::msg::BMSData::_cell_voltage_type arg)
  {
    msg_.cell_voltage = std::move(arg);
    return Init_BMSData_last_battery_msg_time(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

class Init_BMSData_temperature
{
public:
  explicit Init_BMSData_temperature(::mir_msgs::msg::BMSData & msg)
  : msg_(msg)
  {}
  Init_BMSData_cell_voltage temperature(::mir_msgs::msg::BMSData::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_BMSData_cell_voltage(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

class Init_BMSData_status_flags
{
public:
  explicit Init_BMSData_status_flags(::mir_msgs::msg::BMSData & msg)
  : msg_(msg)
  {}
  Init_BMSData_temperature status_flags(::mir_msgs::msg::BMSData::_status_flags_type arg)
  {
    msg_.status_flags = std::move(arg);
    return Init_BMSData_temperature(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

class Init_BMSData_state_of_health
{
public:
  explicit Init_BMSData_state_of_health(::mir_msgs::msg::BMSData & msg)
  : msg_(msg)
  {}
  Init_BMSData_status_flags state_of_health(::mir_msgs::msg::BMSData::_state_of_health_type arg)
  {
    msg_.state_of_health = std::move(arg);
    return Init_BMSData_status_flags(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

class Init_BMSData_remaining_capacity
{
public:
  explicit Init_BMSData_remaining_capacity(::mir_msgs::msg::BMSData & msg)
  : msg_(msg)
  {}
  Init_BMSData_state_of_health remaining_capacity(::mir_msgs::msg::BMSData::_remaining_capacity_type arg)
  {
    msg_.remaining_capacity = std::move(arg);
    return Init_BMSData_state_of_health(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

class Init_BMSData_remaining_time_to_full_charge
{
public:
  explicit Init_BMSData_remaining_time_to_full_charge(::mir_msgs::msg::BMSData & msg)
  : msg_(msg)
  {}
  Init_BMSData_remaining_capacity remaining_time_to_full_charge(::mir_msgs::msg::BMSData::_remaining_time_to_full_charge_type arg)
  {
    msg_.remaining_time_to_full_charge = std::move(arg);
    return Init_BMSData_remaining_capacity(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

class Init_BMSData_state_of_charge
{
public:
  explicit Init_BMSData_state_of_charge(::mir_msgs::msg::BMSData & msg)
  : msg_(msg)
  {}
  Init_BMSData_remaining_time_to_full_charge state_of_charge(::mir_msgs::msg::BMSData::_state_of_charge_type arg)
  {
    msg_.state_of_charge = std::move(arg);
    return Init_BMSData_remaining_time_to_full_charge(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

class Init_BMSData_discharge_current
{
public:
  explicit Init_BMSData_discharge_current(::mir_msgs::msg::BMSData & msg)
  : msg_(msg)
  {}
  Init_BMSData_state_of_charge discharge_current(::mir_msgs::msg::BMSData::_discharge_current_type arg)
  {
    msg_.discharge_current = std::move(arg);
    return Init_BMSData_state_of_charge(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

class Init_BMSData_charge_current
{
public:
  explicit Init_BMSData_charge_current(::mir_msgs::msg::BMSData & msg)
  : msg_(msg)
  {}
  Init_BMSData_discharge_current charge_current(::mir_msgs::msg::BMSData::_charge_current_type arg)
  {
    msg_.charge_current = std::move(arg);
    return Init_BMSData_discharge_current(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

class Init_BMSData_pack_voltage
{
public:
  Init_BMSData_pack_voltage()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BMSData_charge_current pack_voltage(::mir_msgs::msg::BMSData::_pack_voltage_type arg)
  {
    msg_.pack_voltage = std::move(arg);
    return Init_BMSData_charge_current(msg_);
  }

private:
  ::mir_msgs::msg::BMSData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::mir_msgs::msg::BMSData>()
{
  return mir_msgs::msg::builder::Init_BMSData_pack_voltage();
}

}  // namespace mir_msgs

#endif  // MIR_MSGS__MSG__DETAIL__BMS_DATA__BUILDER_HPP_
