#ifndef ServoST_h
#define ServoST_h

#include <Servo.h>

class ServoST : public Servo {
  public:
    int getPin();
    uint8_t attach(int pin);
    void reAttach();
    void updateValue(int value);
    void refresh();
    
  private:
    int _pin = -1; 
    int _valueST = 90;
};

#endif


