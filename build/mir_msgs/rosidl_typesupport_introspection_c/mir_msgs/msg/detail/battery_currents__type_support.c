// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mir_msgs:msg/BatteryCurrents.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mir_msgs/msg/detail/battery_currents__rosidl_typesupport_introspection_c.h"
#include "mir_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mir_msgs/msg/detail/battery_currents__functions.h"
#include "mir_msgs/msg/detail/battery_currents__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mir_msgs__msg__BatteryCurrents__init(message_memory);
}

void mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_fini_function(void * message_memory)
{
  mir_msgs__msg__BatteryCurrents__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_message_member_array[2] = {
  {
    "battery1_current",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mir_msgs__msg__BatteryCurrents, battery1_current),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "battery2_current",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mir_msgs__msg__BatteryCurrents, battery2_current),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_message_members = {
  "mir_msgs__msg",  // message namespace
  "BatteryCurrents",  // message name
  2,  // number of fields
  sizeof(mir_msgs__msg__BatteryCurrents),
  mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_message_member_array,  // message members
  mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_init_function,  // function to initialize message memory (memory has to be allocated)
  mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_message_type_support_handle = {
  0,
  &mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mir_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mir_msgs, msg, BatteryCurrents)() {
  if (!mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_message_type_support_handle.typesupport_identifier) {
    mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mir_msgs__msg__BatteryCurrents__rosidl_typesupport_introspection_c__BatteryCurrents_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
