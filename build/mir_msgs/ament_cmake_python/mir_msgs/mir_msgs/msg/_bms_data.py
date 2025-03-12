# generated from rosidl_generator_py/resource/_idl.py.em
# with input from mir_msgs:msg/BMSData.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'cell_voltage'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BMSData(type):
    """Metaclass of message 'BMSData'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'DISCHARGING': 1,
        'CHARGING': 2,
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
                'mir_msgs.msg.BMSData')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__bms_data
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__bms_data
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__bms_data
            cls._TYPE_SUPPORT = module.type_support_msg__msg__bms_data
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__bms_data

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'DISCHARGING': cls.__constants['DISCHARGING'],
            'CHARGING': cls.__constants['CHARGING'],
        }

    @property
    def DISCHARGING(self):
        """Message constant 'DISCHARGING'."""
        return Metaclass_BMSData.__constants['DISCHARGING']

    @property
    def CHARGING(self):
        """Message constant 'CHARGING'."""
        return Metaclass_BMSData.__constants['CHARGING']


class BMSData(metaclass=Metaclass_BMSData):
    """
    Message class 'BMSData'.

    Constants:
      DISCHARGING
      CHARGING
    """

    __slots__ = [
        '_pack_voltage',
        '_charge_current',
        '_discharge_current',
        '_state_of_charge',
        '_remaining_time_to_full_charge',
        '_remaining_capacity',
        '_state_of_health',
        '_status_flags',
        '_temperature',
        '_cell_voltage',
        '_last_battery_msg_time',
    ]

    _fields_and_field_types = {
        'pack_voltage': 'double',
        'charge_current': 'double',
        'discharge_current': 'double',
        'state_of_charge': 'int32',
        'remaining_time_to_full_charge': 'double',
        'remaining_capacity': 'int32',
        'state_of_health': 'int32',
        'status_flags': 'int32',
        'temperature': 'int32',
        'cell_voltage': 'sequence<uint32>',
        'last_battery_msg_time': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint32')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pack_voltage = kwargs.get('pack_voltage', float())
        self.charge_current = kwargs.get('charge_current', float())
        self.discharge_current = kwargs.get('discharge_current', float())
        self.state_of_charge = kwargs.get('state_of_charge', int())
        self.remaining_time_to_full_charge = kwargs.get('remaining_time_to_full_charge', float())
        self.remaining_capacity = kwargs.get('remaining_capacity', int())
        self.state_of_health = kwargs.get('state_of_health', int())
        self.status_flags = kwargs.get('status_flags', int())
        self.temperature = kwargs.get('temperature', int())
        self.cell_voltage = array.array('I', kwargs.get('cell_voltage', []))
        self.last_battery_msg_time = kwargs.get('last_battery_msg_time', float())

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
        if self.pack_voltage != other.pack_voltage:
            return False
        if self.charge_current != other.charge_current:
            return False
        if self.discharge_current != other.discharge_current:
            return False
        if self.state_of_charge != other.state_of_charge:
            return False
        if self.remaining_time_to_full_charge != other.remaining_time_to_full_charge:
            return False
        if self.remaining_capacity != other.remaining_capacity:
            return False
        if self.state_of_health != other.state_of_health:
            return False
        if self.status_flags != other.status_flags:
            return False
        if self.temperature != other.temperature:
            return False
        if self.cell_voltage != other.cell_voltage:
            return False
        if self.last_battery_msg_time != other.last_battery_msg_time:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pack_voltage(self):
        """Message field 'pack_voltage'."""
        return self._pack_voltage

    @pack_voltage.setter
    def pack_voltage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pack_voltage' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pack_voltage' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pack_voltage = value

    @builtins.property
    def charge_current(self):
        """Message field 'charge_current'."""
        return self._charge_current

    @charge_current.setter
    def charge_current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'charge_current' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'charge_current' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._charge_current = value

    @builtins.property
    def discharge_current(self):
        """Message field 'discharge_current'."""
        return self._discharge_current

    @discharge_current.setter
    def discharge_current(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'discharge_current' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'discharge_current' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._discharge_current = value

    @builtins.property
    def state_of_charge(self):
        """Message field 'state_of_charge'."""
        return self._state_of_charge

    @state_of_charge.setter
    def state_of_charge(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state_of_charge' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'state_of_charge' field must be an integer in [-2147483648, 2147483647]"
        self._state_of_charge = value

    @builtins.property
    def remaining_time_to_full_charge(self):
        """Message field 'remaining_time_to_full_charge'."""
        return self._remaining_time_to_full_charge

    @remaining_time_to_full_charge.setter
    def remaining_time_to_full_charge(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'remaining_time_to_full_charge' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'remaining_time_to_full_charge' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._remaining_time_to_full_charge = value

    @builtins.property
    def remaining_capacity(self):
        """Message field 'remaining_capacity'."""
        return self._remaining_capacity

    @remaining_capacity.setter
    def remaining_capacity(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'remaining_capacity' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'remaining_capacity' field must be an integer in [-2147483648, 2147483647]"
        self._remaining_capacity = value

    @builtins.property
    def state_of_health(self):
        """Message field 'state_of_health'."""
        return self._state_of_health

    @state_of_health.setter
    def state_of_health(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state_of_health' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'state_of_health' field must be an integer in [-2147483648, 2147483647]"
        self._state_of_health = value

    @builtins.property
    def status_flags(self):
        """Message field 'status_flags'."""
        return self._status_flags

    @status_flags.setter
    def status_flags(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status_flags' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'status_flags' field must be an integer in [-2147483648, 2147483647]"
        self._status_flags = value

    @builtins.property
    def temperature(self):
        """Message field 'temperature'."""
        return self._temperature

    @temperature.setter
    def temperature(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'temperature' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'temperature' field must be an integer in [-2147483648, 2147483647]"
        self._temperature = value

    @builtins.property
    def cell_voltage(self):
        """Message field 'cell_voltage'."""
        return self._cell_voltage

    @cell_voltage.setter
    def cell_voltage(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'I', \
                "The 'cell_voltage' array.array() must have the type code of 'I'"
            self._cell_voltage = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 4294967296 for val in value)), \
                "The 'cell_voltage' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 4294967295]"
        self._cell_voltage = array.array('I', value)

    @builtins.property
    def last_battery_msg_time(self):
        """Message field 'last_battery_msg_time'."""
        return self._last_battery_msg_time

    @last_battery_msg_time.setter
    def last_battery_msg_time(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'last_battery_msg_time' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'last_battery_msg_time' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._last_battery_msg_time = value
