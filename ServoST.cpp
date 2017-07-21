#include <Servo.h>
#include "ServoST.h"

// get the number of the pin the instance is attached to (-1 if not attached)
int ServoST::getPin(){
  return _pin;
}

uint8_t ServoST::attach(int pin){
  _pin = pin;
  Servo::attach(pin,615,2390);
}

