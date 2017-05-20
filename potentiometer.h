
#ifndef potentiometer_h
#define potentiometer_h

class Potentiometer
{
  public:
    Potentiometer();

    // Attach to a pin (and also sets initial state)
    void attach(int pin);

    // get the number of the pin the instance is attached to
    int getPin();
    
    // Updates the pin
    // Returns 1 if the state changed
    // Returns 0 if the state did not change
    bool update();

    // Returns the updated pin value (int 0 to 1023)
    int read();

 protected:
    int _value;
    int _previous_value;
    int _pin;
};




#endif
