void setup() {
  for (int i = 0; i < 11; i++)
    pinMode(i, OUTPUT);

}

void loop() {
  for (int i = 0; i < 11; i++)
    digitalWrite(i, 1);

  delay(1000);

  for (int i = 0; i < 11; i++)
    digitalWrite(i, 0);

  delay(1000);
}
