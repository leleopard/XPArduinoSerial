#include "digOutput.h"
#include "Arduino.h"
#include "globals.h"

DigOutput::DigOutput(){
  _pin = -1;  
  _value = 0;
}

// Attach to a pin (and also sets initial value) pin must be between 22 and 53, or -1 in which case the instance is effectively disabled
void DigOutput::attach(int pin){
  
  if (pin >=22 && pin <=53){
    _pin = pin;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
  } else if(pin == -1){
    _pin = pin;
  }
  //Serial.println("PWM attached pin: " + (String)_pin);
}

// get the number of the pin the instance is attached to (-1 if not attached)
int DigOutput::getPin(){
  return _pin;
}

// updates the value of the instance 
void DigOutput::updateValue(int value){
  _value = 0;
  if (value == 0 || value == 1){
    _value = value;  
  }
}


// Updates the pin (if <> -1)
void DigOutput::writeValue(){
  if(_pin != -1){
    //Serial.println(">ARD> digout writing value to pin: " + (String)_pin + " value: " + _value);
    if(_value == 1) {
      digitalWrite(_pin, HIGH);  
    } else {
      digitalWrite(_pin, LOW);
    }
  }
}

