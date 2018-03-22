
float retrieve_temp() {
  float temp;
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  temp = (1.8 * temp) + 32;             // convert celcius to fahrenheit because that's how most brew temps are reported
  return(temp);
}

void trigger_buzzer() {
  if (buzzer_enable == 1)
    analogWrite(9, 127);
  else
    analogWrite(9, 0);
}

