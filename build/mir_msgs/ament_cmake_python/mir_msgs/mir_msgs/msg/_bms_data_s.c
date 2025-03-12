// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from mir_msgs:msg/BMSData.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "mir_msgs/msg/detail/bms_data__struct.h"
#include "mir_msgs/msg/detail/bms_data__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool mir_msgs__msg__bms_data__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[31];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("mir_msgs.msg._bms_data.BMSData", full_classname_dest, 30) == 0);
  }
  mir_msgs__msg__BMSData * ros_message = _ros_message;
  {  // pack_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "pack_voltage");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->pack_voltage = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // charge_current
    PyObject * field = PyObject_GetAttrString(_pymsg, "charge_current");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->charge_current = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // discharge_current
    PyObject * field = PyObject_GetAttrString(_pymsg, "discharge_current");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->discharge_current = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // state_of_charge
    PyObject * field = PyObject_GetAttrString(_pymsg, "state_of_charge");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state_of_charge = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // remaining_time_to_full_charge
    PyObject * field = PyObject_GetAttrString(_pymsg, "remaining_time_to_full_charge");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->remaining_time_to_full_charge = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // remaining_capacity
    PyObject * field = PyObject_GetAttrString(_pymsg, "remaining_capacity");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->remaining_capacity = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // state_of_health
    PyObject * field = PyObject_GetAttrString(_pymsg, "state_of_health");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state_of_health = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // status_flags
    PyObject * field = PyObject_GetAttrString(_pymsg, "status_flags");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->status_flags = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // temperature
    PyObject * field = PyObject_GetAttrString(_pymsg, "temperature");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->temperature = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // cell_voltage
    PyObject * field = PyObject_GetAttrString(_pymsg, "cell_voltage");
    if (!field) {
      return false;
    }
    if (PyObject_CheckBuffer(field)) {
      // Optimization for converting arrays of primitives
      Py_buffer view;
      int rc = PyObject_GetBuffer(field, &view, PyBUF_SIMPLE);
      if (rc < 0) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = view.len / sizeof(uint32_t);
      if (!rosidl_runtime_c__uint32__Sequence__init(&(ros_message->cell_voltage), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create uint32__Sequence ros_message");
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      uint32_t * dest = ros_message->cell_voltage.data;
      rc = PyBuffer_ToContiguous(dest, &view, view.len, 'C');
      if (rc < 0) {
        PyBuffer_Release(&view);
        Py_DECREF(field);
        return false;
      }
      PyBuffer_Release(&view);
    } else {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'cell_voltage'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = PySequence_Size(field);
      if (-1 == size) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      if (!rosidl_runtime_c__uint32__Sequence__init(&(ros_message->cell_voltage), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create uint32__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      uint32_t * dest = ros_message->cell_voltage.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyLong_Check(item));
        uint32_t tmp = PyLong_AsUnsignedLong(item);

        memcpy(&dest[i], &tmp, sizeof(uint32_t));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // last_battery_msg_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "last_battery_msg_time");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->last_battery_msg_time = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * mir_msgs__msg__bms_data__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BMSData */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("mir_msgs.msg._bms_data");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BMSData");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  mir_msgs__msg__BMSData * ros_message = (mir_msgs__msg__BMSData *)raw_ros_message;
  {  // pack_voltage
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->pack_voltage);
    {
      int rc = PyObject_SetAttrString(_pymessage, "pack_voltage", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // charge_current
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->charge_current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "charge_current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // discharge_current
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->discharge_current);
    {
      int rc = PyObject_SetAttrString(_pymessage, "discharge_current", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state_of_charge
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->state_of_charge);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state_of_charge", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // remaining_time_to_full_charge
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->remaining_time_to_full_charge);
    {
      int rc = PyObject_SetAttrString(_pymessage, "remaining_time_to_full_charge", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // remaining_capacity
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->remaining_capacity);
    {
      int rc = PyObject_SetAttrString(_pymessage, "remaining_capacity", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state_of_health
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->state_of_health);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state_of_health", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // status_flags
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->status_flags);
    {
      int rc = PyObject_SetAttrString(_pymessage, "status_flags", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // temperature
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->temperature);
    {
      int rc = PyObject_SetAttrString(_pymessage, "temperature", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // cell_voltage
    PyObject * field = NULL;
    field = PyObject_GetAttrString(_pymessage, "cell_voltage");
    if (!field) {
      return NULL;
    }
    assert(field->ob_type != NULL);
    assert(field->ob_type->tp_name != NULL);
    assert(strcmp(field->ob_type->tp_name, "array.array") == 0);
    // ensure that itemsize matches the sizeof of the ROS message field
    PyObject * itemsize_attr = PyObject_GetAttrString(field, "itemsize");
    assert(itemsize_attr != NULL);
    size_t itemsize = PyLong_AsSize_t(itemsize_attr);
    Py_DECREF(itemsize_attr);
    if (itemsize != sizeof(uint32_t)) {
      PyErr_SetString(PyExc_RuntimeError, "itemsize doesn't match expectation");
      Py_DECREF(field);
      return NULL;
    }
    // clear the array, poor approach to remove potential default values
    Py_ssize_t length = PyObject_Length(field);
    if (-1 == length) {
      Py_DECREF(field);
      return NULL;
    }
    if (length > 0) {
      PyObject * pop = PyObject_GetAttrString(field, "pop");
      assert(pop != NULL);
      for (Py_ssize_t i = 0; i < length; ++i) {
        PyObject * ret = PyObject_CallFunctionObjArgs(pop, NULL);
        if (!ret) {
          Py_DECREF(pop);
          Py_DECREF(field);
          return NULL;
        }
        Py_DECREF(ret);
      }
      Py_DECREF(pop);
    }
    if (ros_message->cell_voltage.size > 0) {
      // populating the array.array using the frombytes method
      PyObject * frombytes = PyObject_GetAttrString(field, "frombytes");
      assert(frombytes != NULL);
      uint32_t * src = &(ros_message->cell_voltage.data[0]);
      PyObject * data = PyBytes_FromStringAndSize((const char *)src, ros_message->cell_voltage.size * sizeof(uint32_t));
      assert(data != NULL);
      PyObject * ret = PyObject_CallFunctionObjArgs(frombytes, data, NULL);
      Py_DECREF(data);
      Py_DECREF(frombytes);
      if (!ret) {
        Py_DECREF(field);
        return NULL;
      }
      Py_DECREF(ret);
    }
    Py_DECREF(field);
  }
  {  // last_battery_msg_time
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->last_battery_msg_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "last_battery_msg_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
