
void setup() {
  pinMode(9, INPUT);
  for (int i = 0; i < 9; i++)
    pinMode(i, OUTPUT);

}

void loop() {
  if(digitalRead(9))
  {
    digitalWrite(1,1);
    digitalWrite(2,1);
    digitalWrite(3,1);
    digitalWrite(4,1);
    digitalWrite(5,1);
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(8,1);
  }
  else
  {
    digitalWrite(1,0);
    digitalWrite(2,0);
    digitalWrite(3,0);
    digitalWrite(4,0);
    digitalWrite(5,0);
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,0);
  }
}
