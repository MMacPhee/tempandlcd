#include "global.h"


void write_button(int button, short value) {
  if (button == 0) {
    buttons.view = value;
  }
  else if (button == 1) {
    buttons.edit = value;
  }
  else if (button == 2) {
    buttons.up = value;
  }
  else if (button == 3) {
    buttons.down = value;
  }
  else if (button == 4) {
    buttons.start = value;
  }
  else{}
}

short read_button(int button) {
  if (button == 0) {
    return buttons.view;
  }
  else if (button == 1) {
    return buttons.edit;
  }
  else if (button == 2) {
    return buttons.up;
  }
  else if (button == 3) {
    return buttons.down;
  }
  else if (button == 4) {
    return buttons.start;
  }
  else
    return -1;
}

void write_probe_temp(short value) {
  probe_temp = value;
}

short read_probe_temp() {
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

