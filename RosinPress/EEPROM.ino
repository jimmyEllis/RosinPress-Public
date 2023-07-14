void WriteParamToEEPROM (void) {

  //Serial.println("\t TOP \t");
  EEPROM.put(KP_TOP, KpTop);
  //Serial.print("Kp written : \t"); Serial.println(KpTop);
  EEPROM.put(KI_TOP, KiTop);
  //Serial.print("Ki written : \t"); Serial.println(KiTop);
  EEPROM.put(KD_TOP, KdTop);
  //Serial.print("Kd written : \t"); Serial.println(KdTop);
  EEPROM.put(OUT_MIN_TOP, OutputMinTop);
  //Serial.print("out min written : \t"); Serial.println(OutputMinTop);
  EEPROM.put(OUT_MAX_TOP, OutputMaxTop);
  //Serial.print("out max written : \t"); Serial.println(OutputMaxTop);
  EEPROM.put(BANG_BANG_TOP, BangBangTop);
  //Serial.print("bangbang written : \t"); Serial.println(BangBangTop);
  EEPROM.put(HYST_TOP, HysteresisTop);
  //Serial.println("\n\t BOTTEM \t");
  EEPROM.put(KP_BTM, KpBtm);
  //Serial.print("Kp written : \t"); Serial.println(KpBtm);
  EEPROM.put(KI_BTM, KiBtm);
  //Serial.print("Ki written : \t"); Serial.println(KiBtm);
  EEPROM.put(KD_BTM, KdBtm);
  //Serial.print("Kd written : \t"); Serial.println(KdBtm);
  EEPROM.put(OUT_MIN_BTM, OutputMinBtm);
  //Serial.print("out min written : \t"); Serial.println(OutputMinBtm);
  EEPROM.put(OUT_MAX_BTM, OutputMaxBtm);
  //Serial.print("out max written : \t"); Serial.println(OutputMaxBtm);
  EEPROM.put(BANG_BANG_BTM, BangBangBtm);
  //Serial.print("bangbang written : \t"); Serial.println(BangBangBtm);
 EEPROM.put(HYST_BTM, HysteresisBtm);

}
void ReadParamFromEEPROM (void) {
  //Serial.println("\t TOP \t");
  EEPROM.get(KP_TOP, KpTop);
  //Serial.print("Kp read : \t"); Serial.println(KpTop);
  EEPROM.get(KI_TOP, KiTop);
  //Serial.print("Ki read : \t"); Serial.println(KiTop);
  EEPROM.get(KD_TOP, KdTop);
  //Serial.print("Kd read : \t"); Serial.println(KdTop);
  EEPROM.get(OUT_MIN_TOP, OutputMinTop);
  //Serial.print("out min read : \t"); Serial.println(OutputMinTop);
  EEPROM.get(OUT_MAX_TOP, OutputMaxTop);
  //Serial.print("out max read : \t"); Serial.println(OutputMaxTop);
  EEPROM.get(BANG_BANG_TOP, BangBangTop);
  //Serial.print("bangbang read : \t"); Serial.println(BangBangTop);
  EEPROM.get(HYST_TOP, HysteresisTop);
  //Serial.println("\n\t BOTTEM \t");
  EEPROM.get(KP_BTM, KpBtm);
  //Serial.print("Kp read : \t"); Serial.println(KpBtm);
  EEPROM.get(KI_BTM, KiBtm);
  //Serial.print("Ki read : \t"); Serial.println(KiBtm);
  EEPROM.get(KD_BTM, KdBtm);
  //Serial.print("Kd read : \t"); Serial.println(KdBtm);
  EEPROM.get(OUT_MIN_BTM, OutputMinBtm);
  //Serial.print("out min read : \t"); Serial.println(OutputMinBtm);
  EEPROM.get(OUT_MAX_BTM, OutputMaxBtm);
  //Serial.print("out max read : \t"); Serial.println(OutputMaxBtm);
  EEPROM.get(BANG_BANG_BTM, BangBangBtm);
  //Serial.print("bangbang read : \t"); Serial.println(BangBangBtm);
  EEPROM.get(HYST_BTM, HysteresisBtm);

}
void WriteSetpointToEEPROM (void) {
  //Serial.print("Kp written : "); Serial.print(SetPoint);
  //EEPROM.write(SETPOINT, SetPoint*100);
  EEPROM.put(SETPOINT, SetPoint);

}
void ReadSetpointFromEEPROM (void) {
  // SetPoint = EEPROM.read(SETPOINT)/100;
  EEPROM.get(SETPOINT, SetPoint);
 // Serial.print("Kp read : "); Serial.print(SetPoint);
}

void SetupEEPROM(void) {
  ReadSetpointFromEEPROM ();
  ReadParamFromEEPROM ();
}
