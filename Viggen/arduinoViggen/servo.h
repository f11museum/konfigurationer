#include <Servo.h>

#define NR_SERVOS DIGITAL_PIN_COUNT // 10 servos takes 27 bytes memory
Servo myservos[NR_SERVOS];
void setupServo(int pin) {
  
  myservos[pin].attach(pin); 
}
void setServo(int pin, int val) {
  //pcSerial.print("Servo");
  //pcSerial.println(val);
  //Servo myservo;
  //myservo.attach(pin); 
  if (val <600) {
    val = 600;
  }
  if (val>2600) {
    val = 2600;
  }
  myservos[pin].writeMicroseconds(val);
  //delay(15); 
}
