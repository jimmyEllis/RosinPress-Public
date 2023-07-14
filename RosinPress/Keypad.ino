void SetupKeypad (void) {
 // Serial.println("---------------------------------------");
  pinMode(UP, INPUT_PULLUP);
  attachPCINT(digitalPinToPCINT(UP), &UPfunc, CHANGE);  // add more attachInterrupt code as required
  pinMode(DN, INPUT_PULLUP);
  attachPCINT(digitalPinToPCINT(DN), &DNfunc, CHANGE);
  pinMode(LFT, INPUT_PULLUP);
  attachPCINT(digitalPinToPCINT(LFT), &LFTfunc, CHANGE);
  pinMode(RGT, INPUT_PULLUP);
  attachPCINT(digitalPinToPCINT(RGT), &RGTfunc, CHANGE);
  pinMode(OK, INPUT_PULLUP);
  attachPCINT(digitalPinToPCINT(OK), &OKfunc, CHANGE);
 // Serial.println("---------------------------------------");
}

bool ReadBtn(int btn) {
  if (!digitalRead(btn)) {
    delay(3);
    if (!digitalRead(btn)) {
      return true;
    }
  }
  return false;
}

void SaveConfig(void) {
  if (ReadBtn(LFT) && ReadBtn(RGT)) {
    WriteSetpointToEEPROM();
    ReadSetpointFromEEPROM();

    delay(1000);

    WriteParamToEEPROM ();
    ReadParamFromEEPROM ();

    delay(1000);
  }
}

void UpdateKeyDuration(void) {
  if (!digitalRead(UP)) {
    btnUpPressDur = millis() - btnUpPressTime;
   // Serial.print("btnUpPressDur "); Serial.print(btnUpPressDur / 1000, DEC); Serial.println("sec");
  }
  if (!digitalRead(DN)) {
    btnDownPressDur = millis() - btnDownPressTime;
  //  Serial.print("btnDownPressDur "); Serial.print(btnDownPressDur / 1000, DEC); Serial.println("sec");
  }
  if (!digitalRead(LFT)) {
    btnLeftPressDur = millis() - btnLeftPressTime;
  //  Serial.print("btnLeftPressDur "); Serial.print(btnLeftPressDur / 1000, DEC); Serial.println("sec");
  }
  if (!digitalRead(RGT)) {
    btnRightPressDur = millis() - btnRightPressTime;
 //   Serial.print("btnRightPressDur "); Serial.print(btnRightPressDur / 1000, DEC); Serial.println("sec");
  }
  if (!digitalRead(OK)) {
    btnOkPressDur = millis() - btnOkPressTime;
  //  Serial.print("btnOkPressDur "); Serial.print(btnOkPressDur / 1000, DEC); Serial.println("sec");
  }
}



//INTERRUPTS
void UPfunc() {
 // Serial.print("Up "); Serial.print(UP, DEC); Serial.println("!");
  if (digitalRead(UP)) {
    up = false;
    btnUpPressDur = millis() - btnUpPressTime;
   // Serial.print("btnUpPressDur "); Serial.print(btnUpPressDur / 1000, DEC); Serial.println("sec");
  }
  else {
    up = true;
    btnUpPressTime = millis();
  }
}
void DNfunc() {
 // Serial.print("Down "); Serial.print(DN, DEC); Serial.println("!");
  if (digitalRead(DN)) {
    down = false;
    btnDownPressDur = millis() - btnDownPressTime;
  //  Serial.print("btnDownPressDur "); Serial.print(btnDownPressDur / 1000, DEC); Serial.println("sec");
  }
  else {
    down = true;
    btnDownPressTime = millis();
  }
}
void LFTfunc() {
//  Serial.print("Left "); Serial.print(LFT, DEC); Serial.println("!");
  if (digitalRead(LFT)) {
    left = false;
    btnLeftPressDur = millis() - btnLeftPressTime;
 //   Serial.print("btnLeftPressDur "); Serial.print(btnLeftPressDur / 1000, DEC); Serial.println("sec");
  }
  else {
    left = true;
    btnLeftPressTime = millis();
  }
}
void RGTfunc() {
 // Serial.print("Right "); Serial.print(RGT, DEC); Serial.println("!");
  if (digitalRead(RGT)) {
    right = false;
    btnRightPressDur = millis() - btnRightPressTime;
  //  Serial.print("btnRightPressDur "); Serial.print(btnRightPressDur / 1000, DEC); Serial.println("sec");
  }
  else {
    right = true;
    btnRightPressTime = millis();
  }
}
void OKfunc() {
//  Serial.print("Ok "); Serial.print(OK, DEC); Serial.println("!");
  if (digitalRead(OK)) {
    ok = false;
    btnOkPressDur = millis() - btnOkPressTime;
//    Serial.print("btnOkPressDur "); Serial.print(btnOkPressDur / 1000, DEC); Serial.println("sec");
  }
  else {
    ok = true;
    btnOkPressTime = millis();
  }
}
