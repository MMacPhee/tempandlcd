void update_lcd(char* str) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(str);
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
}


float retrieve_temp() {
  float temp;
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  temp = (1.8 * temp) + 32;             // convert celcius to fahrenheit because that's how most brew temps are reported
  return(temp);
}

byte* button_check(byte* buttons) {

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

  return *buttons;
}

