#include <Bounce2.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
int val = 0;

void loop() {
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
