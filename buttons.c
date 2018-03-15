#include "global.h"
#include "buttons.h"


void poll_buttons() {

  short buttons[5];

  buttons[0] = digitalRead(view_btn);
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
       
    buttons[2] = digitalRead(up_btn);
    Serial.print("Button 3 is: ");
    Serial.println(buttons[2]);
    lcd.setCursor(13, 1);
    if (buttons[2] == HIGH)
      lcd.print(1);
    else
      lcd.print(0);
      
    buttons[3] = digitalRead(down_btn);
    Serial.print("Button 4 is: ");
    Serial.println(buttons[3]);
    lcd.setCursor(14, 1);
    if (buttons[3] == HIGH)
      lcd.print(1);
    else
      lcd.print(0);
      
    buttons[4] = digitalRead(start_btn);
    Serial.print("Button 5 is: ");
    Serial.println(buttons[4]);
    lcd.setCursor(15, 1);
    if (buttons[4] == HIGH)
      lcd.print(1);
    else
      lcd.print(0);

    void write_btn("view", buttons[0]);
    void write_btn("edit", buttons[1]);
    void write_btn("up", buttons[2]);
    void write_btn("down", buttons[3]);
    void write_btn("start", buttons[4]);

}
