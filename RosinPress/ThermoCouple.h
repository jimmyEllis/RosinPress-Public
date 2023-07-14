#define CS_PIN_BTM 2
#define CS_PIN_TOP 9
#define SO_PIN 10
#define SCK_PIN 11
#define UNITS 1 //Units to readout temp (0 = raw, 1 = ˚C, 2 = ˚F)

bool TC_Error = false; //Used to turn off PID when TC is faulty

// Initialize the MAX6675 Library for our chip
MAX6675 TopTempCtr(CS_PIN_TOP, SO_PIN, SCK_PIN, UNITS);
MAX6675 BtmTempCtr(CS_PIN_BTM, SO_PIN, SCK_PIN, UNITS);
