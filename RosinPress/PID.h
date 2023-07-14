#define OUTPUT_PIN_TOP 5
#define OUTPUT_PIN_BTM 6
#define RDY_LED_PIN 13

//pid settings and gains
double BangBangTop = 15, BangBangBtm = 15;
double OutputMinTop = 0, OutputMinBtm = 0;
double OutputMaxTop = 255, OutputMaxBtm = 255;
double KpTop = .012, KpBtm = .12;
double KiTop = .0001, KiBtm = .0003;
double KdTop = 0, KdBtm = 0;
double TemperatureTop = 0.0,SetPoint = 50, OutputValTop = 50;  // Temperature output variable
double TemperatureBtm = 0.0,/*SetPoint = 40,*/ OutputValBtm = 100;  // Temperature output variable
bool AtTempTop = false, AtTempBtm = false;
double HysteresisTop = 3.0, HysteresisBtm = 3.0;
//input/output variables passed by reference, so they are updated automatically
AutoPID TopPID(&TemperatureTop, &SetPoint, &OutputValTop, OutputMinTop, OutputMaxTop, KpTop, KiTop, KdTop);
AutoPID BtmPID(&TemperatureBtm, &SetPoint, &OutputValBtm, OutputMinBtm, OutputMaxBtm, KpBtm, KiBtm, KdBtm);
