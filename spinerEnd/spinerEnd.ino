int Salida = 9, Entrada = 8;
boolean entrada = LOW;
boolean led = LOW;
int inicio = 0, medio = 0, fin = 0, wait = 0, contador = 0;

void setup() {
  pinMode(Entrada,INPUT);
  pinMode(Salida,OUTPUT);
   Serial.begin(9600);
}

void loop() {
   
  entrada = digitalRead(Entrada);
  inicio = millis();
  
  while(entrada == 1){
    
    if(contador == 1){
        Serial.print("Tiempo de espera entre clics:");
        Serial.println(contador);
        Serial.println(inicio-wait);
        contador = 0;
    }
    
    entrada = digitalRead(Entrada);
    
    if(!entrada){
      if(contador == 0){
        wait = millis();
      }
    }
      contador++;
   }
}

