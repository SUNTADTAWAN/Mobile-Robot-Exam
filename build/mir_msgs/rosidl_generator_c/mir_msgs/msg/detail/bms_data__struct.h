// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from mir_msgs:msg/BMSData.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__MSG__DETAIL__BMS_DATA__STRUCT_H_
#define MIR_MSGS__MSG__DETAIL__BMS_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'DISCHARGING'.
enum
{
  mir_msgs__msg__BMSData__DISCHARGING = 1l
};

/// Constant 'CHARGING'.
enum
{
  mir_msgs__msg__BMSData__CHARGING = 2l
};

// Include directives for member types
// Member 'cell_voltage'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/BMSData in the package mir_msgs.
typedef struct mir_msgs__msg__BMSData
{
  double pack_voltage;
  double charge_current;
  double discharge_current;
  int32_t state_of_charge;
  double remaining_time_to_full_charge;
  int32_t remaining_capacity;
  int32_t state_of_health;
  int32_t status_flags;
  int32_t temperature;
  /// In Mk2 robots and above the BMS provides data for 8 battery cells. MiR500 robots have BMS for 13 battery cells
  rosidl_runtime_c__uint32__Sequence cell_voltage;
  double last_battery_msg_time;
} mir_msgs__msg__BMSData;

// Struct for a sequence of mir_msgs__msg__BMSData.
typedef struct mir_msgs__msg__BMSData__Sequence
{
  mir_msgs__msg__BMSData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} mir_msgs__msg__BMSData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIR_MSGS__MSG__DETAIL__BMS_DATA__STRUCT_H_
