#include <Servo.h> //Load servo library

//Ultrasoinc Sensor
int trigPin = 13; // trigPin to 13
int echoPin = 11; //echoPin to 11

//Servo Motor
int  servoControlPin = 6; // analogPin to pin 6

float pingTime; //time for ping to go and return
float targetDistance; //distance from sensor to target
float speedofSound = 776.5; //speed of sound in miles/hour (temp is 77 degree F)
float servoAngle; //Variable for the angle of servo

Servo myPointer; //Created servo object called myPointer

void setup() {
  Serial.begin(9600); //On serial port
  pinMode(servoControlPin, OUTPUT); //servo control pin is on output
  pinMode(trigPin, OUTPUT); //OUTPUT trigger
  pinMode(echoPin, INPUT); //INPUT echo

  myPointer.attach(servoControlPin); //Servo is connected
}

void loop() {
  digitalWrite(trigPin, LOW); //trig -> LOW
  delayMicroseconds(2000); //delayTime 2 milli s
  digitalWrite(trigPin, HIGH); //trig -> HIGH
  delayMicroseconds(15); //delayTime 0.015 milli s
  digitalWrite(trigPin, LOW); //bring tigPin to LOW again
  delayMicroseconds(10); //delayTime 0.01 milli s

  pingTime = pulseIn(echoPin, HIGH); //Measure ping time in Us
  pingTime = pingTime / 1000000.0; //1e6 -> Us - s
  pingTime = pingTime / 3600.0; //s -> H
  targetDistance = speedofSound * pingTime; //Calc. distance in miles
  targetDistance = targetDistance / 2; //Accounts for trip go & back
  targetDistance = targetDistance * 63360; //Convert targetDistance from invhes to miles

  Serial.println("The distance to the target is: ");
  Serial.print(targetDistance);
  Serial.println(" inches");
  if (targetDistance <= 7) {
    servoAngle = (106. / 7.) * targetDistance + 37;
    if (servoAngle >= 37 || servoAngle <= 130) {
      for (int i = 1; i <= servoAngle; i += 2) {
        myPointer.write(servoAngle);
      }

      for (int i = 1; i > servoAngle; i -= 2) {
        myPointer.write(servoAngle);
      }
    }
    else {
      myPointer.write(120);
    }
    Serial.println(servoAngle);
    //    delay(10);
  }



}
