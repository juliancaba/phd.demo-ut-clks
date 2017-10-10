#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-


import struct

    
def float_to_ieee754(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def ieee754_to_float(ieee):
    return (struct.unpack('f', struct.pack('<I', int(ieee,16)))[0])


def double_to_ieee754(d):
    return struct.unpack('<Q', struct.pack('<d', d))[0]


def ieee754_to_double(ieee):
    return (struct.unpack('d', struct.pack('<Q', int(ieee,16)))[0])


def charSeq_to_intSeq(cseq):
    iseq = []
    it_index = 1
    aux = []
    if cseq == None:
        return None

    for it in cseq:
        aux.append(int(it))
        it_index += 1
        if it_index%4 == 1:
            iseq.append(hex(struct.unpack("<I",  bytearray(aux))[0]))
            aux = []
    return iseq


def int_to_byte(n):
    b = []
    for it in range(0,4):
        b.append(n&0xFF)
        n >>= 8
    return b
