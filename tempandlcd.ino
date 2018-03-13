#include <LiquidCrystal.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <math.h>
#include </Users/malcolmmacphee/Google Drive/tempandlcd/header.h>


char* print_str;
byte probe_temp;

float float_temp = 0;
byte byte_temp = 0;
byte buttons[5];
State state = STARTUP;
State next_state = DISPLAY_MASH;

OneWire oneWire(temp_sense);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  sensors.begin();
  Serial.begin(9600);

  pinMode(temp_knob, INPUT);
  pinMode(edit_btn, INPUT);
  pinMode(view_btn, INPUT);
  pinMode(start_btn, INPUT);
  pinMode(phase_swt, INPUT);

  print_str = print_temp(probe_temp);

}

void loop() {
  
  float_temp = retrieve_temp();
  probe_temp = float_to_byte(float_temp);
  update_lcd(print_str);

  buttons[0] = digitalRead(temp_knob);
  Serial.print("Button 1 is: ");
  Serial.println(buttons[0]);
  lcd.setCursor(11, 1);
  if (buttons[0] == HIGH)
    lcd.print(1);
  else
    lcd.print(0);
    
  buttons[1] = digitalRead(edit_btn);
  lcd.setCursor(12, 1);
  Serial.print("Button 2 is: ");
  Serial.println(buttons[1]);
  if (buttons[1] == HIGH)
    lcd.print(1);
  else
    lcd.print(0); 
     
  buttons[2] = digitalRead(view_btn);
  Serial.print("Button 3 is: ");
  Serial.println(buttons[2]);
  lcd.setCursor(13, 1);
  if (buttons[2] == HIGH)
    lcd.print(1);
  else
    lcd.print(0);
    
  buttons[3] = digitalRead(start_btn);
  Serial.print("Button 4 is: ");
  Serial.println(buttons[3]);
  lcd.setCursor(14, 1);
  if (buttons[3] == HIGH)
    lcd.print(1);
  else
    lcd.print(0);
    
  buttons[4] = digitalRead(phase_swt);
  Serial.print("Button 5 is: ");
  Serial.println(buttons[4]);
  lcd.setCursor(15, 1);
  if (buttons[4] == HIGH)
    lcd.print(1);
  else
    lcd.print(0);

  switch(state) {
    
    case STARTUP:
      startup();
      Serial.println("startup");
      if(buttons[4] == 0)
        next_state = DISPLAY_MASH;
      else
        next_state = DISPLAY_FERM;
      break;
      
    case DISPLAY_MASH:
      print_str = display_mash(probe_temp);
      Serial.println("display mash");
      if(buttons[1] == 1)
        next_state = EDIT_MASH;
      break;
      
    case DISPLAY_FERM:
      display_ferm();
      Serial.println("display ferm");
      if(buttons[1] == 1)
        next_state = EDIT_FERM;
      break;
      
    case EDIT_MASH:
      edit_mash;
      Serial.println("edit mash");
      if(buttons[1] == 0)
        next_state = DISPLAY_MASH;
      break;
      
    case EDIT_FERM:
      edit_ferm;
      Serial.println("edit ferm");
      if(buttons[1] == 0)
        next_state = DISPLAY_FERM;
      break;
      
    case PAUSE:
      pause();
      Serial.println("pause");
      //
      break;
      
    case SHUTDOWN:
      shut_down();
      Serial.println("shutdown");
      //
      break;

    default:
      Serial.println("default case");
      break;
  }

  state = next_state;
  
  delay(500);
}



