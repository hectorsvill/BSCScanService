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
//  lcd.print("earth is gray");
}

void loop() {
//  blinkLCD(300);
  autoScroll(displayText);
}

void autoScroll(String text) {
  lcd.setCursor(15,0);
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

void blinkLCD(int delayTime) {
  lcd.setCursor(0,0);
  lcd.noBlink();
  delay(delayTime);
  lcd.blink();
  delay(delayTime);
}

void blinkCursor(int delayTime) {
  lcd.noCursor();
  delay(delayTime);
  lcd.cursor();
  delay(delayTime);
}
