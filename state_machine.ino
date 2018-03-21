#include "global.h"
#include "state_machine.h"

void update_state_machine() {

  State state = read_current_state();
  State next_state = read_current_state();
  
  short view_btn = read_button("view");
  short edit_btn = read_button("edit");
  short up_btn = read_button("up");
  short down_btn = read_button("down");
  short start_btn = read_button("start");

  switch(state) {
    
    case STARTUP:
      startup();
      Serial.println("startup");
      if(view_btn == 0)
        next_state = DISPLAY_MASH;
      else
        next_state = DISPLAY_FERM;
      break;
      
    case DISPLAY_MASH:
      display_mash();
      Serial.println("display mash");
      if(edit_btn == 1)
        next_state = EDIT_MASH;
      else if(view_btn == 1)
        next_state = DISPLAY_FERM;
      break;
      
    case DISPLAY_FERM:
      display_ferm();
      Serial.println("display ferm");
      if(edit_btn == 1)
        next_state = EDIT_FERM;
      break;
      
    case EDIT_MASH:
      edit_mash();
      Serial.println("edit mash");
      if(edit_btn == 0)
        next_state = DISPLAY_MASH;
      break;
      
    case EDIT_FERM:
      edit_ferm();
      Serial.println("edit ferm");
      if(edit_btn == 0)
        next_state = DISPLAY_FERM;
      break;
      
    case PAUSE:
      pause();
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
  
}

void startup() {
  
}

void display_mash() {

}

void display_ferm() {
  
}

void edit_mash() {
  
}

void edit_ferm() {
  
}

void pause() {
  
}

void shut_down() {
  
}


