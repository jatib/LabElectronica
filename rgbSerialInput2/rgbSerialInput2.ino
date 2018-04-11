int Rojo = 8;
int Verde = 9;
int Azul = 10;

void setup() {
  pinMode(Rojo, OUTPUT);
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  analogWrite(Rojo, random(0,255));
  analogWrite(Verde,random(0,255));
  analogWrite(Azul, random(0,255));
  delay(1000);

}
