#include <LiquidCrystal.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <math.h>
#include </Users/malcolmmacphee/Google Drive/tempandlcd/global.h>
#include </Users/malcolmmacphee/Google Drive/tempandlcd/state_machine.h>
#include </Users/malcolmmacphee/Google Drive/tempandlcd/buttons.h>
#include </Users/malcolmmacphee/Google Drive/tempandlcd/lcd.h>

#define temp_sense 19


float float_temp = 0;

OneWire oneWire(temp_sense);
DallasTemperature sensors(&oneWire);

void setup() {
  
  // set up the LCD's number of columns and rows:
  start_lcd();
  sensors.begin();
  Serial.begin(9600);

  pinMode(view_btn, INPUT);
  pinMode(edit_btn, INPUT);
  pinMode(up_btn, INPUT);
  pinMode(down_btn, INPUT);
  pinMode(start_btn, INPUT);

}

void loop() {
  
  float_temp = retrieve_temp();
  write_probe_temp(float_to_byte(float_temp));

  poll_buttons();
  update_state_machine();
  update_lcd(read_current_state());
  
}



