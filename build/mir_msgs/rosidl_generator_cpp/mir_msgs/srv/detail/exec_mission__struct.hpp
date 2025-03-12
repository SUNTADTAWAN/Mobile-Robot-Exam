// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from mir_msgs:srv/ExecMission.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__SRV__DETAIL__EXEC_MISSION__STRUCT_HPP_
#define MIR_MSGS__SRV__DETAIL__EXEC_MISSION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__mir_msgs__srv__ExecMission_Request __attribute__((deprecated))
#else
# define DEPRECATED__mir_msgs__srv__ExecMission_Request __declspec(deprecated)
#endif

namespace mir_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExecMission_Request_
{
  using Type = ExecMission_Request_<ContainerAllocator>;

  explicit ExecMission_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mission_name = "";
    }
  }

  explicit ExecMission_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : mission_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mission_name = "";
    }
  }

  // field types and members
  using _mission_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mission_name_type mission_name;

  // setters for named parameter idiom
  Type & set__mission_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mission_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mir_msgs::srv::ExecMission_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const mir_msgs::srv::ExecMission_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mir_msgs::srv::ExecMission_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mir_msgs::srv::ExecMission_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mir_msgs::srv::ExecMission_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mir_msgs::srv::ExecMission_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mir_msgs::srv::ExecMission_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mir_msgs::srv::ExecMission_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mir_msgs::srv::ExecMission_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mir_msgs::srv::ExecMission_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mir_msgs__srv__ExecMission_Request
    std::shared_ptr<mir_msgs::srv::ExecMission_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mir_msgs__srv__ExecMission_Request
    std::shared_ptr<mir_msgs::srv::ExecMission_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecMission_Request_ & other) const
  {
    if (this->mission_name != other.mission_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecMission_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecMission_Request_

// alias to use template instance with default allocator
using ExecMission_Request =
  mir_msgs::srv::ExecMission_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mir_msgs


#ifndef _WIN32
# define DEPRECATED__mir_msgs__srv__ExecMission_Response __attribute__((deprecated))
#else
# define DEPRECATED__mir_msgs__srv__ExecMission_Response __declspec(deprecated)
#endif

namespace mir_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ExecMission_Response_
{
  using Type = ExecMission_Response_<ContainerAllocator>;

  explicit ExecMission_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->success = false;
    }
  }

  explicit ExecMission_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
      this->success = false;
    }
  }

  // field types and members
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    mir_msgs::srv::ExecMission_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const mir_msgs::srv::ExecMission_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<mir_msgs::srv::ExecMission_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<mir_msgs::srv::ExecMission_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      mir_msgs::srv::ExecMission_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<mir_msgs::srv::ExecMission_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      mir_msgs::srv::ExecMission_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<mir_msgs::srv::ExecMission_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<mir_msgs::srv::ExecMission_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<mir_msgs::srv::ExecMission_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__mir_msgs__srv__ExecMission_Response
    std::shared_ptr<mir_msgs::srv::ExecMission_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__mir_msgs__srv__ExecMission_Response
    std::shared_ptr<mir_msgs::srv::ExecMission_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ExecMission_Response_ & other) const
  {
    if (this->message != other.message) {
      return false;
    }
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ExecMission_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ExecMission_Response_

// alias to use template instance with default allocator
using ExecMission_Response =
  mir_msgs::srv::ExecMission_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace mir_msgs

namespace mir_msgs
{

namespace srv
{

struct ExecMission
{
  using Request = mir_msgs::srv::ExecMission_Request;
  using Response = mir_msgs::srv::ExecMission_Response;
};

}  // namespace srv

}  // namespace mir_msgs

#endif  // MIR_MSGS__SRV__DETAIL__EXEC_MISSION__STRUCT_HPP_
