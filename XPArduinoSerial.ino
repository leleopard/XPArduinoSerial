#include "Bounce2ST.h"
#include "potentiometer.h"
#include "serialComm.h"
#include "globals.h"

#define BAUD 115200
#define MAX_NR_SWITCHES 32

Bounce SWITCH_ARRAY[32] ;
Potentiometer POT_ARRAY[16];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD);
  pinMode(22,INPUT_PULLUP);
  //SWITCH_ARRAY[0].attach(22);
  //POT_ARRAY[0].attach(0);
}
int val = 0;

void loop() {
  while (Serial.available () > 0){
    //Serial.print("Serial data available!");
    processIncomingByte (Serial.read ());
  }
  for (int i = 0; i < MAX_NR_SWITCHES; i++) {
    if (SWITCH_ARRAY[i].update() == 1) {
      int value = SWITCH_ARRAY[i].read();
      sendSwitchValue(SWITCH_ARRAY[i].getPin(), value);
    } 
  }
  for (int i = 0; i < 16; i++) {
    if (POT_ARRAY[i].update() == true) {
      //Serial.println("POT VALUE CHANGED: POT nr"+ (String)i + " pin: "+(String) POT_ARRAY[i].getPin());
      int value = POT_ARRAY[i].read();
      sendInputValue("POT:",POT_ARRAY[i].getPin(), value);
    } 
  }
  
  //Serial.print("I'm there!!");
  
  
}
