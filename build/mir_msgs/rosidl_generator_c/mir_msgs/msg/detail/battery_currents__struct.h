// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mir_msgs:msg/BatteryCurrents.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__STRUCT_H_
#define MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BatteryCurrents in the package mir_msgs.
typedef struct mir_msgs__msg__BatteryCurrents
{
  double battery1_current;
  double battery2_current;
} mir_msgs__msg__BatteryCurrents;

// Struct for a sequence of mir_msgs__msg__BatteryCurrents.
typedef struct mir_msgs__msg__BatteryCurrents__Sequence
{
  mir_msgs__msg__BatteryCurrents * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mir_msgs__msg__BatteryCurrents__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIR_MSGS__MSG__DETAIL__BATTERY_CURRENTS__STRUCT_H_
