void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 1; i < 12; i++)
    pinMode(i, OUTPUT);
}

void loop()
{
  Serial.print("loc value: ");
  float ratio = (float)analogRead(A0) / 1024 * 10;
  int loc = (int)ratio;
  Serial.println(loc);

  for (int i = 2; i <= ratio; i++)
    digitalWrite(i, 1);
  for (int i = ratio + 1; i <= 11; i++)
    digitalWrite(i, 0);

  //delay(99);
}
