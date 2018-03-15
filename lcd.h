#ifndef LCD_H
#define LCD_H

#include <LiquidCrystal.h>
//#include </Users/malcolmmacphee/Google Drive/tempandlcd/global.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void start_lcd();

void update_lcd(State state);
  
#endif

