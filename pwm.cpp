#include "pwm.h"
#include "Arduino.h"
#include "globals.h"

PWM::PWM(){
  _pin = -1;  
  _value = 0;
}

// Attach to a pin (and also sets initial value) pin must be between 2 and 13, or -1 in which case the instance is effectively disabled
void PWM::attach(int pin){
  
  if (pin >=2 && pin <=13){
    _pin = pin;
    analogWrite(_pin, _value);
  } else if(pin == -1){
    _pin = pin;
  }
  //Serial.println("PWM attached pin: " + (String)_pin);
}

// get the number of the pin the instance is attached to (-1 if not attached)
int PWM::getPin(){
  return _pin;
}

// updates the value of the instance 
void PWM::updateValue(int value){
  _value = value;
}


// Updates the pin (if <> -1)
void PWM::writeValue(){
  if(_pin != -1){
    //Serial.println("PWM writing value to pin: " + (String)_pin + " value: " + _value);
    analogWrite(_pin, _value);
  }
}


