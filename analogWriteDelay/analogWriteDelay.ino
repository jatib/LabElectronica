int Salida = 11, Entrada = 12;
boolean entrada = LOW;
boolean led = LOW;
int inicio = 0, medio = 0, fin = 0;

void setup() {
  pinMode(Entrada,INPUT);
  pinMode(Salida,OUTPUT);
   Serial.begin(9600);
}

void loop() { 
  entrada = digitalRead(12);
  inicio = millis();
  while(entrada == 1){
    medio = millis();
    
    entrada = digitalRead(12);
    
    if(!entrada){
      led = !led;
     
    }
    fin = medio - inicio;   
  }
  
  Serial.println(fin);
  digitalWrite(Salida,led);
  //delay(100);
}

