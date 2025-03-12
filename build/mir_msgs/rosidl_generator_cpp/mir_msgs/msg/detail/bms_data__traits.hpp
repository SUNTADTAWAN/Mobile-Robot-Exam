// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mir_msgs:msg/BMSData.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__MSG__DETAIL__BMS_DATA__TRAITS_HPP_
#define MIR_MSGS__MSG__DETAIL__BMS_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mir_msgs/msg/detail/bms_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mir_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BMSData & msg,
  std::ostream & out)
{
  out << "{";
  // member: pack_voltage
  {
    out << "pack_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.pack_voltage, out);
    out << ", ";
  }

  // member: charge_current
  {
    out << "charge_current: ";
    rosidl_generator_traits::value_to_yaml(msg.charge_current, out);
    out << ", ";
  }

  // member: discharge_current
  {
    out << "discharge_current: ";
    rosidl_generator_traits::value_to_yaml(msg.discharge_current, out);
    out << ", ";
  }

  // member: state_of_charge
  {
    out << "state_of_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.state_of_charge, out);
    out << ", ";
  }

  // member: remaining_time_to_full_charge
  {
    out << "remaining_time_to_full_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_time_to_full_charge, out);
    out << ", ";
  }

  // member: remaining_capacity
  {
    out << "remaining_capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_capacity, out);
    out << ", ";
  }

  // member: state_of_health
  {
    out << "state_of_health: ";
    rosidl_generator_traits::value_to_yaml(msg.state_of_health, out);
    out << ", ";
  }

  // member: status_flags
  {
    out << "status_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.status_flags, out);
    out << ", ";
  }

  // member: temperature
  {
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << ", ";
  }

  // member: cell_voltage
  {
    if (msg.cell_voltage.size() == 0) {
      out << "cell_voltage: []";
    } else {
      out << "cell_voltage: [";
      size_t pending_items = msg.cell_voltage.size();
      for (auto item : msg.cell_voltage) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: last_battery_msg_time
  {
    out << "last_battery_msg_time: ";
    rosidl_generator_traits::value_to_yaml(msg.last_battery_msg_time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BMSData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pack_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pack_voltage: ";
    rosidl_generator_traits::value_to_yaml(msg.pack_voltage, out);
    out << "\n";
  }

  // member: charge_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charge_current: ";
    rosidl_generator_traits::value_to_yaml(msg.charge_current, out);
    out << "\n";
  }

  // member: discharge_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "discharge_current: ";
    rosidl_generator_traits::value_to_yaml(msg.discharge_current, out);
    out << "\n";
  }

  // member: state_of_charge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_of_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.state_of_charge, out);
    out << "\n";
  }

  // member: remaining_time_to_full_charge
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remaining_time_to_full_charge: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_time_to_full_charge, out);
    out << "\n";
  }

  // member: remaining_capacity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "remaining_capacity: ";
    rosidl_generator_traits::value_to_yaml(msg.remaining_capacity, out);
    out << "\n";
  }

  // member: state_of_health
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state_of_health: ";
    rosidl_generator_traits::value_to_yaml(msg.state_of_health, out);
    out << "\n";
  }

  // member: status_flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_flags: ";
    rosidl_generator_traits::value_to_yaml(msg.status_flags, out);
    out << "\n";
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature, out);
    out << "\n";
  }

  // member: cell_voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.cell_voltage.size() == 0) {
      out << "cell_voltage: []\n";
    } else {
      out << "cell_voltage:\n";
      for (auto item : msg.cell_voltage) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: last_battery_msg_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_battery_msg_time: ";
    rosidl_generator_traits::value_to_yaml(msg.last_battery_msg_time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BMSData & msg, bool use_flow_style = false)
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
  const mir_msgs::msg::BMSData & msg,
  std::ostream & out, size_t indentation = 0)
{
  mir_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mir_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const mir_msgs::msg::BMSData & msg)
{
  return mir_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<mir_msgs::msg::BMSData>()
{
  return "mir_msgs::msg::BMSData";
}

template<>
inline const char * name<mir_msgs::msg::BMSData>()
{
  return "mir_msgs/msg/BMSData";
}

template<>
struct has_fixed_size<mir_msgs::msg::BMSData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mir_msgs::msg::BMSData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mir_msgs::msg::BMSData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIR_MSGS__MSG__DETAIL__BMS_DATA__TRAITS_HPP_
