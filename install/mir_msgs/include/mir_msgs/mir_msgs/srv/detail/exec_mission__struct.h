// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mir_msgs:srv/ExecMission.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__SRV__DETAIL__EXEC_MISSION__STRUCT_H_
#define MIR_MSGS__SRV__DETAIL__EXEC_MISSION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'mission_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ExecMission in the package mir_msgs.
typedef struct mir_msgs__srv__ExecMission_Request
{
  rosidl_runtime_c__String mission_name;
} mir_msgs__srv__ExecMission_Request;

// Struct for a sequence of mir_msgs__srv__ExecMission_Request.
typedef struct mir_msgs__srv__ExecMission_Request__Sequence
{
  mir_msgs__srv__ExecMission_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mir_msgs__srv__ExecMission_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ExecMission in the package mir_msgs.
typedef struct mir_msgs__srv__ExecMission_Response
{
  rosidl_runtime_c__String message;
  bool success;
} mir_msgs__srv__ExecMission_Response;

// Struct for a sequence of mir_msgs__srv__ExecMission_Response.
typedef struct mir_msgs__srv__ExecMission_Response__Sequence
{
  mir_msgs__srv__ExecMission_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mir_msgs__srv__ExecMission_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIR_MSGS__SRV__DETAIL__EXEC_MISSION__STRUCT_H_
