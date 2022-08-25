#define PotentiometerInputPin A0 // potentiometer input pin number

int inputPotentiometerValue = 0; //variable to store the value from potentiometer

void setup() {
  // open serial
  Serial.begin(9600);
}

void loop() {
  
  inputPotentiometerValue = analogRead(PotentiometerInputPin);
  
  //Map value from Potentiometer to Output to Unity 0 to 100
  inputPotentiometerValue = map(inputPotentiometerValue, 0, 1023, 0, 100);
  
  Serial.println(inputPotentiometerValue);
}
