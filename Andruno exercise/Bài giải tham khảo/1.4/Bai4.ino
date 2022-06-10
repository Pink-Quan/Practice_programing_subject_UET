void setup()
{
  // put your setup code here, to run once:
  for (int i = 0; i < 9; i++)
    pinMode(i, OUTPUT);
}

int light=1;

void loop()
{
  // put your main code here, to run repeatedly:
  for(int i=8;i>=light;i--)
  {
    if(i!=8)
      digitalWrite(i+1,0);
    digitalWrite(i,1);
    delay(100);
  }
  light++;
  if(light==8)
    light=1;
}
