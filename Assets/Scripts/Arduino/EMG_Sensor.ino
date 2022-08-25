#define PotentiometerInputPin A0 // potentiometer input pin number

int inputPotentiometerValue = 0; //variable to store the value from potentiometer

void setup() {
  // open serial
  Serial.begin(9600);
}

void loop() {
  
  inputPotentiometerValue = analogRead(PotentiometerInputPin);
  
  Serial.println(inputPotentiometerValue);
}
