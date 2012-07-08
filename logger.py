#! /usr/bin/env python
# logger.py

"""Print the serial output from an Arduino.
"""

import sys
import serial
from datetime import datetime

def log_serial(device='/dev/ttyACM0', baud=9600):
    print("Logging output from %s. Press Ctrl-C to stop.")
    ser = serial.Serial(device, baud)
    try:
        while True:
            line = ser.readline().strip()
            now = datetime.now()
            print("%s, %s" % (now, line))
    except KeyboardInterrupt:
        print("Quitting!")

if __name__ == '__main__':
    log_serial()

