// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from mir_msgs:srv/ExecMission.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__SRV__DETAIL__EXEC_MISSION__TRAITS_HPP_
#define MIR_MSGS__SRV__DETAIL__EXEC_MISSION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "mir_msgs/srv/detail/exec_mission__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace mir_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExecMission_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mission_name
  {
    out << "mission_name: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecMission_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mission_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mission_name: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecMission_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mir_msgs

namespace rosidl_generator_traits
{

[[deprecated("use mir_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mir_msgs::srv::ExecMission_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  mir_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mir_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const mir_msgs::srv::ExecMission_Request & msg)
{
  return mir_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mir_msgs::srv::ExecMission_Request>()
{
  return "mir_msgs::srv::ExecMission_Request";
}

template<>
inline const char * name<mir_msgs::srv::ExecMission_Request>()
{
  return "mir_msgs/srv/ExecMission_Request";
}

template<>
struct has_fixed_size<mir_msgs::srv::ExecMission_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mir_msgs::srv::ExecMission_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mir_msgs::srv::ExecMission_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace mir_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const ExecMission_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << ", ";
  }

  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ExecMission_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }

  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ExecMission_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace mir_msgs

namespace rosidl_generator_traits
{

[[deprecated("use mir_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const mir_msgs::srv::ExecMission_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  mir_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use mir_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const mir_msgs::srv::ExecMission_Response & msg)
{
  return mir_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<mir_msgs::srv::ExecMission_Response>()
{
  return "mir_msgs::srv::ExecMission_Response";
}

template<>
inline const char * name<mir_msgs::srv::ExecMission_Response>()
{
  return "mir_msgs/srv/ExecMission_Response";
}

template<>
struct has_fixed_size<mir_msgs::srv::ExecMission_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<mir_msgs::srv::ExecMission_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<mir_msgs::srv::ExecMission_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<mir_msgs::srv::ExecMission>()
{
  return "mir_msgs::srv::ExecMission";
}

template<>
inline const char * name<mir_msgs::srv::ExecMission>()
{
  return "mir_msgs/srv/ExecMission";
}

template<>
struct has_fixed_size<mir_msgs::srv::ExecMission>
  : std::integral_constant<
    bool,
    has_fixed_size<mir_msgs::srv::ExecMission_Request>::value &&
    has_fixed_size<mir_msgs::srv::ExecMission_Response>::value
  >
{
};

template<>
struct has_bounded_size<mir_msgs::srv::ExecMission>
  : std::integral_constant<
    bool,
    has_bounded_size<mir_msgs::srv::ExecMission_Request>::value &&
    has_bounded_size<mir_msgs::srv::ExecMission_Response>::value
  >
{
};

template<>
struct is_service<mir_msgs::srv::ExecMission>
  : std::true_type
{
};

template<>
struct is_service_request<mir_msgs::srv::ExecMission_Request>
  : std::true_type
{
};

template<>
struct is_service_response<mir_msgs::srv::ExecMission_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MIR_MSGS__SRV__DETAIL__EXEC_MISSION__TRAITS_HPP_
