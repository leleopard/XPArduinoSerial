#include "Bounce2ST.h"
#include "ClickEncoderST.h"
#include "potentiometer.h"
#include "pwm.h"
#include "ServoST.h"
#include "serialComm.h"
#include "globals.h"
#include <TimerOne.h>

#define BAUD 115200

Bounce          SWITCH_ARRAY[MAX_NR_SWITCHES] ;
Potentiometer   POT_ARRAY[MAX_NR_POTS];
PWM             PWM_ARRAY[MAX_NR_PWMS];
ServoST         SERVO_ARRAY[MAX_NR_SERVOS];
DigOutput       DIGOUTPUTS_ARRAY[MAX_NR_DIGOUTPUTS];
ClickEncoder    ROTENC_ARRAY[MAX_NR_ENCODERS];
int16_t         lastEncoderValues[MAX_NR_ENCODERS];
int16_t         currentEncoderValues[MAX_NR_ENCODERS];

void timerIsr() {
  for (int i = 0; i < MAX_NR_ENCODERS; i++) {
    ROTENC_ARRAY[i].service(); 
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUD);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr); 
  for (int i = 0; i < MAX_NR_ENCODERS; i++) {
    lastEncoderValues[i] = 0; 
    currentEncoderValues[i] = 0; 
  }
  
  Serial.println("Setup complete...");
  
}
int val = 0;
int angle = 0; 

void loop() {
  while (Serial.available () > 0){
    //Serial.print("Serial data available!");
    processIncomingByte (Serial.read ());
  }
  for (int i = 0; i < MAX_NR_SWITCHES; i++) {
    if (SWITCH_ARRAY[i].update() == 1) {
      int value = SWITCH_ARRAY[i].read();
      sendInputValue("SW:", SWITCH_ARRAY[i].getPin(), value);
    } 
  }
  for (int i = 0; i < MAX_NR_POTS; i++) {
    if (POT_ARRAY[i].update() == true) {
      //Serial.println("POT VALUE CHANGED: POT nr"+ (String)i + " pin: "+(String) POT_ARRAY[i].getPin());
      int value = POT_ARRAY[i].read();
      sendInputValue("POT:",POT_ARRAY[i].getPin(), value);
    } 
  }

  for (int i = 0; i < MAX_NR_ENCODERS; i++) {
    currentEncoderValues[i] += ROTENC_ARRAY[i].getValue();
    if (currentEncoderValues[i] != lastEncoderValues[i]) {
      //Serial.println("Encoder "+(String)i+" value: "+(String)currentEncoderValues[i]); 
      
      sendInputValue("ROTENC:",ROTENC_ARRAY[i].getPin(), currentEncoderValues[i]-lastEncoderValues[i]);
      lastEncoderValues[i] = currentEncoderValues[i];
    }
    
  }
  
  for (int i = 0; i < MAX_NR_PWMS; i++) {
    PWM_ARRAY[i].writeValue(); 
  }
  for (int i = 0; i < MAX_NR_DIGOUTPUTS; i++) {
    DIGOUTPUTS_ARRAY[i].writeValue(); 
  }
  
  /**
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++)  
  {                                  
    SERVO_ARRAY[0].write(angle);               
    delay(15);                   
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--)    
  {                                
    SERVO_ARRAY[0].write(angle);           
    delay(15);       
  } */
  
}
