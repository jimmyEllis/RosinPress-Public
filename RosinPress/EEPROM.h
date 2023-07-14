#include <EEPROM.h>


enum blinkStates {
  SETPOINT = 0, 
  KP_TOP = 4, 
  KI_TOP = 8, 
  KD_TOP = 12,
  OUT_MIN_TOP = 16,
  OUT_MAX_TOP = 20,
  BANG_BANG_TOP = 24,
  KP_BTM = 28, 
  KI_BTM = 32, 
  KD_BTM = 36,
  OUT_MIN_BTM = 40,
  OUT_MAX_BTM = 44,
  BANG_BANG_BTM = 48, 
  HYST_TOP = 52,
  HYST_BTM = 56
};
