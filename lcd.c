#include <LiquidCrystal.h>
#include "global.h"
#include "lcd.h"


void start_lcd() {
  lcd.begin(16, 2);
}

void update_lcd(State state) {

  char* top_line = (char*)malloc(16*sizeof(char));
  char* bottom_line = (char*)malloc(16*sizeof(char));

  switch(state) {
    
    case STARTUP:
      top_line = "startup line 1";
      bottom_line = "startup line 2";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case DISPLAY_MASH:
      top_line = "display mash 1";
      bottom_line = "display mash 2";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case DISPLAY_FERM:
      top_line = "display ferm 1";
      bottom_line = "display ferm 2";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case EDIT_MASH:
      top_line = "edit mash 1";
      bottom_line = "edit mash 2";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case EDIT_FERM:
      top_line = "edit ferm 1";
      bottom_line = "edit ferm 2";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case PAUSE:
      top_line = "pause 1";
      bottom_line = "pause 2";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case SHUTDOWN:
      top_line = "shutdown 1";
      bottom_line = "shutdown 2";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;

    default:
      top_line = "missed a step";
      bottom_line = "fuck";
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
  }

  free(top_line);
  free(bottom_line);
  
}

