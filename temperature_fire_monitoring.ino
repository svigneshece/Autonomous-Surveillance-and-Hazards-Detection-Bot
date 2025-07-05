

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define sensor and component pins
#define DHTPIN 4          // Temperature sensor pin
#define DHTTYPE DHT11     // DHT11 or DHT22
DHT dht(DHTPIN, DHTTYPE);

#define FLAME_SENSOR 19   // Flame sensor digital pin
#define MQ3_SENSOR 36     // MQ3 analog pin
#define BUZZER 23         // Buzzer pin

#define RED 16            // RGB LED Red pin
#define GREEN 17          // RGB LED Green pin
#define BLUE 18           // RGB LED Blue pin

// LCD Setup
LiquidCrystal_I2C lcd1(0x27, 16, 2); // First LCD (Temperature & Gas)
LiquidCrystal_I2C lcd2(0x26, 16, 2); // Second LCD (Fire & Alerts)

// Function to control RGB LED
void setRGB(int r, int g, int b) {
    digitalWrite(RED, r);
    digitalWrite(GREEN, g);
    digitalWrite(BLUE, b);
}

void setup() {
    Serial.begin(115200);
    dht.begin();

    pinMode(FLAME_SENSOR, INPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);

    lcd1.init(); lcd1.backlight();
    lcd2.init(); lcd2.backlight();

    // Initial LCD messages
    lcd1.setCursor(0, 0);
    lcd1.print("Initializing...");
    lcd2.setCursor(0, 0);
    lcd2.print("System Ready");
    delay(2000);
    lcd1.clear();
    lcd2.clear();
}

void loop() {
    float temp = dht.readTemperature();
    int mq3_value = analogRead(MQ3_SENSOR);
    int flame_detected = digitalRead(FLAME_SENSOR);

    Serial.print("Temp: "); Serial.print(temp); Serial.print(" C | ");
    Serial.print("Gas: "); Serial.print(mq3_value); Serial.print(" | ");
    Serial.print("Flame: "); Serial.println(flame_detected == LOW ? "Detected!" : "No Fire");

    // Display Temperature
    lcd1.setCursor(0, 0);
    lcd1.print("Temp: "); lcd1.print(temp); lcd1.print(" C ");

    // Display Gas/Alcohol Level
    lcd1.setCursor(0, 1);
    lcd1.print("Gas: "); lcd1.print(mq3_value); lcd1.print("  ");

    // Control RGB LED Based on Temperature
    if (temp < 20) {
        setRGB(0, 0, 1);  // Blue (Cool)
    } 
    else if (temp >= 20 && temp < 30) {
        setRGB(0, 1, 0);  // Green (Normal)
    } 
    else if (temp >= 30 && temp < 40) {
        setRGB(1, 1, 0);  // Orange (Warm)
    } 
    else {
        setRGB(1, 0, 0);  // Red (High Temp)
    }

    // Display Fire Status
    lcd2.setCursor(0, 0);
    if (flame_detected == LOW) { 
        lcd2.print("Fire Detected! ");
        digitalWrite(BUZZER, HIGH);
        setRGB(1, 0, 0);  // Red Alert
    } else {
        lcd2.print("No Fire        ");
        digitalWrite(BUZZER, LOW);
    }

    // Display Gas Alert if needed
    lcd2.setCursor(0, 1);
    if (mq3_value > 400) {
        lcd2.print("Gas High Alert!");
        setRGB(1, 0, 1);  // Purple for Gas Alert
        digitalWrite(BUZZER, HIGH);
    } else {
        lcd2.print("Gas Normal     ");
    }

    delay(2000);
}
