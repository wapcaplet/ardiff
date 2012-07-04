#! /usr/bin/env python
# logger.py

"""Log the serial output from the Arduino to a text file.
"""

import sys
import serial

def log_serial(filename, device='/dev/ttyACM0', baud=9600):
    ser = serial.Serial(device, baud)
    outfile = open(filename, 'w')
    while True:
        line = ser.readline()
        print(line)
        outfile.write(line)

if __name__ == '__main__':
    filename = sys.argv[1]
    log_serial(filename)

