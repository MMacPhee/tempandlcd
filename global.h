
typedef struct Buttons{
  bool view;
  bool edit;
  bool up;
  bool down;
  bool start;
} Buttons;

typedef enum State {
  STARTUP,
  DISPLAY_MASH,
  DISPLAY_FERM,
  EDIT_MASH,
  EDIT_FERM,
  PAUSE,
  SHUTDOWN
} ;

Buttons buttons = {.view = 0, .edit = 0, .up = 0, .down = 0, .start = 0};

byte probe_temp = 0;
byte mash_target = 154;
byte ferm_target = 66;

State current_state = STARTUP;
State next_state = STARTUP;

void write_button(char *button, bool value) {
  if (button == "view") {
    buttons.view = value;
  }
  else if (button == "edit") {
    buttons.edit = value;
  }
  else if (button == "up") {
    buttons.up = value;
  }
  else if (button == "down") {
    buttons.down = value;
  }
  else if (button == "start") {
    buttons.start = value;
  }
  else{}
}

bool read_button(char *button) {
  if (button == "view") {
    return buttons.view;
  }
  else if (button == "edit") {
    return buttons.edit;
  }
  else if (button == "up") {
    return buttons.up;
  }
  else if (button == "down") {
    return buttons.down;
  }
  else if (button == "start") {
    return buttons.start;
  }
  else
    return -1;
}

void write_probe_temp(byte value) {
  probe_temp = value;
}

byte read_probe_temp() {
  return probe_temp;
}

void inc_mash_target() {
  if (mash_target < 254) {
    mash_target++;
  }
  else{}
}

void dec_mash_target() {
  if (mash_target > 1) {
    mash_target--;
  }
  else{}
}

void inc_ferm_target() {
  if (ferm_target < 254) {
    ferm_target++;
  }
  else{}
}

void dec_ferm_target() {
  if (ferm_target > 1) {
    ferm_target--;
  }
  else{}
}

void write_current_state(State state) {
  current_state = state;
}

State read_current_state() {
  return current_state;
}

void write_next_state(State state) {
  next_state = state;
}

State read_next_state() {
  return next_state;
}

