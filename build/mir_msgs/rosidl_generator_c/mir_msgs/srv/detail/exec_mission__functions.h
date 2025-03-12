// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from mir_msgs:srv/ExecMission.idl
// generated code does not contain a copyright notice

#ifndef MIR_MSGS__SRV__DETAIL__EXEC_MISSION__FUNCTIONS_H_
#define MIR_MSGS__SRV__DETAIL__EXEC_MISSION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "mir_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "mir_msgs/srv/detail/exec_mission__struct.h"

/// Initialize srv/ExecMission message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mir_msgs__srv__ExecMission_Request
 * )) before or use
 * mir_msgs__srv__ExecMission_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Request__init(mir_msgs__srv__ExecMission_Request * msg);

/// Finalize srv/ExecMission message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
void
mir_msgs__srv__ExecMission_Request__fini(mir_msgs__srv__ExecMission_Request * msg);

/// Create srv/ExecMission message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mir_msgs__srv__ExecMission_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
mir_msgs__srv__ExecMission_Request *
mir_msgs__srv__ExecMission_Request__create();

/// Destroy srv/ExecMission message.
/**
 * It calls
 * mir_msgs__srv__ExecMission_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
void
mir_msgs__srv__ExecMission_Request__destroy(mir_msgs__srv__ExecMission_Request * msg);

/// Check for srv/ExecMission message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Request__are_equal(const mir_msgs__srv__ExecMission_Request * lhs, const mir_msgs__srv__ExecMission_Request * rhs);

/// Copy a srv/ExecMission message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Request__copy(
  const mir_msgs__srv__ExecMission_Request * input,
  mir_msgs__srv__ExecMission_Request * output);

/// Initialize array of srv/ExecMission messages.
/**
 * It allocates the memory for the number of elements and calls
 * mir_msgs__srv__ExecMission_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Request__Sequence__init(mir_msgs__srv__ExecMission_Request__Sequence * array, size_t size);

/// Finalize array of srv/ExecMission messages.
/**
 * It calls
 * mir_msgs__srv__ExecMission_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
void
mir_msgs__srv__ExecMission_Request__Sequence__fini(mir_msgs__srv__ExecMission_Request__Sequence * array);

/// Create array of srv/ExecMission messages.
/**
 * It allocates the memory for the array and calls
 * mir_msgs__srv__ExecMission_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
mir_msgs__srv__ExecMission_Request__Sequence *
mir_msgs__srv__ExecMission_Request__Sequence__create(size_t size);

/// Destroy array of srv/ExecMission messages.
/**
 * It calls
 * mir_msgs__srv__ExecMission_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
void
mir_msgs__srv__ExecMission_Request__Sequence__destroy(mir_msgs__srv__ExecMission_Request__Sequence * array);

/// Check for srv/ExecMission message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Request__Sequence__are_equal(const mir_msgs__srv__ExecMission_Request__Sequence * lhs, const mir_msgs__srv__ExecMission_Request__Sequence * rhs);

/// Copy an array of srv/ExecMission messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Request__Sequence__copy(
  const mir_msgs__srv__ExecMission_Request__Sequence * input,
  mir_msgs__srv__ExecMission_Request__Sequence * output);

/// Initialize srv/ExecMission message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * mir_msgs__srv__ExecMission_Response
 * )) before or use
 * mir_msgs__srv__ExecMission_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Response__init(mir_msgs__srv__ExecMission_Response * msg);

/// Finalize srv/ExecMission message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
void
mir_msgs__srv__ExecMission_Response__fini(mir_msgs__srv__ExecMission_Response * msg);

/// Create srv/ExecMission message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * mir_msgs__srv__ExecMission_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
mir_msgs__srv__ExecMission_Response *
mir_msgs__srv__ExecMission_Response__create();

/// Destroy srv/ExecMission message.
/**
 * It calls
 * mir_msgs__srv__ExecMission_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
void
mir_msgs__srv__ExecMission_Response__destroy(mir_msgs__srv__ExecMission_Response * msg);

/// Check for srv/ExecMission message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Response__are_equal(const mir_msgs__srv__ExecMission_Response * lhs, const mir_msgs__srv__ExecMission_Response * rhs);

/// Copy a srv/ExecMission message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Response__copy(
  const mir_msgs__srv__ExecMission_Response * input,
  mir_msgs__srv__ExecMission_Response * output);

/// Initialize array of srv/ExecMission messages.
/**
 * It allocates the memory for the number of elements and calls
 * mir_msgs__srv__ExecMission_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Response__Sequence__init(mir_msgs__srv__ExecMission_Response__Sequence * array, size_t size);

/// Finalize array of srv/ExecMission messages.
/**
 * It calls
 * mir_msgs__srv__ExecMission_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
void
mir_msgs__srv__ExecMission_Response__Sequence__fini(mir_msgs__srv__ExecMission_Response__Sequence * array);

/// Create array of srv/ExecMission messages.
/**
 * It allocates the memory for the array and calls
 * mir_msgs__srv__ExecMission_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
mir_msgs__srv__ExecMission_Response__Sequence *
mir_msgs__srv__ExecMission_Response__Sequence__create(size_t size);

/// Destroy array of srv/ExecMission messages.
/**
 * It calls
 * mir_msgs__srv__ExecMission_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
void
mir_msgs__srv__ExecMission_Response__Sequence__destroy(mir_msgs__srv__ExecMission_Response__Sequence * array);

/// Check for srv/ExecMission message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Response__Sequence__are_equal(const mir_msgs__srv__ExecMission_Response__Sequence * lhs, const mir_msgs__srv__ExecMission_Response__Sequence * rhs);

/// Copy an array of srv/ExecMission messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_mir_msgs
bool
mir_msgs__srv__ExecMission_Response__Sequence__copy(
  const mir_msgs__srv__ExecMission_Response__Sequence * input,
  mir_msgs__srv__ExecMission_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MIR_MSGS__SRV__DETAIL__EXEC_MISSION__FUNCTIONS_H_
