void setup() 
{
  // put your setup code here, to run once:
  for (int i = 0; i < 9; i++)
    pinMode(i, OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 9; i++)
  {
      digitalWrite(i,1);
      delay(100);
  }

  for (int i = 8; i > -1; i--)
  {
      digitalWrite(i,0);
      delay(100);
  }
}
