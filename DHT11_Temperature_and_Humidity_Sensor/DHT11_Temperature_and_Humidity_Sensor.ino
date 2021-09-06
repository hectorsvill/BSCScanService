#include <LiquidCrystal.h>
#include <DHT.h>

static const int rs = 7;
static const int en = 8;
static const int d4 = 9;
static const int d5 = 10;
static const int d6 = 11;
static const int d7 = 12;
static const int dht11Pin = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define sensorType DHT11

DHT HT(dht11Pin, sensorType);

float humidity;
float tempC;
float tempF;

bool deviceIsSet = false;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  HT.begin();
  delay(1000);
  deviceIsSet = true;
}

void loop() {
  if (deviceIsSet == false) {
    autoScroll("Setting up device.....");  
  } else {

    humidity = HT.readHumidity();
    tempC = HT.readTemperature();
    tempF = HT.readTemperature(true);
    String humidityStr = "H:" +  String(humidity) + "%";
    String tempCStr = "C:" + String(tempC);
    String tempFStr = "F:" + String(tempF);
    String logStr = humidityStr + " " + tempCStr + " " + tempFStr + "\n";
    Serial.print(logStr);

    lcd.setCursor(0,0);
    lcd.print("        ");
    lcd.setCursor(random(0,8),0);
    lcd.print(".");
    
    lcd.setCursor(8,0);
    lcd.print(humidityStr);
    
    lcd.setCursor(0,1);
    lcd.print(tempCStr);
    
    lcd.setCursor(8,1);
    lcd.print(tempFStr);
    
    delay(200);
  }
}


void autoScroll(String text) {
  lcd.setCursor(15,0);
  lcd.autoscroll();
  
  for (int i = 0; i < text.length(); i++) {
    char c = text[i];
    Serial.println(c);
    lcd.print(c);
    delay(200);
  }

  lcd.noAutoscroll();
  lcd.clear();
}
