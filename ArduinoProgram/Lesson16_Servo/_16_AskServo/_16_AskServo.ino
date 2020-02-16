#include <Servo.h> //Loading servo library
int angle = 0; //dec. position variable
int servoPin = 9; //Servo pin
int servoDelay = 25; //Delay time of servo 

Servo myPointer; //making servo as object

void setup() {
  Serial.begin(9600);
  myPointer.attach(servoPin); //servo is attached to pin 9
}

void loop() {
Serial.println("Angle: ");
while (Serial.available() == 0) {}
angle = Serial.parseInt();
myPointer.write(angle);
delay(servoDelay);
}
