#include <LiquidCrystal.h>

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String displayText = "Follow @stoiczfpv on IG!";

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  autoScroll(displayText);
}

void autoScroll(String text) {
  lcd.setCursor(16,0);
  lcd.autoscroll();
  
  for (int i = 0; i < displayText.length(); i++) {
    char c = displayText[i];
    Serial.println(c);
    lcd.print(c);
    delay(300);
  }
  
//  lcd.noAutoscroll();
//  lcd.clear();
}
