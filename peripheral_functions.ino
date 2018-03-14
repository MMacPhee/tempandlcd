
float retrieve_temp() {
  float temp;
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  temp = (1.8 * temp) + 32;             // convert celcius to fahrenheit because that's how most brew temps are reported
  return(temp);
}


