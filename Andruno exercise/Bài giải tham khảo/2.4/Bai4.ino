int status=1;

void setup() {
  pinMode(1, INPUT);
  pinMode(0, OUTPUT);
  digitalWrite(0,status);
}

void loop() {
  if(digitalRead(1))
  {
    status=(status==1?0:1);
    digitalWrite(0,status);
    delay(400);
  }
}
