// return 1 = change, return 0 = ready, return -1 = do nothing
int SetFloatValue(double& value, String unit, double min, double max, int interval = 2500, int precision = 4, double incr1 = 0.0001, double incr2 = 0.001, double incr3 = 0.01, double incr4 = 0.1, double incr5 = 1 ) {
  static int step = 0;
  static bool init = false;

  Serial.print("value "); Serial.println(value, 4);
  Serial.print("step "); Serial.println(step);


  switch (step) {
    case 0:  //Select direction
      if (!init) {
        display.clearDisplay();
        writeDoubleToDisplay(value, 3, 10, 0, false, precision);
        writeTextToDisplay(unit, 3, 100, 0, false);
        display.display();
        init = true;
      }
      else if (up) {
        step = 10;
        init = false;
      }
      else if (down) {
        step = 20;
        init = false;
      }
      else if ((left && btnLeftPressDur >= 500) || (right && btnRightPressDur >= 500)) {
        init = false;
        return 0;
      }
      break;

    case 10:  //Increment by "incr1"
      if (!init) {
        display.clearDisplay();
        writeDoubleToDisplay(value, 3, 10, 0, false, precision);
        writeTextToDisplay(unit, 3, 100, 0, false);
        display.display();
        init = true;
      }
      if (!up) {
        step = 0;
        init = false;
      }

      else if (btnUpPressDur <= interval)  {
        if (value <= max - incr1) {
          value += incr1;
        }
        else {
          value = max;
        }
        init = false;
      }
      else {
        step = 11;
        init = false;
      }
      return 1;
      break;

    case 11:  //Increment by "incr2"
      if (!init) {
        display.clearDisplay();
        writeDoubleToDisplay(value, 3, 10, 0, false, precision);
        writeTextToDisplay(unit, 3, 100, 0, false);
        display.display();
        init = true;
      }
      if (!up) {
        step = 0;
        init = false;
      }
      else if (btnUpPressDur <= 2 * interval) {
        if (value <= max - incr2) {
          value += incr2;
          init = false;
        }
        else {
          value = max;
        }
      }
      else {
        step = 12;
        init = false;
      }
      return 1;
      break;

    case 12:  //Increment by "incr3"
      if (!init) {
        display.clearDisplay();
        writeDoubleToDisplay(value, 3, 10, 0, false, precision);
        writeTextToDisplay(unit, 3, 100, 0, false);
        display.display();
        init = true;
      }
      if (!up) {
        step = 0;
        init = false;
      }
      else if (btnUpPressDur <= 3 * interval) {
        if (value <= max - incr3) {
          value += incr3;
          init = false;
        }
        else {
          value = max;
        }
      }
      else {
        step = 13;
        init = false;
      }
      return 1;
      break;

    case 13:  //Increment by "incr4"
      if (!init) {
        display.clearDisplay();
        writeDoubleToDisplay(value, 3, 10, 0, false, precision);
        writeTextToDisplay(unit, 3, 100, 0, false);
        display.display();
        init = true;
      }
      if (!up) {
        step = 0;
        init = false;
      }
      else  {
        if (value <= max - incr4) {
          value += incr4;
          init = false;
        }
        else {
          value = max;
        }
      }
      return 1;
      break;

    case 20:  //Decrement by "incr1"
      if (!init) {
        display.clearDisplay();
        writeDoubleToDisplay(value, 3, 10, 0, false, precision);
        writeTextToDisplay(unit, 3, 100, 0, false);
        display.display();
        init = true;
      }
      if (!down) {
        step = 0;
        init = false;
      }
      else if (btnDownPressDur <= interval) {
        if (value >= min + incr1) {
          value -= incr1;
          init = false;
        }
        else {
          value = min;
        }
      }
      else {
        step = 21;
        init = false;
      }
      return 1;
      break;

    case 21:  //Decrement by "incr2"
      if (!init) {
        display.clearDisplay();
        writeDoubleToDisplay(value, 3, 10, 0, false, precision);
        writeTextToDisplay(unit, 3, 100, 0, false);
        display.display();
        init = true;
      }
      if (!down) {
        step = 0;
        init = false;
      }
      else if (btnDownPressDur <= 2 * interval) {
        if (value >= min + incr2) {
          value -= incr2;
          init = false;
        }
        else {
          value = min;
        }
      }
      else {
        step = 22;
        init = false;
      }
      return 1;
      break;

    case 22:  //Decrement by "incr3"
      if (!init) {
        display.clearDisplay();
        writeDoubleToDisplay(value, 3, 10, 0, false, precision);
        writeTextToDisplay(unit, 3, 100, 0, false);
        display.display();
        init = true;
      }
      if (!down) {
        step = 0;
        init = false;
      }
      else if (btnDownPressDur <= 3 * interval) {
        if (value >= min + incr3) {
          value -= incr3;
          init = false;
        }
        else {
          value = min;
        }
      }
      else {
        step = 23;
        init = false;
      }
      return 1;
      break;

    case 23:  //Decrement by "incr4"
      if (!init) {
        display.clearDisplay();
        writeDoubleToDisplay(value, 3, 10, 0, false, precision);
        writeTextToDisplay(unit, 3, 100, 0, false);
        display.display();
        init = true;
      }
      if (!down) {
        step = 0;
        init = false;
      }
      else  {
        if (value >= min + incr4) {
          value -= incr4;
          init = false;
        }
        else {
          value = min;
        }
      }
      return 1;
      break;
  }
  return -1;
}
void HandleSetpoint(void) {




  static int step = 0;

  if (ok || (millis() - SetpointStartTime >= SetpointDisplTime)) {
    SetpointActive = false;
    WriteSetpointToEEPROM ();
    step = 0;
  }

  if (up || down || left || right || ok) {
    SetpointStartTime = millis();
  }

  switch (step) {
    //Edit setpoint
    case 0:
      if ((up || down) && !MenuActive) {
        step = 1;
        SetpointActive = true;
      }
      break;
    //Select direction
    case 1:
      SetFloatValue(SetPoint, "C", 0, 300, 5000, 0, 1, 10, 100, 100);
      break;
  }
}

