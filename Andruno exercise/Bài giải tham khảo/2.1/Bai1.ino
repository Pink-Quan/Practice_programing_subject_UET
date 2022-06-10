void setup()
{
  pinMode(9,INPUT);
  for (int i = 0; i < 9; i++)
    pinMode(i, OUTPUT);
}

void loop()
{
  if(digitalRead(9))
  
    for (int i = 0; i < 9; i++)
      digitalWrite(i, 1);
  else
    for (int i = 0; i < 9; i++)
      digitalWrite(i, 0);
}
