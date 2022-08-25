#define PotentiometerInputPin 0 // potentiometer input pin number 1
#define PotentiometerInputPinTwo 1 // potentiometer input pin number 2

int inputPotentiometerValue = 0; //variable to store the value from potentiometer 1
int inputPotentiometerValueTwo = 0; //variable to store the value from potentiometer 2

void setup() {
  // open serial
  Serial.begin(9600);
}

void loop() {
  //Read Pin 1
  inputPotentiometerValue = analogRead(PotentiometerInputPin);
  //Read Pin Two
  inputPotentiometerValueTwo = analogRead(PotentiometerInputPinTwo);
  
  
  //Map value from Potentiometer to Output to Unity 0 to 100
  
  //Potentiometer
  inputPotentiometerValue = map(inputPotentiometerValue, 0, 1023, 0, 100);
  //Potentiometer Two
  inputPotentiometerValueTwo = map(inputPotentiometerValueTwo, 0, 1023, 0, 100);

  //Output values to Serial Port
  Serial.print(inputPotentiometerValue);
  Serial.print(",");
  Serial.println(inputPotentiometerValueTwo);

  delay(200);
}
