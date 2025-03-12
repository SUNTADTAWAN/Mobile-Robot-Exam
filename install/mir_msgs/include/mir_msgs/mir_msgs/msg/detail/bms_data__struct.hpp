// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mir_msgs:msg/BMSData.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__MSG__DETAIL__BMS_DATA__STRUCT_HPP_
#define MIR_MSGS__MSG__DETAIL__BMS_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mir_msgs__msg__BMSData __attribute__((deprecated))
#else
# define DEPRECATED__mir_msgs__msg__BMSData __declspec(deprecated)
#endif

namespace mir_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BMSData_
{
  using Type = BMSData_<ContainerAllocator>;

  explicit BMSData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pack_voltage = 0.0;
      this->charge_current = 0.0;
      this->discharge_current = 0.0;
      this->state_of_charge = 0l;
      this->remaining_time_to_full_charge = 0.0;
      this->remaining_capacity = 0l;
      this->state_of_health = 0l;
      this->status_flags = 0l;
      this->temperature = 0l;
      this->last_battery_msg_time = 0.0;
    }
  }

  explicit BMSData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pack_voltage = 0.0;
      this->charge_current = 0.0;
      this->discharge_current = 0.0;
      this->state_of_charge = 0l;
      this->remaining_time_to_full_charge = 0.0;
      this->remaining_capacity = 0l;
      this->state_of_health = 0l;
      this->status_flags = 0l;
      this->temperature = 0l;
      this->last_battery_msg_time = 0.0;
    }
  }

  // field types and members
  using _pack_voltage_type =
    double;
  _pack_voltage_type pack_voltage;
  using _charge_current_type =
    double;
  _charge_current_type charge_current;
  using _discharge_current_type =
    double;
  _discharge_current_type discharge_current;
  using _state_of_charge_type =
    int32_t;
  _state_of_charge_type state_of_charge;
  using _remaining_time_to_full_charge_type =
    double;
  _remaining_time_to_full_charge_type remaining_time_to_full_charge;
  using _remaining_capacity_type =
    int32_t;
  _remaining_capacity_type remaining_capacity;
  using _state_of_health_type =
    int32_t;
  _state_of_health_type state_of_health;
  using _status_flags_type =
    int32_t;
  _status_flags_type status_flags;
  using _temperature_type =
    int32_t;
  _temperature_type temperature;
  using _cell_voltage_type =
    std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>>;
  _cell_voltage_type cell_voltage;
  using _last_battery_msg_time_type =
    double;
  _last_battery_msg_time_type last_battery_msg_time;

  // setters for named parameter idiom
  Type & set__pack_voltage(
    const double & _arg)
  {
    this->pack_voltage = _arg;
    return *this;
  }
  Type & set__charge_current(
    const double & _arg)
  {
    this->charge_current = _arg;
    return *this;
  }
  Type & set__discharge_current(
    const double & _arg)
  {
    this->discharge_current = _arg;
    return *this;
  }
  Type & set__state_of_charge(
    const int32_t & _arg)
  {
    this->state_of_charge = _arg;
    return *this;
  }
  Type & set__remaining_time_to_full_charge(
    const double & _arg)
  {
    this->remaining_time_to_full_charge = _arg;
    return *this;
  }
  Type & set__remaining_capacity(
    const int32_t & _arg)
  {
    this->remaining_capacity = _arg;
    return *this;
  }
  Type & set__state_of_health(
    const int32_t & _arg)
  {
    this->state_of_health = _arg;
    return *this;
  }
  Type & set__status_flags(
    const int32_t & _arg)
  {
    this->status_flags = _arg;
    return *this;
  }
  Type & set__temperature(
    const int32_t & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__cell_voltage(
    const std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t>> & _arg)
  {
    this->cell_voltage = _arg;
    return *this;
  }
  Type & set__last_battery_msg_time(
    const double & _arg)
  {
    this->last_battery_msg_time = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int32_t DISCHARGING =
    1;
  static constexpr int32_t CHARGING =
    2;

  // pointer types
  using RawPtr =
    mir_msgs::msg::BMSData_<ContainerAllocator> *;
  using ConstRawPtr =
    const mir_msgs::msg::BMSData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mir_msgs::msg::BMSData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mir_msgs::msg::BMSData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mir_msgs::msg::BMSData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mir_msgs::msg::BMSData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mir_msgs::msg::BMSData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mir_msgs::msg::BMSData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mir_msgs::msg::BMSData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mir_msgs::msg::BMSData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mir_msgs__msg__BMSData
    std::shared_ptr<mir_msgs::msg::BMSData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mir_msgs__msg__BMSData
    std::shared_ptr<mir_msgs::msg::BMSData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BMSData_ & other) const
  {
    if (this->pack_voltage != other.pack_voltage) {
      return false;
    }
    if (this->charge_current != other.charge_current) {
      return false;
    }
    if (this->discharge_current != other.discharge_current) {
      return false;
    }
    if (this->state_of_charge != other.state_of_charge) {
      return false;
    }
    if (this->remaining_time_to_full_charge != other.remaining_time_to_full_charge) {
      return false;
    }
    if (this->remaining_capacity != other.remaining_capacity) {
      return false;
    }
    if (this->state_of_health != other.state_of_health) {
      return false;
    }
    if (this->status_flags != other.status_flags) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->cell_voltage != other.cell_voltage) {
      return false;
    }
    if (this->last_battery_msg_time != other.last_battery_msg_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const BMSData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BMSData_

// alias to use template instance with default allocator
using BMSData =
  mir_msgs::msg::BMSData_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t BMSData_<ContainerAllocator>::DISCHARGING;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int32_t BMSData_<ContainerAllocator>::CHARGING;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace mir_msgs

#endif  // MIR_MSGS__MSG__DETAIL__BMS_DATA__STRUCT_HPP_
