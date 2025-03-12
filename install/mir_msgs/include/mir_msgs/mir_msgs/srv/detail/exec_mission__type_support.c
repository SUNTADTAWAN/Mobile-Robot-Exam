// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from mir_msgs:srv/ExecMission.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "mir_msgs/srv/detail/exec_mission__rosidl_typesupport_introspection_c.h"
#include "mir_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "mir_msgs/srv/detail/exec_mission__functions.h"
#include "mir_msgs/srv/detail/exec_mission__struct.h"


// Include directives for member types
// Member `mission_name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mir_msgs__srv__ExecMission_Request__init(message_memory);
}

void mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_fini_function(void * message_memory)
{
  mir_msgs__srv__ExecMission_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_message_member_array[1] = {
  {
    "mission_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mir_msgs__srv__ExecMission_Request, mission_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_message_members = {
  "mir_msgs__srv",  // message namespace
  "ExecMission_Request",  // message name
  1,  // number of fields
  sizeof(mir_msgs__srv__ExecMission_Request),
  mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_message_member_array,  // message members
  mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_message_type_support_handle = {
  0,
  &mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mir_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mir_msgs, srv, ExecMission_Request)() {
  if (!mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_message_type_support_handle.typesupport_identifier) {
    mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mir_msgs__srv__ExecMission_Request__rosidl_typesupport_introspection_c__ExecMission_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "mir_msgs/srv/detail/exec_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "mir_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "mir_msgs/srv/detail/exec_mission__functions.h"
// already included above
// #include "mir_msgs/srv/detail/exec_mission__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  mir_msgs__srv__ExecMission_Response__init(message_memory);
}

void mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_fini_function(void * message_memory)
{
  mir_msgs__srv__ExecMission_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_message_member_array[2] = {
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mir_msgs__srv__ExecMission_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(mir_msgs__srv__ExecMission_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_message_members = {
  "mir_msgs__srv",  // message namespace
  "ExecMission_Response",  // message name
  2,  // number of fields
  sizeof(mir_msgs__srv__ExecMission_Response),
  mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_message_member_array,  // message members
  mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_message_type_support_handle = {
  0,
  &mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mir_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mir_msgs, srv, ExecMission_Response)() {
  if (!mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_message_type_support_handle.typesupport_identifier) {
    mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &mir_msgs__srv__ExecMission_Response__rosidl_typesupport_introspection_c__ExecMission_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "mir_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "mir_msgs/srv/detail/exec_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers mir_msgs__srv__detail__exec_mission__rosidl_typesupport_introspection_c__ExecMission_service_members = {
  "mir_msgs__srv",  // service namespace
  "ExecMission",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // mir_msgs__srv__detail__exec_mission__rosidl_typesupport_introspection_c__ExecMission_Request_message_type_support_handle,
  NULL  // response message
  // mir_msgs__srv__detail__exec_mission__rosidl_typesupport_introspection_c__ExecMission_Response_message_type_support_handle
};

static rosidl_service_type_support_t mir_msgs__srv__detail__exec_mission__rosidl_typesupport_introspection_c__ExecMission_service_type_support_handle = {
  0,
  &mir_msgs__srv__detail__exec_mission__rosidl_typesupport_introspection_c__ExecMission_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mir_msgs, srv, ExecMission_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mir_msgs, srv, ExecMission_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_mir_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mir_msgs, srv, ExecMission)() {
  if (!mir_msgs__srv__detail__exec_mission__rosidl_typesupport_introspection_c__ExecMission_service_type_support_handle.typesupport_identifier) {
    mir_msgs__srv__detail__exec_mission__rosidl_typesupport_introspection_c__ExecMission_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)mir_msgs__srv__detail__exec_mission__rosidl_typesupport_introspection_c__ExecMission_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mir_msgs, srv, ExecMission_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, mir_msgs, srv, ExecMission_Response)()->data;
  }

  return &mir_msgs__srv__detail__exec_mission__rosidl_typesupport_introspection_c__ExecMission_service_type_support_handle;
}
