#!/usr/bin/env python

import time
from ledstrip import Ledstrip
addr_strip_left  = 0x20

strip_left = Ledstrip(addr_strip_left, True)
strip_left.setSegmentColor(0, [255, 255, 255])