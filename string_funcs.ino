#include <String.h>

char* concat_string ( char *a, char *b ) {
  //char *result = (char*)malloc( strlen(a) + strlen(b) + 1 );
  char result[16];
  //char *result;

  strcpy( result, a );
  strcat( result, b );

  //free(temp);
  return result;
}


byte float_to_byte( float x ) {

  byte result;
  int tmp = round(x);
  
  if ( tmp > 255 || tmp < 0 ) {
    result = -1;
  }

  else
    result = (byte)tmp;

  return result;
  
}

char* print_temp( byte x ) {
  char *number = (char*)malloc(3*sizeof(char));
  char string[64];
  
  if ( x/100 != 0 ) {
    *(number) = x/100;
    *(number+1) = (x%100)/10;
    *(number+2) = (x%100)%10;
    sprintf(string, "%x%x%x F", *(number), *(number+1), *(number+2));
  }
  else if ( x/10 != 0 ) {
    *(number) = x/10;
    *(number+1) = x%10;
    sprintf(string, "%x%x F", *(number), *(number+1));
  }
  else {
    *(number) = x;
    sprintf(string, "%x F", *(number));
  }
  free(number);
  return string;
}







