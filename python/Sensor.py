#!/usr/bin/env python

import time
import smbus
bus = smbus.SMBus(1)

addr_sensor      = 0x10
addr_strip_left  = 0x20
addr_strip_right = 0x21

bus.write_byte(addr_sensor, 1)
time.sleep(0.001)
print "Dist 1 : ", bus.read_byte(addr_sensor)

time.sleep(0.001)
bus.write_byte(addr_sensor, 2)
time.sleep(0.001)
print "Dist 2 : ", bus.read_byte(addr_sensor)

time.sleep(0.001)
bus.write_byte(addr_sensor, 3)
time.sleep(0.001)
print "Dist 3 : ", bus.read_byte(addr_sensor)

#print "Dist 2 : ", bus.read_byte(address)
#print "Dist 3 : ", bus.read_byte(address)