void setup()
{
  pinMode(9, INPUT);
  for (int i = 0; i < 9; i++)
    pinMode(i, OUTPUT);
}

bool onClick = false;
int effect = 2;
void Effect0();
void Effect1();
void Effect2();
void OffAll();

void loop()
{
  switch (effect)
  {
    case 0:
      Effect0();
      break;
    case 1:
      Effect1();
      break;
    case 2:
      Effect2();
      break;
  }
}

void Effect0()
{
  if (onClick)
  {
    delay(300);
    onClick = false;
  }

  for (int i = 0; i < 11; i++)
    digitalWrite(i, 1);
  if (digitalRead(9))
  {
    effect = 1;
    onClick = true;
    return;
  }
  delay(100);
  for (int i = 0; i < 11; i++)
    digitalWrite(i, 0);
  if (digitalRead(9))
  {
    effect = 1;
    onClick = true;
    return;
  }
  delay(100);
}

void Effect1()
{
  OffAll();
  if (onClick)
  {
    delay(300);
    onClick = false;
  }
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(i, 1);

    if (digitalRead(9))
    {
      effect = 2;
      onClick = true;
      return;
    }
    delay(100);
  }

  for (int i = 8; i > -1; i--)
  {
    digitalWrite(i, 0);

    if (digitalRead(9))
    {
      effect = 2;
      onClick = true;
      return;
    }
    delay(100);
  }
}

void Effect2()
{
  OffAll();
  if (onClick)
  {
    delay(300);
    onClick = false;
  }
  for (int i = 0; i < 9; i++)
  {
    if (i > 0)
      digitalWrite(i - 1, 0);
    digitalWrite(i, 1);

    if (digitalRead(9))
    {
      effect = 0;
      onClick = true;
      return;
    }
    delay(100);
  }

  for (int i = 8; i > 0; i--)
  {
    if (i < 8)
      digitalWrite(i + 1, 0);
    digitalWrite(i, 1);

    if (digitalRead(9))
    {
      effect = 0;
      onClick = true;
      return;
    }
    delay(100);
  }
}

void OffAll()
{
  for (int i = 0; i < 9; i++)
    digitalWrite(i, 0);
}
