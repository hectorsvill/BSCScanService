#include <LiquidCrystal.h>

static const int rs = 7;
static const int en = 8;
static const int d4 = 9;
static const int d5 = 10;
static const int d6 = 11;
static const int d7 = 12;
static const int DHT_SENSOR_PIN = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float tempeture;
float humidity;

bool deviceIsSet = false;
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  if (deviceIsSet == false) {
    autoScroll("Setting up device.....");  
  } else {
    
  }
}


void autoScroll(String text) {
  lcd.setCursor(15,0);
  lcd.autoscroll();
  
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
    Serial.println(c);
    lcd.print(c);
    delay(300);
  }

  lcd.noAutoscroll();
  lcd.clear();
}
