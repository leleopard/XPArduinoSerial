#ifndef ServoST_h
#define ServoST_h

#include <Servo.h>

class ServoST : public Servo {
  public:
    int getPin();
    uint8_t attach(int pin);
    void reAttach();

  private:
    int _pin = -1; 
};

#endif


