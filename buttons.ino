#include "global.h"
#include "buttons.h"


void poll_buttons() {

  short buttons[5];

  buttons[0] = digitalRead(view_pin);
    Serial.print("Button 1 is: ");
    Serial.println(buttons[0]);
    lcd.setCursor(11, 1);
      
    buttons[1] = digitalRead(edit_pin);
    Serial.print("Button 2 is: ");
    Serial.println(buttons[1]);
       
    buttons[2] = digitalRead(up_pin);
    Serial.print("Button 3 is: ");
    Serial.println(buttons[2]);
      
    buttons[3] = digitalRead(down_pin);
    Serial.print("Button 4 is: ");
    Serial.println(buttons[3]);
      
    buttons[4] = digitalRead(start_pin);
    Serial.print("Button 5 is: ");
    Serial.println(buttons[4]);

    write_button(0, buttons[0]);
    write_button(1, buttons[1]);
    write_button(2, buttons[2]);
    write_button(3, buttons[3]);
    write_button(4, buttons[4]);

}
