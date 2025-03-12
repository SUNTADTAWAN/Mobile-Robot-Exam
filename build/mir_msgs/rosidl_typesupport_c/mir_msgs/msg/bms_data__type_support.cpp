// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from mir_msgs:msg/BMSData.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "mir_msgs/msg/detail/bms_data__struct.h"
#include "mir_msgs/msg/detail/bms_data__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace mir_msgs
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _BMSData_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _BMSData_type_support_ids_t;

static const _BMSData_type_support_ids_t _BMSData_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _BMSData_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _BMSData_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _BMSData_type_support_symbol_names_t _BMSData_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, mir_msgs, msg, BMSData)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mir_msgs, msg, BMSData)),
  }
};

typedef struct _BMSData_type_support_data_t
{
  void * data[2];
} _BMSData_type_support_data_t;

static _BMSData_type_support_data_t _BMSData_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _BMSData_message_typesupport_map = {
  2,
  "mir_msgs",
  &_BMSData_message_typesupport_ids.typesupport_identifier[0],
  &_BMSData_message_typesupport_symbol_names.symbol_name[0],
  &_BMSData_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t BMSData_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_BMSData_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace mir_msgs

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, mir_msgs, msg, BMSData)() {
  return &::mir_msgs::msg::rosidl_typesupport_c::BMSData_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
