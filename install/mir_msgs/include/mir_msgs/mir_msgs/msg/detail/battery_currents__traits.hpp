// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mir_msgs:msg/BatteryCurrents.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__TRAITS_HPP_
#define MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mir_msgs/msg/detail/battery_currents__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mir_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BatteryCurrents & msg,
  std::ostream & out)
{
  out << "{";
  // member: battery1_current
  {
    out << "battery1_current: ";
    rosidl_generator_traits::value_to_yaml(msg.battery1_current, out);
    out << ", ";
  }

  // member: battery2_current
  {
    out << "battery2_current: ";
    rosidl_generator_traits::value_to_yaml(msg.battery2_current, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BatteryCurrents & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: battery1_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery1_current: ";
    rosidl_generator_traits::value_to_yaml(msg.battery1_current, out);
    out << "\n";
  }

  // member: battery2_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery2_current: ";
    rosidl_generator_traits::value_to_yaml(msg.battery2_current, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BatteryCurrents & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace mir_msgs

namespace rosidl_generator_traits
{

[[deprecated("use mir_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mir_msgs::msg::BatteryCurrents & msg,
  std::ostream & out, size_t indentation = 0)
{
  mir_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mir_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const mir_msgs::msg::BatteryCurrents & msg)
{
  return mir_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mir_msgs::msg::BatteryCurrents>()
{
  return "mir_msgs::msg::BatteryCurrents";
}

template<>
inline const char * name<mir_msgs::msg::BatteryCurrents>()
{
  return "mir_msgs/msg/BatteryCurrents";
}

template<>
struct has_fixed_size<mir_msgs::msg::BatteryCurrents>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<mir_msgs::msg::BatteryCurrents>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<mir_msgs::msg::BatteryCurrents>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__TRAITS_HPP_
