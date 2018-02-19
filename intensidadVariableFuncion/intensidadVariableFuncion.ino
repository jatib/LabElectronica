int Pin = 11;

void setup() {
  pinMode(Pin,OUTPUT);
}

void loop() {
  for(int contador = 0; contador < 510; contador++) {
    digitalWrite(Pin,1);
    delayMicroseconds(20*(255-abs(255-contador)));
    digitalWrite(Pin,0);
    delayMicroseconds(20*abs(255-contador));
  }
}
