#ifndef serialComm_h
#define serialComm_h

#include "Arduino.h"

void processIncomingByte (const byte inByte);
void sendSwitchValue(uint8_t pin,int value);
void sendInputValue(String inputType, uint8_t pin,int value);
void processCommand(char* command);
void sendXP_Cmd(String command);
void sendXP_Dref(float value, String dataref);

#endif
