#!/usr/bin/env python

import time
import smbus
bus = smbus.SMBus(1)
address = 0x10

bus.write_byte(address, 1)
time.sleep(0.001)
print "Dist 1 : ", bus.read_byte(address)

time.sleep(0.001)
bus.write_byte(address, 2)
time.sleep(0.001)
print "Dist 2 : ", bus.read_byte(address)

time.sleep(0.001)
bus.write_byte(address, 3)
time.sleep(0.001)
print "Dist 3 : ", bus.read_byte(address)

#print "Dist 2 : ", bus.read_byte(address)
#print "Dist 3 : ", bus.read_byte(address)