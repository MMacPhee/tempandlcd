#include </Users/malcolmmacphee/Google Drive/tempandlcd/global.h>

void update_state_machine() {

  State state = read_curent_state();
  State next_state = state;
  
  bool view_btn = read_btn("view");
  bool edit_btn = read_btn("edit");
  bool up_btn = read_btn("up");
  bool down_btn = read_btn("down");
  bool start_btn = read_btn("start");

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


