int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0,tiempo = 0;
float volt,temp,maxi=0,mini=0;
//boolean pulso = 0;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);

}

void loop() {
  tiempo = millis();
  sensorValue = analogRead(sensorPin);
  volt = sensorValue*0.004889;
  temp = volt*100;

  maxi = max(maxi,temp);
  if(mini==0)
    mini = temp;
  else
    mini = min(mini,temp);
    
  Serial.print("Medido: ");
  Serial.print(sensorValue);
  Serial.print("\t Voltaje: ");
  Serial.print(volt);
  Serial.print("\t Temperatura: ");
  Serial.print(temp);
  Serial.print("\t tiempo: ");
  Serial.println(tiempo/1000);
  Serial.println((tiempo/1000)%15);
  delay(1000);

  
  
  if((tiempo/1000)%15 == 0){
    Serial.print("MÁXIMO: ");
    Serial.print(maxi);
    Serial.print("\t MÍNIMO: ");
    Serial.println(mini);
  }
  
  //if (pulso = 1)
}

