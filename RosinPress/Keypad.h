//#include <PinChangeInt.h>

#include <PinChangeInterrupt.h>


#define UP  14
#define LFT  15
#define RGT  16
#define DN  17
#define OK  7

bool up, down, left, right, ok;

long btnUpPressTime, btnDownPressTime, btnLeftPressTime, btnRightPressTime, btnOkPressTime;
long btnUpPressDur = 0, btnDownPressDur = 0, btnLeftPressDur = 0, btnRightPressDur = 0, btnOkPressDur = 0;
