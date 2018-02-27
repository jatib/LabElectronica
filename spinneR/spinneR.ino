int Salida = 11, Entrada = 12, Salida2 = 10;
boolean entrada = LOW;
boolean led = LOW;
int tiempo;
float distancia;
int inicio = 0, medio = 0, fin = 0, wait = 0, contador = 0;

void setup() {
  pinMode(Entrada,INPUT);
  pinMode(Salida,OUTPUT);
  pinMode(Salida2, OUTPUT);
   Serial.begin(9600);
}

void loop() {
  digitalWrite(Salida, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Salida, LOW);
  
  tiempo = pulseIn(Entrada, HIGH);
  distancia = float(tiempo*0.0340/2);
  Serial.print("Tiempo:");
  Serial.print(tiempo);
  Serial.println(" ms");
  Serial.print("Distancia:");
  Serial.print(distancia);
  Serial.println(" cm");
  delay(10);
  if(distancia > 10 && distancia < 20){
    digitalWrite(Salida2,!led);
  }else{
    digitalWrite(Salida2,led);
 }

}

