#include "global.h"
#include "lcd.h"


void start_lcd() {
  lcd.begin(16, 2);
}

void update_lcd(State state) {

  short probe_temp = read_probe_temp();
  short mash_target = read_mash_target();
  short ferm_target = read_ferm_target();

  char top_line[16];
  char bottom_line[16];

  switch(state) {
    
    /*case STARTUP:
      strcpy(top_line, "startup line 1");
      strcpy(bottom_line, "startup line 2");
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;*/
      
    case DISPLAY_MASH:
      strcpy(top_line, "Mash Monitor:");
      strcpy(bottom_line, print_temp(probe_temp));
      strcat(bottom_line, " / ");
      strcat(bottom_line, print_temp(mash_target));
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case DISPLAY_FERM:
      strcpy(top_line, "Ferm Monitor:");
      strcpy(bottom_line, print_temp(probe_temp));
      strcat(bottom_line, " / ");
      strcat(bottom_line, print_temp(ferm_target));
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case EDIT_MASH:
      strcpy(top_line, "Edit Mash:");
      strcpy(bottom_line, print_temp(probe_temp));
      strcat(bottom_line, " / ");
      strcat(bottom_line, print_temp(mash_target));
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    case EDIT_FERM:
      strcpy(top_line, "Edit Ferm:");
      strcpy(bottom_line, print_temp(probe_temp));
      strcat(bottom_line, " / ");
      strcat(bottom_line, print_temp(ferm_target));
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(top_line);
      lcd.setCursor(0, 1);
      lcd.print(bottom_line);
      delay(100);
      break;
      
    /*case PAUSE:
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
      break;*/

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

