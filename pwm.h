#ifndef pwm_h
#define pwm_h

class PWM
{
  public:
    PWM();

    // Attach to a pin (and also sets initial state)
    void attach(int pin);

    // get the number of the pin the instance is attached to
    int getPin();

    // updates the value of the instance 
    void updateValue(int value);
    
    // Updates the pin (if <> -1)
    void writeValue();

 protected:
    int _value;
    int _previous_value;
    int _pin;
};

#endif
