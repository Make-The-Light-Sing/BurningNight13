#!/usr/bin/env python

import time
from ledstrip import Ledstrip
from sensor import Sensor

debug = False


""" Define address of different slaves on i2c bus """
addr_sensor      = 0x10
addr_strip_left  = 0x20
addr_strip_right = 0x21

""" Instanciate slaves """
strip_left = Ledstrip(addr_strip_left, debug)
sensor = Sensor(addr_sensor, debug)

""" Main loop """
print "Running..."
while True:
    sensorValues = sensor.getAllValues()
    if debug:
        print "Dist : ", sensorValues
    strip_left.sendData(sensorValues)
    time.sleep(0.1)
