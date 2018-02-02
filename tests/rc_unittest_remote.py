#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-

import sys
import operator
from hwt_proxy import sendMessage
from arm_casting_ieee754 import *
from unittest import TestCase

_clockRates = [100,400,200,66,33]
_time_valid = 0
_time_value = 0


class RCUnittestTestCase(TestCase):
    def __init__(self, *args, **kwargs):
        super(RCUnittestTestCase, self).__init__(*args, **kwargs)
        self._hw_addr = 0x41000000
        self._skipInputTicks = 0x0001
        self._skipOutputTicks = 0x0001
        self._enableCycles = 0x00001000
        self._clockRate = 0
        self._testingFUBlock=0



    def _unittest_Reset(self):
        self._skipInputTicks = 0x0001
        self._skipOutputTicks = 0x0001
        self._hw_addr = 0x41000000
        self._enableCycles = 0x00001000
        self._clockRate = 0
        self._testingFUBlock=0

        head,payload=sendMessage(self._hw_addr, 0x00010100, 0x00000000, None)
      

    def CONFIGURE_HW_ADDR(self, addr):
        self._hw_addr = addr

      
    def CONFIGURE_FU_BLOCKS_AS_DUT(self, initialFUBlock, endFUBlock):
        self._testingFUBlock = endFUBlock
        if(initialFUBlock <= endFUBlock and initialFUBlock != 0):
            self._skipInputTicks = initialFUBlock
            self._skipOutputTicks = endFUBlock
        else:
            self._testingFUBlock = 0
            print ("[CRITICAL ERROR] FU-Block testing is not allowed")
            raise 

        
    def CONFIGURE_FU_BLOCK_AS_DUT(self, fu_block):
        self._testingFUBlock = fu_block
        if fu_block == 0:
            self._skipInputTicks = 0x0001
            self._skipOutputTicks = 0x0001
        else:        
            self._skipInputTicks = fu_block
            self._skipOutputTicks = fu_block
          

    def CONFIGURE_ENABLE_CYCLES(self, n):
        self._enableCycles = n

        
    def CONFIGURE_CLOCK_RATE(self, n):
        try:
            self._clockRate = _clockRates.index(n)
        except:
            print ("Clock rate not found!! (Set up default clock rate)")
            self._clockRate = 0

            
    def CONFIGURE_SKIP_INPUT(self, n):
        if self._testingFUBlock == 0:
            self._skipInputTicks = n
        else:
            print ("[CRITICAL ERROR] Skip input not allowed when FU-Block testing is actived")
            raise 
        
          
    def CONFIGURE_SKIP_OUTPUT(self, n):
        if self._testingFUBlock == 0:
            self._skipOutputTicks = n
        else:
            print ("[CRITICAL ERROR] Skip input not allowed when FU-Block testing is actived")
            raise 

        
    def TEST_RESET(self):
        self._unittest_Reset()

    def TEST_START(self):
        global _time_value
        global _time_valid
        _time_value = 0
        _time_valid = 0
        din = []
        #print ("[INFO] Deprecated function version (supported until platform v4)")
        din.extend(int_to_byte((self._skipInputTicks << 16) | self._skipOutputTicks))
        head,payload=sendMessage(self._hw_addr, 0x00010204, 0x00000001, din)

    def TEST_CONFIGURE(self):
        global _time_value
        global _time_valid
        _time_value = 0
        _time_valid = 0
        din = []
        #print ("[INFO] Deprecated function version (supported until platform v6)")
        din.extend(int_to_byte(self._enableCycles))
        din.extend(int_to_byte((self._skipInputTicks << 16) | self._skipOutputTicks))
        head,payload=sendMessage(self._hw_addr, 0x00010204, 0x2, din)

      
    def TEST_SETUP(self):
        global _time_value
        global _time_valid
        _time_value = 0
        _time_valid = 0
        din = []
        din.extend(int_to_byte(self._enableCycles))
        din.extend(int_to_byte((self._skipInputTicks << 16) | self._skipOutputTicks))
        din.extend(int_to_byte((self._clockRate << 24) | 0x000000))
        #din.extend(int_to_byte(0x01000000))
        head,payload=sendMessage(self._hw_addr, 0x00010204, 0x3, din)

    
    def unittest_TimeGetTime(self):
        global _time_valid
        global _time_value
        if _time_valid == 1:
            return _time_value

        head,payload=sendMessage(self._hw_addr, 0x00010300, 0x00000000, None)
        time = payload[0]

        #self._unittest_TimeReset()
        _time_valid = 1
        if self._testingFUBlock == 0:
            _time_value = time #int(str(time),16)
        else:
            _time_value = time - (int(self._testingFUBlock)-1)
        return _time_value


    def assertGeneral(self, func, expected):
        #timeExecution = int(str(self.unittest_TimeGetTime()),16)
        timeExecution = self.unittest_TimeGetTime()
        print(timeExecution)
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


