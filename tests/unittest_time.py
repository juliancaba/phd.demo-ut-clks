#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-

import sys
import operator
from hwt_proxy import sendMessage
from arm_casting_ieee754 import *
from unittest import TestCase

_clocks = [100,400,200,66,33]
_time_valid = 0
_time_value = 0

class TimeTestCase(TestCase):
    def __init__(self, *args, **kwargs):
      super(TimeTestCase, self).__init__(*args, **kwargs)
      self._time_hw_addr = 0x41000000
      self._inputWords = 0x0001
      self._outputWords = 0x0001
      self._enableCycles = 0x00001000
      self._clock = 0


    def _unittest_TimeReset(self):
      self._inputWords = 0x0001
      self._outputWords = 0x0001
      self._time_hw_addr = 0x41000000
      self._enableCycles = 0x00001000
      self._clock = 0

      head,payload=sendMessage(self._time_hw_addr, 0x00010100, 0x00000000, None)
      

    def CONFIGURE_UNITTEST_TIME_HW_ADDR(self, addr):
      self._time_hw_addr = addr

    def CONFIGURE_UNITTEST_TIME_ENABLE_CYCLES(self, n):
      self._enableCycles = n

    def CONFIGURE_UNITTEST_TIME_CLOCK(self, n):
        try:
            self._clock = _clocks.index(n)
        except:
            print ("Clock rate not found!! (Set up default clock)")
            self._clock = 0
      
    def CONFIGURE_UNITTEST_TIME_INPUT_32BIT_WORDS(self, n):
      self._inputWords = n
    
    def CONFIGURE_UNITTEST_TIME_OUTPUT_32BIT_WORDS(self, n):
      self._outputWords = n

    def UNITTEST_TIME_RESET(self):
        self._unittest_TimeReset()

    def UNITTEST_TIME_START(self):
      global _time_value
      global _time_valid
      _time_value = 0
      _time_valid = 0
      din = []
      print ("[INFO] Deprecated function version (supported until platform v4)")
      din.extend(int_to_byte((self._inputWords << 16) | self._outputWords))
      head,payload=sendMessage(self._time_hw_addr, 0x00010204, 0x00000001, din)

    def UNITTEST_TIME_CONFIGURE(self):
      global _time_value
      global _time_valid
      _time_value = 0
      _time_valid = 0
      din = []
      print ("[INFO] Deprecated function version (supported until platform v6)")
      din.extend(int_to_byte(self._enableCycles))
      din.extend(int_to_byte((self._inputWords << 16) | self._outputWords))
      head,payload=sendMessage(self._time_hw_addr, 0x00010204, 0x2, din)

      
    def UNITTEST_TIME_SETUP(self):
      global _time_value
      global _time_valid
      _time_value = 0
      _time_valid = 0
      din = []
      din.extend(int_to_byte(self._enableCycles))
      din.extend(int_to_byte((self._inputWords << 16) | self._outputWords))
      din.extend(int_to_byte((self._clock << 24) | 0x000000))
      #din.extend(int_to_byte(0x01000000))
      head,payload=sendMessage(self._time_hw_addr, 0x00010204, 0x3, din)

    
    def unittest_TimeGetTime(self):
      global _time_valid
      global _time_value
      if _time_valid == 1:
        return _time_value

      head,payload=sendMessage(self._time_hw_addr, 0x00010300, 0x00000000, None)
      time = payload[0]

      #self._unittest_TimeReset()
      _time_valid = 1
      _time_value = time

      return time


    def assertGeneral(self, func, expected):
      timeExecution = int(str(self.unittest_TimeGetTime()),16)
      evaluation = func(timeExecution, expected, msg=("TIME FAIL!!!"))


    def assertTimeEQ(self, expected):
      self.assertGeneral(self.assertEqual, expected)

    def assertTimeGT(self, expected):
      self.assertGeneral(self.assertGreater, expected)

    def assertTimeLT(self, expected):
      self.assertGeneral(self.assertLess, expected)

    def assertTimeGE(self, expected):
      self.assertGeneral(self.assertGreaterEqual, expected)

    def assertTimeLE(self, expected):
      self.assertGeneral(self.assertLessEqual, expected)


