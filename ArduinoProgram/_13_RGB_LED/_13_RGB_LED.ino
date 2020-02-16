int redPin=7;  //set red LED pin to 11
int greenPin=6; //set green LED pin to 10
int bluePin=5; //set blue LED pin to 6
int brightness=102; //Set brightness to 100

void setup() {
pinMode(redPin, OUTPUT); //Set redPin to be an output
pinMode(greenPin, OUTPUT); //Set greenPin to be an output
pinMode(bluePin, OUTPUT); //set bluePin to be an output

}

void loop() {
  // put your main code here, to run repeatedly: 
  
  analogWrite(redPin, brightness); //turn off red pin
  delay(1000);
  analogWrite(redPin, 0); //turn off red pin
  delay(1000);

  analogWrite(greenPin, brightness); //turn off red pin
  delay(1000);
  analogWrite(greenPin, 0); //turn off red pin
  delay(1000);

  analogWrite(bluePin, brightness); //turn off red pin
  delay(1000);
  analogWrite(bluePin, 0); //turn off red pin
  delay(1000);
}
