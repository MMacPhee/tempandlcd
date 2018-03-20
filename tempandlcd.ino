#include <LiquidCrystal.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <math.h>
#include "global.h"
#include "state_machine.h"
#include "buttons.h"
#include "lcd.h"

#define temp_sense 19

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

float float_temp = 0;

OneWire oneWire(temp_sense);
DallasTemperature sensors(&oneWire);


void setup() {
  
  // set up the LCD's number of columns and rows:
  start_lcd();
  sensors.begin();
  Serial.begin(9600);

  pinMode(view_pin, INPUT);
  pinMode(edit_pin, INPUT);
  pinMode(up_pin, INPUT);
  pinMode(down_pin, INPUT);
  pinMode(start_pin, INPUT);

}

void loop() {
  
  float_temp = retrieve_temp();
  write_probe_temp(float_to_byte(float_temp));

  poll_buttons();
  update_state_machine();
  update_lcd(read_current_state());
  
}






