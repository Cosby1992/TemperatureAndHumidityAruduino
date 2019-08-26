/////////////////////////////////// libraries ////////////////////////////////////
#include <LiquidCrystal.h>  // lcd library
#include <DHT.h>            // DHT (humidity, temperature sensor) labrary
//////////////////////////////////////////////////////////////////////////////////

// used for dht library method
#define DHTPIN 8            // DHT data pin is on digital pin 8 on the arduino uno
#define DHTTYPE DHT11       // DHT type is required for dht library method, my type is DHT11

// setting up lcd pins using library
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// setting up dht
DHT dht(DHTPIN, DHTTYPE); 

  byte temp;
  byte hum;
  int contrast = 90;


void setup() {
  
  //starting lcd and dht
  analogWrite(10, contrast);
  lcd.begin(16,2);
  dht.begin();
  
}

void loop() {
  
  delay(1000);

  lcd.clear();

  temp = dht.readTemperature();
  hum = dht.readHumidity();

    // Check if any reads failed and exit early (to try again)
  if (isnan(hum) || isnan(temp)) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Error");
    return;
  }

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);

  lcd.setCursor(0,1);
  lcd.print("Hum: ");
  lcd.print(hum);
  lcd.print("%");
  

}
