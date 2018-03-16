void guts(char* print_str, byte* probe_temp) {
  float_temp = retrieve_temp();
  probe_temp = float_to_byte(float_temp);
  update_lcd(print_temp(byte_temp));
//  button_check();
}

