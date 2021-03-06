#include "global.h"
#include "state_machine.h"

void update_state_machine() {

  State state = read_current_state();
  State next_state = read_current_state();
  State previous_state = read_previous_state();
  
  short view_btn = read_button(0);
  short edit_btn = read_button(1);
  short up_btn = read_button(2);
  short down_btn = read_button(3);
  short start_btn = read_button(4);

  switch(state) {
    
    case STARTUP:
      startup();
      Serial.println("startup");
      if (view_btn == 0)
        next_state = DISPLAY_MASH;
      else if (view_btn == 1)
        next_state = DISPLAY_FERM;
      else
        Serial.println("startup directions not working");
      break;
      
    case DISPLAY_MASH:
      display_mash();
      Serial.println("display mash");
      if (start_btn == 1 ) {
        previous_state = DISPLAY_MASH;
        next_state = PAUSE;
      }

      else {
        if(edit_btn == 1 && view_btn == 0)
          next_state = EDIT_MASH;
        else if(view_btn == 1)
          next_state = DISPLAY_FERM;
        else if (view_btn == 0)
          next_state = DISPLAY_MASH;
        else
          Serial.println("display mash directions not working");
      }
      break;
      
    case DISPLAY_FERM:
      display_ferm();
      Serial.println("display ferm");
      if (start_btn == 1) {
        previous_state = DISPLAY_FERM;
        next_state = PAUSE;
      }

      else {
        if(edit_btn == 1 && view_btn == 1)
          next_state = EDIT_FERM;
        else if(view_btn == 1)
          next_state = DISPLAY_FERM;
        else if (view_btn == 0)
          next_state = DISPLAY_MASH;
        else
          Serial.println("display ferm directions not working");
      }
      break;
      
    case EDIT_MASH:
      edit_mash();
      Serial.println("edit mash");
      if (start_btn == 1) {
        previous_state = EDIT_MASH;
        next_state = PAUSE;
      }

      else {
        if (edit_btn == 1)
          next_state = EDIT_MASH;
        else if (edit_btn == 0)
          next_state = DISPLAY_MASH;
        else
          Serial.println("edit mash directions not working");
      }
      break;
      
    case EDIT_FERM:
      edit_ferm();
      Serial.println("edit ferm");
      if (start_btn == 1) {
        previous_state = EDIT_FERM;
        next_state = PAUSE;
      }

      else {
        if (edit_btn == 1)
          next_state = EDIT_FERM;
        else if (edit_btn == 0)
          next_state = DISPLAY_FERM;
        else
          Serial.println("edit ferm directions not working");
      }
      break;
      
    case PAUSE:
      pause();
      if (start_btn == 1 )
        next_state = PAUSE;
      else if (start_btn == 0)
        next_state = previous_state;
      else
        Serial.println("pause directions not working");
      
      Serial.println("pause");
      break;
      
    case SHUTDOWN:
      shut_down();
      Serial.println("shutdown");
      break;

    default:
      Serial.println("default case");
      break;
  }

  write_current_state(next_state);
  write_previous_state(previous_state);
  
}

void startup() {
  delay(1000);
}

void display_mash() {

}

void display_ferm() {
  
}

void edit_mash() {

  short up_btn = read_button(2);
  short down_btn = read_button(3);

  if (up_btn == 1 && down_btn == 0)
    inc_mash_target();

  if (up_btn == 0 && down_btn == 1)
    dec_mash_target();
  
}

void edit_ferm() {

  short up_btn = read_button(2);
  short down_btn = read_button(3);

  if (up_btn == 1 && down_btn == 0)
    inc_ferm_target();

  if (up_btn == 0 && down_btn == 1)
    dec_ferm_target();
  
}

void pause() {
  // i guess do fuck all
}

void shut_down() {
  // look at going into power saving mode and waking into startup
}


