int Pin = 11;

void setup() {
  pinMode(Pin,OUTPUT);

}

void loop() {
  for(int contador = 0; contador < 255; contador++) {
    digitalWrite(Pin,1);
    delayMicroseconds(20*contador);
    digitalWrite(Pin,0);
    delayMicroseconds(20*256-10*contador);
  }
}
