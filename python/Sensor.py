#!/usr/bin/env python

import time
import smbus
from ledstrip import Ledstrip

bus = smbus.SMBus(1)

addr_sensor      = 0x10
addr_strip_left  = 0x20
addr_strip_right = 0x21

strip_left = Ledstrip(addr_strip_left)

""" Read values from sensor, this values are retrieved from the Arduino via the i2c bus"""
def readSensorValues():
    """ Read sensor 1"""
    bus.write_byte(addr_sensor, 1)
    time.sleep(0.001)
    dist_1 = bus.read_byte(addr_sensor)
    
    """ Read sensor 2"""
    time.sleep(0.001)
    bus.write_byte(addr_sensor, 2)
    time.sleep(0.001)
    dist_2 = bus.read_byte(addr_sensor)
    
    """ Read sensor 3"""
    time.sleep(0.001)
    bus.write_byte(addr_sensor, 3)
    time.sleep(0.001)
    dist_3 = bus.read_byte(addr_sensor)
    
    """ Return read values"""
    return [dist_1, dist_2, dist_3]

while True:
    sensorValues = readSensorValues()
    print "Dist : ", sensorValues
    strip_left.sendData(sensorValues)
    time.sleep(0.1)

#bus.write_byte(addr_strip_left, dist_1)

#print "Dist 2 : ", bus.read_byte(address)
#print "Dist 3 : ", bus.read_byte(address)