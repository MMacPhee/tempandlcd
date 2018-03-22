#ifndef GLOBAL_H
#define GLOBAL_H


typedef struct Buttons{
  short view;
  short edit;
  short up;
  short down;
  short start;
} Buttons;

typedef enum State {
  STARTUP,
  DISPLAY_MASH,
  DISPLAY_FERM,
  EDIT_MASH,
  EDIT_FERM,
  PAUSE,
  SHUTDOWN
} State;

typedef enum SuperState {
  STARTUP,
  ALARM,
  NOT_ALARM,
  PAUSE,
  SHUTDOWN
} SuperState;

Buttons buttons = {.view = 0, .edit = 0, .up = 0, .down = 0, .start = 0};

short probe_temp = 0;
short mash_target = 154;
short ferm_target = 66;

short buzzer_enable = 0;

State current_state = DISPLAY_MASH;
SuperState current_super_state = STARTUP;
SuperState previous_super_state = STARTUP;

void write_button(int button, short value);
short read_button(int button);

void write_probe_temp(short value);
short read_probe_temp();

short read_mash_target();
void inc_mash_target();
void dec_mash_target();

short read_ferm_target();
void inc_ferm_target();
void dec_ferm_target();

void enable_buzzer();
void disable_buzzer();

void write_current_state(State state);
State read_current_state();

void write_current_super_state(SuperState state);
SuperState read_current_super_state();

void write_previous_super_state(SuperState state);
SuperState read_previous_super_state();

#endif
