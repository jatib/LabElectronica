//InicialesMorse
int Pin=11;

void setup() {
  pinMode(Pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
M();
espacioLetra();
S();
espacioLetra();
B();
espacioPalabra();
}

void punto(){
  digitalWrite(Pin,1);
  delay(200);
  digitalWrite(Pin,0);
  delay(200);
}

void raya(){
  digitalWrite(Pin,1);
  delay(600);
  digitalWrite(Pin,0);
  delay(200);
}

void espacioLetra(){
  digitalWrite(Pin,0);
  delay(400);
}

void espacioPalabra(){
  digitalWrite(Pin,0);
  delay(800);
}

void R(){
    punto();
    raya();
    punto();
}
//mariana silva baca
void G(){
  raya();
  raya();
  punto();
}

void I(){
  punto();
  punto();
}

void S(){
  punto;
  punto;
  punto;
}

void B(){
  raya();
  punto();
  punto();
  punto();
}

void M(){
  raya();
  raya();
   }
