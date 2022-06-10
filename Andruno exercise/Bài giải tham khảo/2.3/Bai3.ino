int breakPoint1 = 1, breakPoint2 = 8;
int i;

void setup()
{
  pinMode(9, INPUT);
  for (i = 0; i < 9; i++)
    pinMode(i, OUTPUT);

  i=1;
}


void loop()
{
  if (digitalRead(9))
  {
    if (i == 8)
    {
      breakPoint2 = 8;
      breakPoint1 = 1;
      if (!digitalRead(9))
        return;
    }
    else
      for (i = breakPoint1; i <= 8; i++)
      {
        digitalWrite(i, 1);

        if (!digitalRead(9)||i==8)
        {
          breakPoint2 = i;
          breakPoint1 = 1;
          return;
        }
        delay(500);
      }
  }

  else
  {
    if (i == 1)
    {
      breakPoint1 = i;
      breakPoint2 = 8;
    }
    else
      for (i = breakPoint2; i >= 1; i--)
      {
        digitalWrite(i, 0);

        if (digitalRead(9)||i==1)
        {
          breakPoint1 = i;
          breakPoint2 = 8;
          return;
        }
        delay(100);
      }
  }

}
