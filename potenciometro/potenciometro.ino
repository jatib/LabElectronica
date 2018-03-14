int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;
float voltaje;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

}

void loop() {
  sensorValue = analogRead(sensorPin);
  voltaje = sensorValue*0.004889;
  Serial.print("Medido: ");
  Serial.print(sensorValue);
  Serial.print("\t Voltaje: ");
  Serial.println(voltaje);
  
}
