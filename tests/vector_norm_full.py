#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-



from hwt_proxy import FPGA_hwtClient
from arm_casting_ieee754 import *

import sys


def scale2(sum):
    din = []
    din.extend(int_to_byte(0x00010104))
    din.extend(int_to_byte(0x00000001))
    din.extend(int_to_byte(float_to_ieee754(sum)))

    print(din)
    testCli = FPGA_hwtClient()
    testCli.arguments(0x42000000, din)
    testCli.main([None])#[fpga_endpoint])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    print (idout)
    head1 = idout[0]
    head2 = idout[1]
    _ret = ieee754_to_float(idout[2])

    del testCli
    del idout
    
    return _ret


def sum_hist_pow(histIN):
    din = []
    din.extend(int_to_byte(0x00010204))
    din.extend(int_to_byte(0x00000010))

    for it in histIN:
        din.extend(int_to_byte(float_to_ieee754(it)))
    
    testCli = FPGA_hwtClient()
    testCli.arguments(0x42000000, din)
    testCli.main([None])#[fpga_endpoint])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)
    
    head1 = idout[0]
    head2 = idout[1]
    _ret = ieee754_to_float(idout[2])
    
    del testCli
    return _ret

def mult_hist_scale(histAUX, scale, histOUT):    
    din = []
    din.extend(int_to_byte(0x00010304))
    din.extend(int_to_byte(0x00000011))

    for it in histAUX:
        din.extend(int_to_byte(float_to_ieee754(it)))
        
    din.extend(int_to_byte(float_to_ieee754(scale)))
        
    testCli = FPGA_hwtClient()
    testCli.arguments(0x42000000, din)
    testCli.main([None])#[fpga_endpoint])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)
    
    head1 = idout[0]
    head2 = idout[1]
    _ret = []
    for indx in range(0,16):
        _ret.append(ieee754_to_float(idout[indx]))

    histOUT = _ret
    del testCli
