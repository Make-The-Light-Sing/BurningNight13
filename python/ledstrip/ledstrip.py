#!/usr/bin/env python

import smbus
bus = smbus.SMBus(1)
#import serial

commands = {"setLedColor":1}

class Ledstrip(object):
    """ Constructor """
    def __init__(self, address, debug = False):
        self.address = address
        self.debug = debug
        self.max_attempts = 0

    """ Send data to the arduino """
    def sendData(self, data):
        dataRecieved = 0
        attempt = 0
        length = len(data) + 2
        data.insert(0, length)
        if (self.debug):
            print "Sending datas : ", length
            print data
        while(True):
            attempt += 1
            try:
                bus.write_i2c_block_data(self.address, 0x00, data)
                dataRecieved = bus.read_byte(self.address)
                if self.debug:
                    print "Recieved : ", dataRecieved
                if (dataRecieved == length):
                    break
            except IOError:
                if (self.debug):
                    print("IOError in writeData")
        if self.debug:
            print "Number of attempt ", attempt
        if attempt > self.max_attempts:
            self.max_attempts = attempt
        return attempt

    """ Change color of a dedicated segment"""
    def setSegmentColor(self, segment, color):
        data = [commands["setLedColor"], segment] + color
        return self.sendData(data)