void HandleMenu(void) {
  static int step;
  static bool init = false;
  static bool top_bottem = true;
  static int paramPointer = 1, framePointer = 1;


  if (MenuActive && ((ok && btnOkPressDur > 5000) || (millis() - MenuStartTime >= MenuDisplTime))) {
    MenuActive = false;
    WriteParamToEEPROM ();
    step = 0;
  }

  if (up || down || left || right || ok) {
    MenuStartTime = millis();
  }

  switch (step) {
    //Edit setpoint
    case 0:
      if (ok) {
        step = 1;
        MenuActive = true;
      }
      break;

    //Select controller TOP/BOTTEM
    case 1:
      if (!init) {
        display.clearDisplay();
        writeTextToDisplay("TOP", 2, 40, 0, top_bottem);
        writeTextToDisplay("BOTTEM", 2, 18, 16, !top_bottem);
        display.display();
        init = true;
      }
      else if (up) {
        top_bottem = !top_bottem;
        init = false;
      }
      else if (down) {
        top_bottem = !top_bottem;
        init = false;
      }
      else if (ok) {
        if (top_bottem) {
          step = 10;
          init = false;
        }
        else {
          step = 110;
          init = false;
        }
      }
      break;
    //Select parameter of TOP controller
    case 10:
      if (!init) {

        //*******************************************************************************************************
        //        writeTextToDisplay("Kp", 1, 10, 0, paramPointer == 1);        //1 | Frame1
        //        writeTextToDisplay("Ki", 1, 10, 8, paramPointer == 2);        //2 |  | Frame2
        //        writeTextToDisplay("Kd", 1, 10, 16, paramPointer == 3);       //3    |  | Frame3
        //        writeTextToDisplay("OutMin", 1, 10, 24, paramPointer == 4);   //4       |   | Frame4
        //        writeTextToDisplay("OutMax", 1, 10, 32, paramPointer == 5);   //5           |   | Frame5
        //        writeTextToDisplay("BangBang", 1, 10, 40, paramPointer == 6); //6               | | Frame6
        //        writeTextToDisplay("HysteresisTop", 1, 10, 40, paramPointer == 6); //7               |
        //*******************************************************************************************************

        display.clearDisplay();
        switch (framePointer) {
          case 1:
            writeTextToDisplay("Kp", 2, 10, 0, paramPointer == 1);
            writeTextToDisplay("Ki", 2, 10, 16, paramPointer == 2);
            break;
          case 2:
            writeTextToDisplay("Ki", 2, 10, 0, paramPointer == 2);
            writeTextToDisplay("Kd", 2, 10, 16, paramPointer == 3);
            break;
          case 3:
            writeTextToDisplay("Kd", 2, 10, 0, paramPointer == 3);
            writeTextToDisplay("OutMin", 2, 10, 16, paramPointer == 4);
            break;
          case 4:
            writeTextToDisplay("OutMin", 2, 10, 0, paramPointer == 4);
            writeTextToDisplay("OutMax", 2, 10, 16, paramPointer == 5);
            break;
          case 5:
            writeTextToDisplay("OutMax", 2, 10, 0, paramPointer == 5);
            writeTextToDisplay("BangBang", 2, 10, 16, paramPointer == 6);
            break;
          case 6:
            writeTextToDisplay("BangBang", 2, 10, 0, paramPointer == 6);
            writeTextToDisplay("HysteresisTop", 2, 10, 16, paramPointer == 7);
            break;
        }
        display.display();
        init = true;
      }
      else if (up) {
        if ( paramPointer <= 6) {
          if ( framePointer > 1) {
            framePointer--;
          }
        }
        if ( paramPointer > 1) {
          paramPointer--;
        }
        init = false;
      }
      else if (down) {
        if ( paramPointer >= 2) {
          if ( framePointer < 6) {
            framePointer++;
          }
        }
        if ( paramPointer < 7) {
          paramPointer++;
        }

        init = false;
      }
      else if ((left && btnLeftPressDur >= 500) || (right && btnRightPressDur >= 500)) {
        step = 1;
        init = false;
      }
      else if (ok) {
        switch (paramPointer) {
          case 1:
            step = 20;
            break;
          case 2:
            step = 30;
            break;
          case 3:
            step = 40;
            break;
          case 4:
            step = 50;
            break;
          case 5:
            step = 60;
            break;
          case 6:
            step = 70;
            break;
          case 7:
            step = 80;
            break;
        }
        init = false;
      }
      break;
    //Kp TOP **********************************************************************************************************************
    case 20:
      if (SetFloatValue(KpTop, "", 0, 1, 5000) == 0) {
        TopPID.setGains(KpTop, KiTop, KdTop);
        EEPROM.put(KP_TOP, KpTop);
        step = 10;
      }
      break;
    //Ki TOP **********************************************************************************************************************
    case 30:
      if (SetFloatValue(KiTop, "", 0, 1, 5000) == 0) {
        TopPID.setGains(KpTop, KiTop, KdTop);
        EEPROM.put(KI_TOP, KiTop);
        step = 10;
      }
      break;
    //Kd TOP **********************************************************************************************************************
    case 40:
      if (SetFloatValue(KdTop, "", 0, 1, 5000) == 0) {
        TopPID.setGains(KpTop, KiTop, KdTop);
        EEPROM.put(KD_TOP, KdTop);
        step = 10;
      }
      break;
    //OutMin TOP **********************************************************************************************************************
    case 50:
      if (SetFloatValue(OutputMinTop, "", 0, 255, 5000, 1, 0.1, 1, 10, 100) == 0) {
        TopPID.setOutputRange(OutputMinTop, OutputMaxTop);
        EEPROM.put(OUT_MIN_TOP, OutputMinTop);
        step = 10;
      }
      break;
    //OutMax TOP **********************************************************************************************************************
    case 60:
      if (SetFloatValue(OutputMaxTop, "", 0, 255, 5000, 1, 0.1, 1, 10, 100) == 0) {
        TopPID.setOutputRange(OutputMinTop, OutputMaxTop);
        EEPROM.put(OUT_MAX_TOP, OutputMaxTop);
        step = 10;
      }
      break;
    //BangBang TOP **********************************************************************************************************************
    case 70:
      if (SetFloatValue(BangBangTop, "C", 0, 300, 5000, 1, 0.25, 1, 10, 100) == 0) {
        TopPID.setBangBang(BangBangTop);
        EEPROM.put(BANG_BANG_TOP, BangBangTop);
        step = 10;
      }
      break;
      //Hysteresis TOP **********************************************************************************************************************
    case 80:
      if (SetFloatValue(HysteresisTop, "C", 0, 25, 5000, 2, 0.25, 1, 10, 100) == 0) {
        EEPROM.put(HYST_TOP, HysteresisTop);
        step = 10;
      }
      break;

      //Select parameter of TOP controller
    case 110:
      if (!init) {

        //*******************************************************************************************************
        //        writeTextToDisplay("Kp", 1, 10, 0, paramPointer == 1);        //1 | Frame1
        //        writeTextToDisplay("Ki", 1, 10, 8, paramPointer == 2);        //2 |  | Frame2
        //        writeTextToDisplay("Kd", 1, 10, 16, paramPointer == 3);       //3    |  | Frame3
        //        writeTextToDisplay("OutMin", 1, 10, 24, paramPointer == 4);   //4       |   | Frame4
        //        writeTextToDisplay("OutMax", 1, 10, 32, paramPointer == 5);   //5           |   | Frame5
        //        writeTextToDisplay("BangBang", 1, 10, 40, paramPointer == 6); //6               | | Frame6
        //        writeTextToDisplay("HysteresisTop", 1, 10, 40, paramPointer == 6); //7            |
        //*******************************************************************************************************

        display.clearDisplay();
        switch (framePointer) {
          case 1:
            writeTextToDisplay("Kp", 2, 10, 0, paramPointer == 1);
            writeTextToDisplay("Ki", 2, 10, 16, paramPointer == 2);
            break;
          case 2:
            writeTextToDisplay("Ki", 2, 10, 0, paramPointer == 2);
            writeTextToDisplay("Kd", 2, 10, 16, paramPointer == 3);
            break;
          case 3:
            writeTextToDisplay("Kd", 2, 10, 0, paramPointer == 3);
            writeTextToDisplay("OutMin", 2, 10, 16, paramPointer == 4);
            break;
          case 4:
            writeTextToDisplay("OutMin", 2, 10, 0, paramPointer == 4);
            writeTextToDisplay("OutMax", 2, 10, 16, paramPointer == 5);
            break;
          case 5:
            writeTextToDisplay("OutMax", 2, 10, 0, paramPointer == 5);
            writeTextToDisplay("BangBang", 2, 10, 16, paramPointer == 6);
            break;
          case 6:
            writeTextToDisplay("BangBang", 2, 10, 0, paramPointer == 6);
            writeTextToDisplay("HysteresisTop", 2, 10, 16, paramPointer == 7);
            break;
        }
        display.display();
        init = true;
      }
      else if (up) {
        if ( paramPointer <= 6) {
          if ( framePointer > 1) {
            framePointer--;
          }
        }
        if ( paramPointer > 1) {
          paramPointer--;
        }
        init = false;
      }
      else if (down) {
        if ( paramPointer >= 2) {
          if ( framePointer < 6) {
            framePointer++;
          }
        }
        if ( paramPointer < 7) {
          paramPointer++;
        }

        init = false;
      }
      else if ((left && btnLeftPressDur >= 500) || (right && btnRightPressDur >= 500)) {
        step = 1;
        init = false;
      }
      else if (ok) {
        switch (paramPointer) {
          case 1:
            step = 120;
            break;
          case 2:
            step = 130;
            break;
          case 3:
            step = 140;
            break;
          case 4:
            step = 150;
            break;
          case 5:
            step = 160;
            break;
          case 6:
            step = 170;
            break;
          case 7:
            step = 180;
            break;
        }
        init = false;
      }
      break;
    //Kp BOTTEM **********************************************************************************************************************
    case 120:
      if (SetFloatValue(KpBtm, "", 0, 1, 5000) == 0) {
        BtmPID.setGains(KpBtm, KiBtm, KdBtm);
        EEPROM.put(KP_BTM, KpBtm);
        step = 110;
      }
      break;
    //Ki BOTTEM **********************************************************************************************************************
    case 130:
      if (SetFloatValue(KiBtm, "", 0, 1, 5000) == 0) {
        BtmPID.setGains(KpBtm, KiBtm, KdBtm);
        EEPROM.put(KI_BTM, KiBtm);
        step = 110;
      }
      break;
    //Kd BOTTEM **********************************************************************************************************************
    case 140:
      if (SetFloatValue(KdBtm, "", 0, 1, 5000) == 0) {
        BtmPID.setGains(KpBtm, KiBtm, KdBtm);
        EEPROM.put(KD_BTM, KdBtm);
        step = 110;
      }
      break;
    //OutMin BOTTEM **********************************************************************************************************************
    case 150:
      if (SetFloatValue(OutputMinBtm, "", 0, 255, 5000, 1, 0.1, 1, 10, 100) == 0) {
        BtmPID.setOutputRange(OutputMinBtm, OutputMaxBtm);
        EEPROM.put(OUT_MIN_BTM, OutputMinBtm);
        step = 110;
      }
      break;
    //OutMax BOTTEM **********************************************************************************************************************
    case 160:
      if (SetFloatValue(OutputMaxBtm, "", 0, 255, 5000, 1, 0.1, 1, 10, 100) == 0) {
        BtmPID.setOutputRange(OutputMinBtm, OutputMaxBtm);
        EEPROM.put(OUT_MAX_BTM, OutputMaxBtm);
        step = 110;
      }
      break;
    //BangBang BOTTEM **********************************************************************************************************************
    case 170:
      if (SetFloatValue(BangBangBtm, "C", 0, 300, 5000, 1, 0.25, 1, 10, 100) == 0) {
        BtmPID.setBangBang(BangBangBtm);
        EEPROM.put(BANG_BANG_BTM, BangBangBtm);
        step = 110;
      }
      break;
      //Hysteresis BOTTEM **********************************************************************************************************************
    case 180:
      if (SetFloatValue(HysteresisBtm, "C", 0, 25, 5000, 2, 0.25, 1, 10, 100) == 0) {
        EEPROM.put(HYST_BTM, HysteresisBtm);
        step = 110;
      }
      break;
  }


  //bool SetFloatValue(double& value, String unit, double min, double max, int interval = 2500, int precision = 4, double incr1 = 0.0001, double incr2 = 0.001, double incr3 = 0.01, double incr4 = 0.1, double incr5 = 1 ) {
}
