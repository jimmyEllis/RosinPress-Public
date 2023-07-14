#include <AutoPID.h>
#include <MAX6675.h>
#include "PID.h"
#include "ThermoCouple.h"
#include "LCD.h"
#include "Keypad.h"
#include "Menu.h"
#include "EEPROM.h"

bool PID_Selectot;

void setup() {
  Serial.begin(9600);
    SetupEEPROM();
  SetupTC();
    SetupLCD();
   SetupPid();
  SetupKeypad();
}

void loop() {
  // Read the temp from the MAX6675
  if (PID_Selectot) {
    TemperatureTop = ReadTemperature(true);
    PID_Selectot = false;
  }
  else {
    TemperatureBtm = ReadTemperature(false);
    PID_Selectot = true;
  }
//Serial.print("TemperatureTop: "); Serial.print( TemperatureTop ); Serial.print("\tTemperatureBtm: "); Serial.println( TemperatureBtm );
UpdateKeyDuration();
    RunPID(TC_Error);
    HandleSetpoint();
    HandleMenu();
  //SaveConfig();
    if (millis() - LastTime >= DisplTime && !MenuActive && !SetpointActive) {
      display.clearDisplay();
      display.fillRect(68, 0, 70, 70, SSD1306_INVERSE);
      
      AtTempTop = TopPID.atSetPoint(HysteresisTop);
      AtTempBtm = BtmPID.atSetPoint(HysteresisBtm);
      
      writeDoubleToDisplay(TemperatureTop, 2, 0, 1, AtTempTop,0);
      writeTextToDisplay("C", 2, 50, 0, AtTempTop);
      writeDoubleToDisplay(map(OutputValTop,0,255,0,100), 2, 68, 0, true, 0);
      writeTextToDisplay("%", 2, 105, 0, true);
      
      writeDoubleToDisplay(TemperatureBtm, 2, 0, 17, AtTempBtm,0);
      writeTextToDisplay("C", 2, 50, 17, AtTempBtm);
      writeDoubleToDisplay(map(OutputValBtm,0,255,0,100), 2, 68, 17, true, 0);
      writeTextToDisplay("%", 2, 105, 17, true);
      
      
      display.display();
      LastTime = millis();
    }
  //
  //
  //
  //
  //
//    Serial.print("\nTop output: "); Serial.print( OutputValTop ); Serial.print("\tBottem output: "); Serial.println( OutputValBtm );
//    Serial.print("Top output Min: "); Serial.print(OutputMinTop); Serial.print("\tBottem output Min: "); Serial.println(OutputMinBtm);
//    Serial.print("Top output Max: "); Serial.print( OutputMaxTop ); Serial.print("\tBottem output Max: "); Serial.println( OutputMaxBtm );
    
}
