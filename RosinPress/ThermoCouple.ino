void SetupTC(void){
  pinMode(CS_PIN_BTM,OUTPUT);
  pinMode(CS_PIN_TOP,OUTPUT);
}
double ReadTemperature(bool top) {
  double temperature;

  if (top) {
    temperature = TopTempCtr.read_temp();
  }
  else {
    temperature = BtmTempCtr.read_temp();
  }
  
  if (temperature < 0) {
    // If there is an error with the TC, temperature will be < 0
    Serial.print("Thermocouple Error on CS");
    Serial.println( temperature );
    TC_Error = true;
    return 9999; //Return very high temp so heaters will turn off

  } else {
    TC_Error = false;
    return temperature;
  }


}
