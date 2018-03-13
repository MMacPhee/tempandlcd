#define temp_knob 2
#define edit_btn 3
#define view_btn 4
#define start_btn 5
#define phase_swt 6
#define temp_sense 19

void startup();
char* display_mash(byte);
void display_ferm();
void edit_mash();
void edit_ferm();
void pause();
void shut_down();
char* print_temp(byte);
char* concat_string(char*, char*);

byte mash_target = 154;
byte ferm_target = 66;

typedef enum State {
  STARTUP,
  DISPLAY_MASH,
  DISPLAY_FERM,
  EDIT_MASH,
  EDIT_FERM,
  PAUSE,
  SHUTDOWN
} ;

void startup() {
  
}

char* display_mash(byte probe_temp) {

  return concat_string(concat_string(print_temp(probe_temp), " / "), print_temp(mash_target));
  
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

