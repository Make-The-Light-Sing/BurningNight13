#!/usr/bin/env python

import smbus
bus = smbus.SMBus(1)
#import serial

class Ledstrip(object):
    def __init__(self, address, debug = False):
        self.address = address
        self.debug = debug
        self.max_attempts = 0

    def sendData(self, data):
        dataRecieved = 0
        attempt = 0
        if (self.debug):
            print "Sending datas : ", len(data)
        while(True):
            attempt += 1
            try:
                bus.write_i2c_block_data(self.address, 0x00, data)
                dataRecieved = bus.read_byte(self.address)
                if self.debug:
                    print "Recieved : ", dataRecieved
                if (dataRecieved == len(data) + 1):
                    break
            except IOError:
                print("IOError in writeData")
        if self.debug:
            print "Number of attempt ", attempt
        if attempt > self.max_attempts:
            self.max_attempts = attempt
        return attempt
