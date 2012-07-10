#! /usr/bin/env python
# logger.py

"""Print the serial output from an Arduino, with timestamps on each line.

Usage:

    arlog.py [device] [baud]

Examples:

    arlog.py                  # Log /dev/ttyACM0 at 9600 baud
    arlog.py /dev/tty23       # Log /dev/tty23 at 9600 baud
    arlog.py /dev/tty23 2400  # Log /dev/tty23 at 2400 baud
"""

import sys
import serial
from datetime import datetime

def message(text):
    """Print a message and flush output immediately
    (so the output will be visible with `tail`, `tee` etc.)
    """
    print(text)
    sys.stdout.flush()

def log_serial(device, baud):
    """Log output from a serial device at the given baud rate."""
    try:
        ser = serial.Serial(device, baud)
    except serial.serialutil.SerialException, e:
        message("Problem: %s" % e)
        return

    while True:
        line = ser.readline()
        now = datetime.now()
        message("%s, %s" % (now, line))

if __name__ == '__main__':
    device = '/dev/ttyACM0'
    baud = 9600

    if len(sys.argv) >= 2:
        device = sys.argv[1]
    if len(sys.argv) == 3:
        baud = int(sys.argv[2])

    message("Logging output from %s at %s baud" % (device, baud))
    message("Press Ctrl-C to quit.")

    try:
        log_serial(device, baud)
    except KeyboardInterrupt:
        message("Quitting!")

