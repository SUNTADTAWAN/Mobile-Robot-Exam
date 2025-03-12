// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from mir_msgs:msg/BMSData.idl
// generated code does not contain a copyright notice
#include "mir_msgs/msg/detail/bms_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `cell_voltage`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
mir_msgs__msg__BMSData__init(mir_msgs__msg__BMSData * msg)
{
  if (!msg) {
    return false;
  }
  // pack_voltage
  // charge_current
  // discharge_current
  // state_of_charge
  // remaining_time_to_full_charge
  // remaining_capacity
  // state_of_health
  // status_flags
  // temperature
  // cell_voltage
  if (!rosidl_runtime_c__uint32__Sequence__init(&msg->cell_voltage, 0)) {
    mir_msgs__msg__BMSData__fini(msg);
    return false;
  }
  // last_battery_msg_time
  return true;
}

void
mir_msgs__msg__BMSData__fini(mir_msgs__msg__BMSData * msg)
{
  if (!msg) {
    return;
  }
  // pack_voltage
  // charge_current
  // discharge_current
  // state_of_charge
  // remaining_time_to_full_charge
  // remaining_capacity
  // state_of_health
  // status_flags
  // temperature
  // cell_voltage
  rosidl_runtime_c__uint32__Sequence__fini(&msg->cell_voltage);
  // last_battery_msg_time
}

bool
mir_msgs__msg__BMSData__are_equal(const mir_msgs__msg__BMSData * lhs, const mir_msgs__msg__BMSData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pack_voltage
  if (lhs->pack_voltage != rhs->pack_voltage) {
    return false;
  }
  // charge_current
  if (lhs->charge_current != rhs->charge_current) {
    return false;
  }
  // discharge_current
  if (lhs->discharge_current != rhs->discharge_current) {
    return false;
  }
  // state_of_charge
  if (lhs->state_of_charge != rhs->state_of_charge) {
    return false;
  }
  // remaining_time_to_full_charge
  if (lhs->remaining_time_to_full_charge != rhs->remaining_time_to_full_charge) {
    return false;
  }
  // remaining_capacity
  if (lhs->remaining_capacity != rhs->remaining_capacity) {
    return false;
  }
  // state_of_health
  if (lhs->state_of_health != rhs->state_of_health) {
    return false;
  }
  // status_flags
  if (lhs->status_flags != rhs->status_flags) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // cell_voltage
  if (!rosidl_runtime_c__uint32__Sequence__are_equal(
      &(lhs->cell_voltage), &(rhs->cell_voltage)))
  {
    return false;
  }
  // last_battery_msg_time
  if (lhs->last_battery_msg_time != rhs->last_battery_msg_time) {
    return false;
  }
  return true;
}

bool
mir_msgs__msg__BMSData__copy(
  const mir_msgs__msg__BMSData * input,
  mir_msgs__msg__BMSData * output)
{
  if (!input || !output) {
    return false;
  }
  // pack_voltage
  output->pack_voltage = input->pack_voltage;
  // charge_current
  output->charge_current = input->charge_current;
  // discharge_current
  output->discharge_current = input->discharge_current;
  // state_of_charge
  output->state_of_charge = input->state_of_charge;
  // remaining_time_to_full_charge
  output->remaining_time_to_full_charge = input->remaining_time_to_full_charge;
  // remaining_capacity
  output->remaining_capacity = input->remaining_capacity;
  // state_of_health
  output->state_of_health = input->state_of_health;
  // status_flags
  output->status_flags = input->status_flags;
  // temperature
  output->temperature = input->temperature;
  // cell_voltage
  if (!rosidl_runtime_c__uint32__Sequence__copy(
      &(input->cell_voltage), &(output->cell_voltage)))
  {
    return false;
  }
  // last_battery_msg_time
  output->last_battery_msg_time = input->last_battery_msg_time;
  return true;
}

mir_msgs__msg__BMSData *
mir_msgs__msg__BMSData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mir_msgs__msg__BMSData * msg = (mir_msgs__msg__BMSData *)allocator.allocate(sizeof(mir_msgs__msg__BMSData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(mir_msgs__msg__BMSData));
  bool success = mir_msgs__msg__BMSData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
mir_msgs__msg__BMSData__destroy(mir_msgs__msg__BMSData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    mir_msgs__msg__BMSData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
mir_msgs__msg__BMSData__Sequence__init(mir_msgs__msg__BMSData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mir_msgs__msg__BMSData * data = NULL;

  if (size) {
    data = (mir_msgs__msg__BMSData *)allocator.zero_allocate(size, sizeof(mir_msgs__msg__BMSData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = mir_msgs__msg__BMSData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        mir_msgs__msg__BMSData__fini(&data[i - 1]);
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
mir_msgs__msg__BMSData__Sequence__fini(mir_msgs__msg__BMSData__Sequence * array)
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
      mir_msgs__msg__BMSData__fini(&array->data[i]);
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

mir_msgs__msg__BMSData__Sequence *
mir_msgs__msg__BMSData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  mir_msgs__msg__BMSData__Sequence * array = (mir_msgs__msg__BMSData__Sequence *)allocator.allocate(sizeof(mir_msgs__msg__BMSData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = mir_msgs__msg__BMSData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
mir_msgs__msg__BMSData__Sequence__destroy(mir_msgs__msg__BMSData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    mir_msgs__msg__BMSData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
mir_msgs__msg__BMSData__Sequence__are_equal(const mir_msgs__msg__BMSData__Sequence * lhs, const mir_msgs__msg__BMSData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!mir_msgs__msg__BMSData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
mir_msgs__msg__BMSData__Sequence__copy(
  const mir_msgs__msg__BMSData__Sequence * input,
  mir_msgs__msg__BMSData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(mir_msgs__msg__BMSData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    mir_msgs__msg__BMSData * data =
      (mir_msgs__msg__BMSData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!mir_msgs__msg__BMSData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          mir_msgs__msg__BMSData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!mir_msgs__msg__BMSData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
