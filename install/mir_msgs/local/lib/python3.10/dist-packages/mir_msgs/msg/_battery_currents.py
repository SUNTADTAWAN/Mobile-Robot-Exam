# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mir_msgs:msg/BatteryCurrents.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BatteryCurrents(type):
    """Metaclass of message 'BatteryCurrents'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('mir_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'mir_msgs.msg.BatteryCurrents')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__battery_currents
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__battery_currents
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__battery_currents
            cls._TYPE_SUPPORT = module.type_support_msg__msg__battery_currents
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__battery_currents

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BatteryCurrents(metaclass=Metaclass_BatteryCurrents):
    """Message class 'BatteryCurrents'."""

    __slots__ = [
        '_battery1_current',
        '_battery2_current',
    ]

    _fields_and_field_types = {
        'battery1_current': 'double',
        'battery2_current': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.battery1_current = kwargs.get('battery1_current', float())
        self.battery2_current = kwargs.get('battery2_current', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.battery1_current != other.battery1_current:
            return False
        if self.battery2_current != other.battery2_current:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def battery1_current(self):
        """Message field 'battery1_current'."""
        return self._battery1_current

    @battery1_current.setter
    def battery1_current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'battery1_current' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'battery1_current' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._battery1_current = value

    @builtins.property
    def battery2_current(self):
        """Message field 'battery2_current'."""
        return self._battery2_current

    @battery2_current.setter
    def battery2_current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'battery2_current' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'battery2_current' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._battery2_current = value
