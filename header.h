#define view_btn 2
#define edit_btn 3
#define up_btn 4
#define down_btn 5
#define start_btn 6
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

  char* str = (char*)(malloc(16*sizeof(char)));
  str = concat_string(print_temp(probe_temp), " / ");
  str = concat_string(str, print_temp(mash_target));

  return str;
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

