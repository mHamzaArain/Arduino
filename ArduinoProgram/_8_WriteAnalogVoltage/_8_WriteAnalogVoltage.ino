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
int orangeNumber = 3;
int greenNumber = 3;

//for loop string msg variables
String orangeMessage = "Orange LED is blinking";
String greenMessage = "Green LED is blinking";

int writeValueOrange; //dec. variable for write value
int writeValueGreen; //dec.variable for write value

void setup() 
{
  Serial.begin(115200); //baud pace init. for serial printing
  Serial.print("\nInitialiing program....\n"); //Printing
  
  //setup both pins as output 
  pinMode(orangeLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  //Prompting from user
  Serial.println("What no. do you want to write Orange LED? "); // Orange
  while (!Serial.available()) {} //wait for input
  writeValueOrange = Serial.parseInt(); //input

  Serial.println("What no. do you want to write Green LED? "); // Orange
  while (!Serial.available()) {} //wait for input
  delay(3000); // delay for input
  writeValueGreen = Serial.parseInt(); //input
}

void loop() {
  //blinking LEDs for specific numbers of time
  
  //orange led section
  Serial.println("");
  int i = 1; //for while loop
  while(i <= orangeNumber)
  {
    //printing
    Serial.println(orangeMessage + ": " + i);

    //on/off -> time
    analogWrite(orangeLedPin, writeValueOrange); // anlog pin high
    delay(orangeOnTime); // on time
    analogWrite(orangeLedPin, 0); // anaog pin low
    delay(orangeOffTime); //off time
    i++;
  }
  Serial.println(""); //print for separation
  
  //Green LED section
  Serial.println(greenMessage);
  for(int j = 1; j <= greenNumber; j++)
  {
    Serial.println(greenMessage + ": " + j);
    analogWrite(greenLedPin, writeValueGreen); //analog high 
    delay(greenOnTime); //ON TIME
    analogWrite(greenLedPin, 0); // analog low
    delay(greenOffTime); //OFF TIME
  }
}
