int ledPin = 9; //dec. digital pin 9 for led
int potPin = A0; //dec. potPin tto be analog pin a0
int readValue; //To read potentiometer
int writeValue; // writing LED

void setup() {
  Serial.begin(9600); //turn on seial port
  pinMode(potPin, INPUT);// input
  pinMode(ledPin, OUTPUT);// outpu  
}

void loop()
{
  do
  {
    readValue = analogRead(potPin); //Reading Potentiometer movements
    Serial.print("The poential range: "); // 0-1023
    Serial.println(readValue);
    
    writeValue = (255.0/1023.0) * readValue; //We got this below: *We use decimal point to make it float
    // X1 = 0, Y1 = 0, X2 = 1023, Y2 = 255
    // m = Y2 - Y1 / X2 - X1 => (255 - 0) / (1023 -  0) => m = 255/1023
    // Y - Y1 = m (X - X1) => Y - 0 = 255/1023 * (X - 0) => Y = 255/1023 * X    
    analogWrite(ledPin, writeValue); //analog on until time
    delay(readValue);

    //printing
    Serial.print("Analog voltage: ");
    Serial.println(writeValue/51.); //m = y2/x2 => 255/5; m = 51
    
    Serial.println();
  }while(writeValue >= 250); // this cond. to make it witout binking when potential range is at max

  // off untill delay 
  analogWrite(ledPin, 0); // 0v -> Volange range 0-255
  delay(readValue);
}
