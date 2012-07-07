#! /usr/bin/env python
# logger.py

"""Log the serial output from the Arduino to a text file.
"""

import sys
import serial
from datetime import datetime

def log_serial(filename, device='/dev/ttyACM0', baud=9600):
    ser = serial.Serial(device, baud)
    outfile = open(filename, 'w')
    try:
        while True:
            line = ser.readline()
            now = datetime.now()
            print("%s, %s" % (now, line))
            outfile.write("%s, %s" % (now, line))
    except KeyboardInterrupt:
        print("Quitting!")
        outfile.close()

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: logger.py <filename>")
    filename = sys.argv[1]
    log_serial(filename)

