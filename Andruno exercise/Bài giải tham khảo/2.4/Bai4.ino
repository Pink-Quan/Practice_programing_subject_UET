
void setup() {
  pinMode(1, INPUT);
  pinMode(0, OUTPUT);
  digitalWrite(0,1);
}

int status=1;

void loop() {
  if(digitalRead(9))
  {
    digitalWrite(1,status*(-1));
    delay(200);
  }
}
