/*
Differential controller

Wiring:
  pump_pin through 1K resistor to LED (simulates pump)
  A0 to middle pin of tank thermometer
  A1 to middle pin of collector thermometer
  5V to left pin of both thermometers
  Ground to right pin of both thermometers

Desirable features:
  - Customizable target tank temperature
  - Customizable differential in tank/collector temp

Basic behavior:
  - If collector is hotter than tank AND tank is not at max temp,
    then turn on the pump
  - If collector is colder than tank OR tank is at max temp,
    then turn off the pump

For later:
  - LCD display of tank/collector temp
*/

#include <OneWire.h>
#include <DallasTemperature.h>

// Digital pin to use for the 1-wire sensor bus
#define ONE_WIRE_BUS 3

// Initialize OneWire
OneWire one_wire(ONE_WIRE_BUS);
DallasTemperature sensors(&one_wire);

// OneWire Sensor addresses
DeviceAddress tank_sensor = { 0x28, 0x95, 0xD2, 0xCE, 0x03, 0x00, 0x00, 0x51 };
DeviceAddress collector_sensor = { 0x28, 0xD4, 0xD3, 0xCE, 0x03, 0x00, 0x00, 0xDE };

int pump_pin = 8;
boolean pump_on = false;

float tank_max_temp = 140;      // Deg. F; above this, pump is off
float collector_min_temp = 40;  // Deg. F; below this, pump is off
float on_threshold = 10;        // Deg. F differential before pump turns on
float off_threshold = 10;       // Deg. F differential before pump turns off
int interval = 60000;           // Delay in ms between readings

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(pump_pin, OUTPUT);
}

void pump() {
  pump_on = true;
  digitalWrite(pump_pin, HIGH);
}

void no_pump() {
  pump_on = false;
  digitalWrite(pump_pin, LOW);
}

void print_temps(float tank_temp, float collector_temp) {
  Serial.print("Tank: ");
  Serial.print(tank_temp);
  Serial.print(", Collector: ");
  Serial.print(collector_temp);
  Serial.println(" F");
}

// Main
void loop()
{
  sensors.requestTemperatures();
  float tank_temp = sensors.getTempF(tank_sensor);
  float collector_temp = sensors.getTempF(collector_sensor);

  print_temps(tank_temp, collector_temp);

  // Assume that very negative readings are errors
  if (tank_temp < -50 || collector_temp < -50) {
    Serial.println("Screwy reading, ignoring");
  }

  // If tank is hot enough, pump is off
  else if (tank_temp >= tank_max_temp) {
    Serial.println("Tank is over max temp, pump off");
    no_pump();
  }

  // If collector is cold, pump is off
  else if (collector_temp <= collector_min_temp) {
    Serial.println("Collector is under min temp, pump off");
    no_pump();
  }

  // If collector is significantly hotter thank tank, pump is on
  else if (collector_temp > tank_temp + on_threshold) {
    Serial.println("Collector is hotter than tank, pump on");
    pump();
  }

  // If collector is significantly colder than tank, pump is off
  else if (tank_temp > collector_temp + off_threshold) {
    Serial.println("Collector is colder than tank, pump off");
    no_pump();
  }

  // Otherwise, no change
  else {
  }

  delay(interval);
}

