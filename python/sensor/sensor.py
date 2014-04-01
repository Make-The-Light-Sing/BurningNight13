#!/usr/bin/env python

import time
import smbus
bus = smbus.SMBus(1)

class Sensor(object):
    def __init__(self, address, debug = False):
        self.address = address
        self.debug = debug

    """ Read values from sensor, this values are retrieved from the Arduino via the i2c bus"""
    def getAllValues(self):
        dist_1 = self.getValue(1)
        dist_2 = self.getValue(2)
        dist_3 = self.getValue(3)
        return [dist_1, dist_2, dist_3]

    """ Read value from a single sensor """
    def getValue(self, index):
        bus.write_byte(self.address, index)
        time.sleep(0.001)
        return bus.read_byte(self.address)
