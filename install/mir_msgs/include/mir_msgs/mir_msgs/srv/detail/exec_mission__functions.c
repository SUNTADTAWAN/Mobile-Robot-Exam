// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mir_msgs:srv/ExecMission.idl
// generated code does not contain a copyright notice
#include "mir_msgs/srv/detail/exec_mission__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `mission_name`
#include "rosidl_runtime_c/string_functions.h"

bool
mir_msgs__srv__ExecMission_Request__init(mir_msgs__srv__ExecMission_Request * msg)
{
  if (!msg) {
    return false;
  }
  // mission_name
  if (!rosidl_runtime_c__String__init(&msg->mission_name)) {
    mir_msgs__srv__ExecMission_Request__fini(msg);
    return false;
  }
  return true;
}

void
mir_msgs__srv__ExecMission_Request__fini(mir_msgs__srv__ExecMission_Request * msg)
{
  if (!msg) {
    return;
  }
  // mission_name
  rosidl_runtime_c__String__fini(&msg->mission_name);
}

bool
mir_msgs__srv__ExecMission_Request__are_equal(const mir_msgs__srv__ExecMission_Request * lhs, const mir_msgs__srv__ExecMission_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mission_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mission_name), &(rhs->mission_name)))
  {
    return false;
  }
  return true;
}

bool
mir_msgs__srv__ExecMission_Request__copy(
  const mir_msgs__srv__ExecMission_Request * input,
  mir_msgs__srv__ExecMission_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // mission_name
  if (!rosidl_runtime_c__String__copy(
      &(input->mission_name), &(output->mission_name)))
  {
    return false;
  }
  return true;
}

mir_msgs__srv__ExecMission_Request *
mir_msgs__srv__ExecMission_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mir_msgs__srv__ExecMission_Request * msg = (mir_msgs__srv__ExecMission_Request *)allocator.allocate(sizeof(mir_msgs__srv__ExecMission_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mir_msgs__srv__ExecMission_Request));
  bool success = mir_msgs__srv__ExecMission_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mir_msgs__srv__ExecMission_Request__destroy(mir_msgs__srv__ExecMission_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mir_msgs__srv__ExecMission_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mir_msgs__srv__ExecMission_Request__Sequence__init(mir_msgs__srv__ExecMission_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mir_msgs__srv__ExecMission_Request * data = NULL;

  if (size) {
    data = (mir_msgs__srv__ExecMission_Request *)allocator.zero_allocate(size, sizeof(mir_msgs__srv__ExecMission_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mir_msgs__srv__ExecMission_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mir_msgs__srv__ExecMission_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mir_msgs__srv__ExecMission_Request__Sequence__fini(mir_msgs__srv__ExecMission_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mir_msgs__srv__ExecMission_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mir_msgs__srv__ExecMission_Request__Sequence *
mir_msgs__srv__ExecMission_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mir_msgs__srv__ExecMission_Request__Sequence * array = (mir_msgs__srv__ExecMission_Request__Sequence *)allocator.allocate(sizeof(mir_msgs__srv__ExecMission_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mir_msgs__srv__ExecMission_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mir_msgs__srv__ExecMission_Request__Sequence__destroy(mir_msgs__srv__ExecMission_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mir_msgs__srv__ExecMission_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mir_msgs__srv__ExecMission_Request__Sequence__are_equal(const mir_msgs__srv__ExecMission_Request__Sequence * lhs, const mir_msgs__srv__ExecMission_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mir_msgs__srv__ExecMission_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mir_msgs__srv__ExecMission_Request__Sequence__copy(
  const mir_msgs__srv__ExecMission_Request__Sequence * input,
  mir_msgs__srv__ExecMission_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mir_msgs__srv__ExecMission_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mir_msgs__srv__ExecMission_Request * data =
      (mir_msgs__srv__ExecMission_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mir_msgs__srv__ExecMission_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mir_msgs__srv__ExecMission_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mir_msgs__srv__ExecMission_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
mir_msgs__srv__ExecMission_Response__init(mir_msgs__srv__ExecMission_Response * msg)
{
  if (!msg) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    mir_msgs__srv__ExecMission_Response__fini(msg);
    return false;
  }
  // success
  return true;
}

void
mir_msgs__srv__ExecMission_Response__fini(mir_msgs__srv__ExecMission_Response * msg)
{
  if (!msg) {
    return;
  }
  // message
  rosidl_runtime_c__String__fini(&msg->message);
  // success
}

bool
mir_msgs__srv__ExecMission_Response__are_equal(const mir_msgs__srv__ExecMission_Response * lhs, const mir_msgs__srv__ExecMission_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
mir_msgs__srv__ExecMission_Response__copy(
  const mir_msgs__srv__ExecMission_Response * input,
  mir_msgs__srv__ExecMission_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

mir_msgs__srv__ExecMission_Response *
mir_msgs__srv__ExecMission_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mir_msgs__srv__ExecMission_Response * msg = (mir_msgs__srv__ExecMission_Response *)allocator.allocate(sizeof(mir_msgs__srv__ExecMission_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mir_msgs__srv__ExecMission_Response));
  bool success = mir_msgs__srv__ExecMission_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mir_msgs__srv__ExecMission_Response__destroy(mir_msgs__srv__ExecMission_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mir_msgs__srv__ExecMission_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mir_msgs__srv__ExecMission_Response__Sequence__init(mir_msgs__srv__ExecMission_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mir_msgs__srv__ExecMission_Response * data = NULL;

  if (size) {
    data = (mir_msgs__srv__ExecMission_Response *)allocator.zero_allocate(size, sizeof(mir_msgs__srv__ExecMission_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mir_msgs__srv__ExecMission_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mir_msgs__srv__ExecMission_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
mir_msgs__srv__ExecMission_Response__Sequence__fini(mir_msgs__srv__ExecMission_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      mir_msgs__srv__ExecMission_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

mir_msgs__srv__ExecMission_Response__Sequence *
mir_msgs__srv__ExecMission_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mir_msgs__srv__ExecMission_Response__Sequence * array = (mir_msgs__srv__ExecMission_Response__Sequence *)allocator.allocate(sizeof(mir_msgs__srv__ExecMission_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mir_msgs__srv__ExecMission_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mir_msgs__srv__ExecMission_Response__Sequence__destroy(mir_msgs__srv__ExecMission_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mir_msgs__srv__ExecMission_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mir_msgs__srv__ExecMission_Response__Sequence__are_equal(const mir_msgs__srv__ExecMission_Response__Sequence * lhs, const mir_msgs__srv__ExecMission_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mir_msgs__srv__ExecMission_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mir_msgs__srv__ExecMission_Response__Sequence__copy(
  const mir_msgs__srv__ExecMission_Response__Sequence * input,
  mir_msgs__srv__ExecMission_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mir_msgs__srv__ExecMission_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mir_msgs__srv__ExecMission_Response * data =
      (mir_msgs__srv__ExecMission_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mir_msgs__srv__ExecMission_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mir_msgs__srv__ExecMission_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mir_msgs__srv__ExecMission_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
