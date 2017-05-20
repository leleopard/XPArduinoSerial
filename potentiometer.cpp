#include "potentiometer.h"
#include "Arduino.h"
#include "globals.h"

Potentiometer::Potentiometer(){
  _pin = -1;  
  _value = 0;
  _previous_value = 0;
}

// Attach to a pin (and also sets initial value)
void Potentiometer::attach(int pin){
  if (pin >=0 && pin <16){
    _pin = pin;
    _value = analogRead(_pin);
  } else if(pin == -1){
    _pin = pin;
  }
}

// get the number of the pin the instance is attached to (-1 if not attached)
int Potentiometer::getPin(){
  return _pin;
}

// Updates the pin
// Returns 1 if the state changed
// Returns 0 if the state did not change
bool Potentiometer::update(){
  if(_pin == -1){
    return false;
  } else {
    _value = analogRead(_pin);
    if(abs(_value - _previous_value) > 5){
      _previous_value = _value;
      return true;
    } else {
      return false;
    }
    
  }
}

// Returns the updated pin value (int 0 to 1023)
int Potentiometer::read(){
  return _value;
}
