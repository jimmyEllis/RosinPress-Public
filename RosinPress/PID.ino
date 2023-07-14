void SetupPid(void) {
  pinMode(OUTPUT_PIN_TOP, OUTPUT);
  pinMode(OUTPUT_PIN_BTM, OUTPUT);
  pinMode(RDY_LED_PIN, OUTPUT);

  //if temperature is more than 4 degrees below or above setpoint, OUTPUT will be set to min or max respectively
  TopPID.setBangBang(BangBangTop);
  BtmPID.setBangBang(BangBangBtm);
  //set PID update interval to 4000ms
  TopPID.setTimeStep(1000);
  BtmPID.setTimeStep(1000);
}
void RunPID(bool err) {
  if (err) {
    TopPID.stop();
    BtmPID.stop();
    analogWrite(OUTPUT_PIN_TOP, 0);
    analogWrite(OUTPUT_PIN_BTM, 0);
  }
  else {
    TopPID.run(); //call every loop, updates automatically at certain time interval
    BtmPID.run(); //call every loop, updates automatically at certain time interval
    analogWrite(OUTPUT_PIN_TOP, OutputValTop);
    analogWrite(OUTPUT_PIN_BTM, OutputValBtm);
  }

 
  
}
