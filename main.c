#include <Arduino.h>
#include <Wire.h>
 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define greenled A3
#define buzzer A2
#define redled A1

char input[12];
int count = 0;
 
int a;
int p1 = 0, p2 = 0, p3 = 0, p4 = 0;
int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
 
double total = 0;
int count_prod = 0;
 
void setup ()
{
  pinMode(6, INPUT_PULLUP);
  pinMode(greenled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(redled, OUTPUT);
 

   lcd.init();
  lcd.backlight();
  Wire.begin();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print(" AUTOMATIC BILL");
  delay (2000);
  lcd.setCursor(0, 1);
  lcd.print(" SHOPPING CART ");
  delay (2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WELCOME TO");
  delay (2000);
  lcd.setCursor(3, 1);
  lcd.print("SUPER MARKET");
  delay (2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Plz Add iTem");
}
 
void loop()
{
  count = 0;
  while (Serial.available() && count < 12)
  {
    input[count] = Serial.read();
    count++;
    delay(5);
  }
  int a = digitalRead(6);
 
  if ((strncmp(input, "2700875A344B", 12) == 0) && (a == 1))
  { 
    lcd.setCursor(0, 0);
    lcd.print("Butter Added       ");
    lcd.setCursor(0, 1);
    lcd.print("Price :- 10.00      ");
    p1++;
    digitalWrite(redled, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(greenled, LOW);
    delay(2000);
    total = total + 10.00;
    count_prod++;
    digitalWrite(redled, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenled, HIGH);
 
  }
  else if ((strncmp(input, "2700874A344B", 12) == 0) && (a == 0))
  {
    if (p1 > 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Butter Removed!!!        ");
      digitalWrite(redled, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(greenled, LOW);
      delay(2000);
      p1--;
      total = total - 10.00;
      count_prod--;
      lcd.clear();
      digitalWrite(redled, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(greenled, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Total Price :-");
 
      lcd.setCursor(0, 1);
      lcd.print(total);
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Not in cart!!!        ");
      digitalWrite(redled, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(greenled, HIGH);
      delay(2000);
      digitalWrite(redled, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(greenled, LOW);
      lcd.clear();
    }
  }
 
 
  if ((strncmp(input, "4000935ABAC5", 12) == 0) && (a == 1))
  {
    lcd.setCursor(0, 0);
    lcd.print("Milk Added       ");
    lcd.setCursor(0, 1);
    lcd.print("Price :- 20.00      ");
    p2++;
    digitalWrite(redled, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(greenled, LOW);
    delay(2000);
    total = total + 20.00;
    count_prod++;
    digitalWrite(redled, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenled, HIGH);
 
  }
 
  else if ((strncmp(input, "4000935ABAC5", 12) == 0) && (a == 0))
  {
    if (p2 > 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Milk Removed!!!        ");
      digitalWrite(redled, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(greenled, LOW);
      delay(2000);
      p2--;
      total = total - 20.00;
      count_prod--;
      lcd.clear();
      digitalWrite(redled, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(greenled, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Total Price :-");
      lcd.setCursor(0, 1);
      lcd.print(total);
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Not in cart!!!        ");
      digitalWrite(redled, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(greenled, HIGH);
      delay(2000);
      digitalWrite(redled, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(greenled, LOW);
      lcd.clear();
    }
  }
 
 
if ((strncmp(input, "030234DA0F2", 12) == 0) && (a == 1))
  {
    lcd.setCursor(0, 0);
    lcd.print("Tea Added       ");
    lcd.setCursor(0, 1);
    lcd.print("Price :- 25.00      ");
    p3++;
    digitalWrite(redled, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(greenled, LOW);
    delay(2000);
    total = total + 25.00;
    count_prod++;
    digitalWrite(redled, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(greenled, HIGH);
 
  }
 
  else if ((strncmp(input, "0300234DA0F2", 12) == 0) && (a == 0))
  {
    if (p3 > 0)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Tea Removed!!!        ");
      digitalWrite(redled, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(greenled, LOW);
      delay(2000);
      p3--;
      total = total - 25.00;
      count_prod--;
      lcd.clear();
      digitalWrite(redled, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(greenled, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Total Price :-");
      lcd.setCursor(0, 1);
      lcd.print(total);
    }
    else
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Not in cart!!!        ");
      digitalWrite(redled, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(greenled, HIGH);
      delay(2000);
      digitalWrite(redled, LOW);
      digitalWrite(buzzer, LOW);
      digitalWrite(greenled, LOW);
      lcd.clear();
    }
  }
}
