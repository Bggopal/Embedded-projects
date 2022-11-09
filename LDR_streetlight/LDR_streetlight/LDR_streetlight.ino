int LDR_input = A0; 
int output_pin = 13; 
int light_value = 0;

void setup()
{
pinMode(output_pin, OUTPUT);
}

void loop() 
{
  light_value = analogRead(LDR_input);
  light_value = 100 - light_value/10.24;
  
  if(light_value>=90)
  {
    digitalWrite(output_pin, LOW);
    }
  else
  {
    digitalWrite(output_pin, HIGH);
    }
  delay(500);
}
