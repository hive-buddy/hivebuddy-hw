// temp&hum
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// mic
const int micpin = A1;
int mic;
const int baseline = 337;
int amplitude;

// pressure sensor
#define pressurePin A0


void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize the sensor
 
}

void loop() {
  unsigned long currentTime = millis();
  int hive_id = 1;
  // read humidity
  float humi = dht.readHumidity();
  // read temperature as Celsius
  float tempC = dht.readTemperature();

// read microphone
  mic = analogRead(micpin);
  amplitude = abs(mic - baseline);

  // read pressure sensor
  int pressure = analogRead(pressurePin);

  // check if any reads failed
  if (isnan(humi) || isnan(tempC) || isnan(amplitude) || isnan(pressurePin)) {
    Serial.println("Failed to read from sensor(s)!");
  } else {
    Serial.print(hive_id);
    Serial.print(";");

    Serial.print(currentTime);
    Serial.print(",");

    Serial.print(humi);
    Serial.print(",");

    Serial.print(tempC);
    Serial.print(",");

    Serial.print(amplitude);
    Serial.print(",");

    int sensorValue1 = analogRead(pressurePin); // Read value from sensor 1
    delay(10); // Small delay for stability
    int sensorValue2 = analogRead(pressurePin);
    delay(10); // Small delay for stability
    int sensorValue3 = analogRead(pressurePin);
    delay(10); // Small delay for stability
    int sensorValue4 = analogRead(pressurePin);
    int averageValue = (sensorValue1 + sensorValue2+sensorValue3+sensorValue4) / 4;

    Serial.println(averageValue);
    delay(500); // every one second the new data will be stored
  }
}

