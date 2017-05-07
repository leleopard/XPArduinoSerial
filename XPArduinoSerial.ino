#include "Bounce2ST.h"
#include "serialComm.h"

#define MAX_NR_SWITCHES 32

Bounce SWITCH_ARRAY[32] ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(22,INPUT_PULLUP);
  SWITCH_ARRAY[0].attach(22);
}
int val = 0;

void loop() {

  for (int i = 0; i < MAX_NR_SWITCHES; i++) {
    if (SWITCH_ARRAY[i].update() == 1) {
      int value = SWITCH_ARRAY[i].read();
      sendSwitchValue(SWITCH_ARRAY[i].getPin(), value);
      
      //Serial.print("pin ");
      //Serial.print(SWITCH_ARRAY[i].getPin());
      //Serial.print(" changed, value: ");
      //Serial.println(value);
      
    } else {
      //Serial.println("pin unchanged");
    }
    
  }
  
  // put your main code here, to run repeatedly:
  char ch = Serial.read();
  if (ch == '+' ) {
    if (val<255) {
      val++;
      Serial.println(val);
    }
  }
  if (ch == '-' ) {
    if (val>0) {
      val--;
      Serial.println(val);
    }
  }
  analogWrite(11, val);
  
}
