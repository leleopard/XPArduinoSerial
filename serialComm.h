#ifndef serialComm_h
#define serialComm_h

#include "Arduino.h"

void sendSwitchValue(uint8_t pin,int value);
void sendXP_Cmd(String command);
void sendXP_Dref(float value, String dataref);

#endif
