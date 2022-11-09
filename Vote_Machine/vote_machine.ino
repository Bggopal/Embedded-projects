

#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define sw1 15
#define sw2 16
#define sw3 17
#define sw4 18
#define sw5 19

const int buzz = 9;

void buzz_sound ();

int vote1 = 0;
int vote2 = 0;
int vote3 = 0;
int vote4 = 0;

void setup()
{
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
  pinMode(sw5, INPUT);
  pinMode(buzz, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Voting Machine");
  buzz_sound();
  digitalWrite(sw1, HIGH);
  digitalWrite(sw2, HIGH);
  digitalWrite(sw3, HIGH);
  digitalWrite(sw4, HIGH);
  digitalWrite(sw5, HIGH);
  lcd.clear();
}
void loop()
{
  lcd.setCursor(0, 0);
  lcd.print("ABC");
  lcd.setCursor(0, 1);
  lcd.print("___");
  lcd.setCursor(4, 0);
  lcd.print("DEF");
  lcd.setCursor(4, 1);
  lcd.print("___");
  lcd.setCursor(8, 0);
  lcd.print("GHI");
  lcd.setCursor(8, 1);
  lcd.print("___");
  lcd.setCursor(12, 0);
  lcd.print("JKL");
  lcd.setCursor(12, 1);
  lcd.print("___");
  if (digitalRead(sw1) == 0)
  {
    buzz_sound();
    vote1++;
    while (digitalRead(sw1) == 0);
  }
  if (digitalRead(sw2) == 0)
  {
    buzz_sound();
    vote2++;
    while (digitalRead(sw2) == 0);
  }
  if (digitalRead(sw3) == 0)
  {
    buzz_sound();
    vote3++;
    while (digitalRead(sw3) == 0);
  }
  if (digitalRead(sw4) == 0)
  {
    buzz_sound();
    vote4++;
    while (digitalRead(sw4) == 0);
  }
  if (digitalRead(sw5) == 0)
  {
    int vote = vote1 + vote2 + vote3 + vote4;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ABC");
    lcd.setCursor(1, 1);
    lcd.print(vote1);
    lcd.setCursor(4, 0);
    lcd.print("DEF");
    lcd.setCursor(5, 1);
    lcd.print(vote2);
    lcd.setCursor(8, 0);
    lcd.print("GHI");
    lcd.setCursor(9, 1);
    lcd.print(vote3);
    lcd.setCursor(12, 0);
    lcd.print("JKL");
    lcd.setCursor(13, 1);
    lcd.print(vote4);
    delay(1000);
    lcd.clear();

    if (vote)
    {
      if ((vote1 > vote2 && vote1 > vote3 && vote1 > vote4))
      {
        lcd.clear();
        lcd.print("ABC wins with");
        lcd.setCursor(0, 1);
        lcd.print(vote1);
        lcd.setCursor(4, 1);
        lcd.print("votes"); delay(2000);
        lcd.clear();
      }
      else if ((vote2 > vote1 && vote2 > vote3 && vote2 > vote4))
      {
        lcd.clear();
        lcd.print("DEF wins with");
        lcd.setCursor(0, 1);
        lcd.print(vote2);
        lcd.setCursor(4, 1);
        lcd.print("votes"); delay(2000);
        lcd.clear();
      }
      else if ((vote3 > vote1 && vote3 > vote2 && vote3 > vote4))
      {
        lcd.clear();
        lcd.print("GHI wins with");
        lcd.setCursor(0, 1);
        lcd.print(vote3);
        lcd.setCursor(4, 1);
        lcd.print("votes"); delay(2000);
        lcd.clear();
      }
      else if (vote4 > vote1 && vote4 > vote2 && vote4 > vote3)
      {
        lcd.setCursor(0, 0);
        lcd.clear();
        lcd.print("JKL wins with");
        lcd.setCursor(0, 1);
        lcd.print(vote4);
        lcd.setCursor(4, 1);
        lcd.print("votes");
        delay(2000);
        lcd.clear();
      }

      else
      {
        lcd.clear();
        lcd.print("   Tie Up Or   ");
        lcd.setCursor(0, 1);
        lcd.print("   No Result   ");
        delay(1000);
        lcd.clear();
      }

    }
    else
    {
      lcd.clear();
      lcd.print("No Voting....");
      delay(1000);
      lcd.clear();
    }
    vote1 = 0; vote2 = 0; vote3 = 0; vote4 = 0, vote = 0;
    lcd.clear();
  }

}

void buzz_sound ()
  {
  tone(buzz, 1000);
  delay(100);
  noTone(buzz);
  }
