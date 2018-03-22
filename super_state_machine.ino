#include "global.h"
#include "state_machine.h"

void update_state_super_machine() {

  SuperState state = read_current_super_state();
  SuperState next_super_state = read_current_super_state();
  SuperState previous_super_state = read_previous_super_state();
  
  short start_btn = read_button(4);

  switch(state) {
    
    case STARTUP:
      startup();
      Serial.println("startup");
      next_super_state = ALARM_CHECK;
      break;

    case ALARM_CHECK:
      alarm_check();
      Serial.println("alarm_check");
      if (start_btn == 1 ) {
        previous_super_state = current_super_state;
        next_super_state = PAUSE;
      }
      else
        next_super_state = ALARM_CHECK;
      break;
      
    case PAUSE:
      pause();
      if (start_btn == 1)
        next_super_state = PAUSE;
      else if (start_btn == 0)
        next_super_state = previous_super_state;
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

  write_current_super_state(next_super_state);
  write_previous_super_state(previous_super_state);
  
}

void startup() {
  delay(1000);
}

void alarm_check() {
  State current_state = read_current_state();
  short probe_temp = read_probe_temp();
  short mash_target = read_mash_target();
  short ferm_target = read_ferm_target();

  if ((current_state == DISPLAY_MASH || current_state == EDIT_MASH) && probe_temp >= mash_target)
    enable_buzzer();
  else 
    disable_buzzer();
  
}

void pause() {
  // i guess do fuck all
  disable_buzzer();
}

void shut_down() {
  // look at going into power saving mode and waking into startup
}
