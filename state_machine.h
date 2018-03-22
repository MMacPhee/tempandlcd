#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H 


#include "global.h"

void update_super_state_machine();
void update_state_machine();

void startup();
void alarm_check();
void pause();
void shut_down();

void display_mash();
void display_ferm();
void edit_mash();
void edit_ferm();

#endif
