#!/usr/bin/python
# -*- coding: utf-8; mode: python -*-


import Ice
from service_config import fpga_endpoint
from arm_casting_ieee754 import *

Ice.loadSlice("/opt/hw_testing/tools/slices/testingService.ice")
import TestingService


def sendMessage(hwAddr, head1, head2, din):
    _din =[]
    _din.extend(int_to_byte(head1))
    _din.extend(int_to_byte(head2))
    if din != None:
        _din.extend(din)
     
    testCli = FPGA_hwtClient()
    testCli.arguments(hwAddr, _din)
    testCli.main([None])#[fpga_endpoint])
    dout = testCli.result()
    idout = charSeq_to_intSeq(dout)

    del testCli
    
    if idout != None:
        return idout[0:2], idout[2:]
    del idout


class FPGA_hwtClient(Ice.Application):
    def arguments(self, addr, din):
        self.din = din
        self.addr = addr
        self.dout = None

    def result(self):
        return self.dout      

        
    def run(self, args):        
        ic = self.communicator()

        proxy = ic.stringToProxy(fpga_endpoint)
        proxy = TestingService.GCommandPrx.uncheckedCast(proxy)
        self.dout=proxy.remoteExec(self.addr, self.din)

