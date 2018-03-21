#include "global.h"
#include "lcd.h"


void start_lcd() {
  lcd.begin(16, 2);
}

void update_lcd(State state) {

  char top_line[16];
  char bottom_line[16];

  switch(state) {
    
    case STARTUP:
      strcpy(top_line, "startup line 1");
      strcpy(bottom_line, "startup line 2");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case DISPLAY_MASH:
      strcpy(top_line, "display mash 1");
      strcpy(bottom_line, "display mash 2");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case DISPLAY_FERM:
      strcpy(top_line, "display ferm 1");
      strcpy(bottom_line, "display ferm 2");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case EDIT_MASH:
      strcpy(top_line, "edit mash 1");
      strcpy(bottom_line, "edit mash 2");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case EDIT_FERM:
      strcpy(top_line, "edit ferm 1");
      strcpy(bottom_line, "edit ferm 2");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case PAUSE:
      strcpy(top_line, "pause line 1");
      strcpy(bottom_line, "pause line 2");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case SHUTDOWN:
      strcpy(top_line, "shutdown line 1");
      strcpy(bottom_line, "shutdown line 2");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;

    default:
      strcpy(top_line, "missed a step");
      strcpy(bottom_line, "fuck");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
  }
  
}

