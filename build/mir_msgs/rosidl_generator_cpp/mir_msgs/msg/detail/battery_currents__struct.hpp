// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mir_msgs:msg/BatteryCurrents.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__STRUCT_HPP_
#define MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mir_msgs__msg__BatteryCurrents __attribute__((deprecated))
#else
# define DEPRECATED__mir_msgs__msg__BatteryCurrents __declspec(deprecated)
#endif

namespace mir_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BatteryCurrents_
{
  using Type = BatteryCurrents_<ContainerAllocator>;

  explicit BatteryCurrents_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery1_current = 0.0;
      this->battery2_current = 0.0;
    }
  }

  explicit BatteryCurrents_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery1_current = 0.0;
      this->battery2_current = 0.0;
    }
  }

  // field types and members
  using _battery1_current_type =
    double;
  _battery1_current_type battery1_current;
  using _battery2_current_type =
    double;
  _battery2_current_type battery2_current;

  // setters for named parameter idiom
  Type & set__battery1_current(
    const double & _arg)
  {
    this->battery1_current = _arg;
    return *this;
  }
  Type & set__battery2_current(
    const double & _arg)
  {
    this->battery2_current = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mir_msgs::msg::BatteryCurrents_<ContainerAllocator> *;
  using ConstRawPtr =
    const mir_msgs::msg::BatteryCurrents_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mir_msgs::msg::BatteryCurrents_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mir_msgs::msg::BatteryCurrents_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mir_msgs::msg::BatteryCurrents_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mir_msgs::msg::BatteryCurrents_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mir_msgs::msg::BatteryCurrents_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mir_msgs::msg::BatteryCurrents_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mir_msgs::msg::BatteryCurrents_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mir_msgs::msg::BatteryCurrents_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mir_msgs__msg__BatteryCurrents
    std::shared_ptr<mir_msgs::msg::BatteryCurrents_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mir_msgs__msg__BatteryCurrents
    std::shared_ptr<mir_msgs::msg::BatteryCurrents_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BatteryCurrents_ & other) const
  {
    if (this->battery1_current != other.battery1_current) {
      return false;
    }
    if (this->battery2_current != other.battery2_current) {
      return false;
    }
    return true;
  }
  bool operator!=(const BatteryCurrents_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BatteryCurrents_

// alias to use template instance with default allocator
using BatteryCurrents =
  mir_msgs::msg::BatteryCurrents_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace mir_msgs

#endif  // MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__STRUCT_HPP_
