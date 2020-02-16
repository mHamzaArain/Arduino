#include <Servo.h> //Loading servo library
int angle = 0; //dec. position variable
int servoPin = 9; //Servo pin
int potentioPin = A0; //Dec. for potentiometre
int potentioRead; // to read the pin
int servoDelay = 25; //Delay time of servo 

Servo myPointer; //making servo as object

void setup() {
  Serial.begin(9600);
  myPointer.attach(servoPin); //servo is attached to pin 9
}

void loop() {
  potentioRead = analogRead(potentioPin);
  angle = (155.0/1023.0)*potentioRead + 15;
  myPointer.write(angle);
  
}
