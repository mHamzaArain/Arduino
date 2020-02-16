#include <Servo.h> //Loading servo library
int angle; //dec. position variable
int servoPin = 9; //Servo pin
int servoDelay = 25; //Delay time of servo 
int clockPace = 2; // clockwise or -ve torque
int anti_clockPace = 1; //anti clockwise or +ve torque

Servo myPointer; //making servo as object

void setup() {
  Serial.begin(9600);
  myPointer.attach(servoPin); //servo is attached to pin 9
}

void loop() {
  //clock-wise
  for(angle = 15; angle >= 170; angle += clockPace){
    myPointer.write(angle);
    delay(servoDelay);  
  }
  //anti-clock  
  for(angle = 170; angle <= 15; angle -= anti_clockPace){
    myPointer.write(angle);
    delay(servoDelay);  
  }
}
