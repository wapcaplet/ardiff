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

// For Adafruit LCD shield
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <Adafruit_RGBLCDShield.h>

// Digital pin to use for the 1-wire sensor bus
#define ONE_WIRE_BUS 11

// Initialize OneWire
OneWire one_wire(ONE_WIRE_BUS);
DallasTemperature sensors(&one_wire);

// Initialize LCD
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

// OneWire Sensor addresses
// The real ones
DeviceAddress tank_sensor = { 0x28, 0x95, 0xD2, 0xCE, 0x03, 0x00, 0x00, 0x51 };
DeviceAddress collector_sensor = { 0x28, 0xD4, 0xD3, 0xCE, 0x03, 0x00, 0x00, 0xDE };
// The other ones
//DeviceAddress tank_sensor = { 0x28, 0x04, 0xCC, 0xCE, 0x03, 0x00, 0x00, 0x09 };
//DeviceAddress collector_sensor = { 0x28, 0x0C, 0xFC, 0xCE, 0x03, 0x00, 0x00, 0x2C };


int pump_pin = 12;
boolean pump_on = false;

float tank_max_temp = 140;      // Deg. F; above this, pump is off
float collector_min_temp = 40;  // Deg. F; below this, pump is off
float on_threshold = 30;        // Deg. F differential before pump turns on
float off_threshold = 15;       // Deg. F differential before pump turns off
int interval = 10000;           // Delay in ms between readings

/*
 * setup() - this function runs once when you turn your Arduino on
 * We initialize the serial connection with the computer
 */
void setup()
{
  Serial.begin(9600);
  sensors.begin();
  pinMode(pump_pin, OUTPUT);
  lcd.begin(16, 2);
  lcd.setBacklight(YELLOW);
  lcd.setCursor(0, 0);
  lcd.print("Waiting for");
  lcd.setCursor(0, 1);
  lcd.print("valid data ...");
}

void pump() {
  pump_on = true;
  digitalWrite(pump_pin, HIGH);
  lcd.setBacklight(RED);
}

void no_pump() {
  pump_on = false;
  digitalWrite(pump_pin, LOW);
  lcd.setBacklight(BLUE);
}

void print_temps(float tank_temp, float collector_temp) {
  Serial.print(tank_temp);
  Serial.print(", ");
  Serial.println(collector_temp);
}

void lcd_print_temps(float tank_temp, float collector_temp) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Coll: ");
  lcd.print(collector_temp);
  lcd.setCursor(0, 1);
  lcd.print("Tank: ");
  lcd.print(tank_temp);
}

// Main
void loop()
{
  sensors.requestTemperatures();
  float tank_temp = sensors.getTempF(tank_sensor);
  float collector_temp = sensors.getTempF(collector_sensor);

  print_temps(tank_temp, collector_temp);
  lcd_print_temps(tank_temp, collector_temp);

  // Assume that very negative readings are errors
  if (tank_temp < -50 || collector_temp < -50) {
    //Serial.println("# Screwy reading, ignoring");
  }

  else {

    // If tank is hot enough, pump is off
    if (tank_temp >= tank_max_temp) {
      //Serial.println("# Tank is over max temp, pump off");
      no_pump();
    }

    // If collector is cold, pump is off
    else if (collector_temp <= collector_min_temp) {
      //Serial.println("# Collector is under min temp, pump off");
      no_pump();
    }

    // If collector is significantly hotter thank tank, pump is on
    else if (collector_temp > tank_temp + on_threshold) {
      //Serial.println("# Collector is hotter than tank, pump on");
      pump();
    }

    // If collector is significantly colder than tank, pump is off
    else if (collector_temp < tank_temp + off_threshold) {
      //Serial.println("# Collector is colder than tank, pump off");
      no_pump();
    }

    // Otherwise, no change
    else {
    }
  }

  delay(interval);
}

