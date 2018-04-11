int Rojo = 8;
int Verde = 9;
int Azul = 10;

void setup() {
  pinMode(Rojo, OUTPUT);
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);

}


void EstablecerColor(int R, int G, int B) {

  analogWrite(Rojo, 255 - R);
  analogWrite(Verde, 255 - G);
  analogWrite(Azul, 255 - B);

}

void loop() {

  //Se representan colores pseudoaleatorios en el LED RGB mediante el
  //uso de la instrución random(min,max);.
  EstablecerColor(random(0, 255), random(0, 255), random(0, 255));

  //Se utiliza un delay para que de tiempo algo observador a apreciar
  //los colores.
  delay(1000);

}
