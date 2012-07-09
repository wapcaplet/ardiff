ardiff
======

This is an Arduino project for controlling a water pump for a solar water
heater. Includes:

- `controller`: Arduino 1.x sketch for the controller
- `arlog.py`: A simple Python script for monitoring the Arduino's serial output

Circuit
-------

To make effective use of this controller, you'll need circuits for your
temperature sensors and for the pump relay. Some example circuits made using
[Qucs](http://qucs.sourceforge.net/) are provided in the `schematics`
directory.


Requirements
------------

Because the temperature sensors need to be at the end of longish wires, this
controller uses the DS18B20 temperature sensors, which require the
[OneWire](http://www.pjrc.com/teensy/td_libs_OneWire.html) and
[DallasTemperature](http://milesburton.com/Main_Page?title=Dallas_Temperature_Control_Library)
libraries. Download and extract those, and put them in your
`~/sketchbook/libraries` folder before using this controller.


License
-------

MIT License.

