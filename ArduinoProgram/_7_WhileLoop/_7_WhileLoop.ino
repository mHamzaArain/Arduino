//init. & dec. t all here, to modify anything fom here;

//dec. pins
int orangeLedPin = 10;
int greenLedPin =  9;

//init. on\off time
int orangeOnTime = 100;
int orangeOffTime = 900;
int greenOnTime = 100;
int greenOffTime = 900;

//LEDs blinking number of times
int orangeNumber;   // = 3;
int greenNumber;    // = 3;

//for loop string msg variables
String orangeMessage = "Orange LED is blinking";
String greenMessage = "Green LED is blinking";

void setup() 
{
  Serial.begin(115200); //baud pace init. for serial printing
  Serial.print("\nInitialiing program....\n"); //Printing
  delay(500);
  
  //setup both pins as output 
  pinMode(orangeLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  //Prompting from user
  Serial.println("How many times Orange LED blink: "); // Orange
  while (!Serial.available()) {}
  orangeNumber = Serial.parseInt();

  Serial.println("How many times Green LED blink: "); //Green
  while (!Serial.available()) {} 
  delay(3000);                   //to hold for input
  greenNumber = Serial.parseInt();

}

void loop() {
  //blinking LEDs for specific numbers of time
  
  //orange led section
  Serial.println("");

  int i = 1; //while looping
  while(i <= orangeNumber)
  {
    //printing
    Serial.println(orangeMessage + ": " + i);

    //on/off -> time
    digitalWrite(orangeLedPin, HIGH); // on
    delay(orangeOnTime); // on time
    digitalWrite(orangeLedPin, LOW); //off
    delay(orangeOffTime); //off time
    i++;
  }
  Serial.println(""); //print for separation
  
  //Green LED section
  Serial.println(greenMessage);
  for(int j = 1; j <= greenNumber; j++)
  {
    Serial.println(greenMessage + ": " + j);
    digitalWrite(greenLedPin,HIGH); //on
    delay(greenOnTime); //ON TIME
    digitalWrite(greenLedPin, LOW); //off
    delay(greenOffTime); //OFF TIME
  }
}
