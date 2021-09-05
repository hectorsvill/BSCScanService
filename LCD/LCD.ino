#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
void setup() {
  lcd.begin(16, 2);
}

bool completed = false;
void loop() {
  if (completed == false) {
    for (int i = 0; i < 1234; i++) {
      lcd.clear();
      lcd.setCursor(random(1,15),0);
      lcd.print(random(1,1000));
      lcd.setCursor(random(1,15),1);
      lcd.print(random(1,300));
      delay(200);
    }
    
    completed = true;
    lcd.clear();
  }
  
  lcd.setCursor(5,1);
  lcd.print("Complete...");
}
