#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_AHTX0.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(9600);

  // OLED Init
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED init failed");
    while (1);
  }

  // AHT10 Init
  if (!aht.begin()) {
    Serial.println("AHT10 not found");
    while (1);
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Smart Thermometer");
  display.display();
  delay(1000);
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  float t = temp.temperature;
  float h = humidity.relative_humidity;

  display.clearDisplay();
  display.setTextSize(1);

  // Temperature
  display.setCursor(0, 0);
  display.print("Temp: ");
  display.print(t);
  display.println(" C");

  // Humidity
  display.setCursor(0, 18);
  display.print("Humidity: ");
  display.print(h);
  display.println(" %");

  // Icon Display (simple ASCII)
  display.setCursor(0, 39);
  if (t > 28) {
    display.println("Weather: Sunny");
  } else if (h > 70) {
    display.println("Weather: Humid");
  } else {
    display.println("Weather: Cloudy");
  }

  display.display();
  delay(2000);
}
