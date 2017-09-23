#ifndef globals_h
#define globals_h

#include "Bounce2ST.h"
#include "ClickEncoderST.h"
#include "potentiometer.h"
#include "pwm.h"
#include "ServoST.h"
#include "digOutput.h"

#define MAX_NR_SWITCHES     32
#define MAX_NR_POTS         16
#define MAX_NR_PWMS         12
#define MAX_NR_SERVOS       12
#define MAX_NR_DIGOUTPUTS   32
#define MAX_NR_ENCODERS     16

extern Bounce         SWITCH_ARRAY[MAX_NR_SWITCHES] ;
extern Potentiometer  POT_ARRAY[MAX_NR_POTS];
extern PWM            PWM_ARRAY[MAX_NR_PWMS];
extern ServoST        SERVO_ARRAY[MAX_NR_SERVOS];
extern DigOutput      DIGOUTPUTS_ARRAY[MAX_NR_DIGOUTPUTS];
extern ClickEncoder   ROTENC_ARRAY[MAX_NR_ENCODERS];

#endif
