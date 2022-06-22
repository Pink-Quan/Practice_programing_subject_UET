
void setup() {
  pinMode(1, INPUT);
  pinMode(0, OUTPUT);
  digitalWrite(0,1);
}

int status=1;

void loop() {
  if(digitalRead(1))
  {
    digitalWrite(0,status*(-1));
    delay(200);
  }
}
