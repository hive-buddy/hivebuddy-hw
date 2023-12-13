#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

#include <HX711_ADC.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif

int sound_sensor = A0; //assign to pin A2
const int HX711_dout = 4; //mcu > HX711 dout pin
const int HX711_sck = 5; //mcu > HX711 sck pin
DHT dht(DHTPIN, DHTTYPE);

HX711_ADC LoadCell(HX711_dout, HX711_sck);

const int calVal_eepromAdress = 0;
unsigned long t = 0;

void setup() {
  Serial.begin(9600);
  dht.begin(); // initialize the sensor

  LoadCell.begin();
  LoadCell.setReverseOutput(); //uncomment to turn a negative output value to positive
  unsigned long stabilizingtime = 2000; // preciscion right after power-up can be improved by adding a few seconds of stabilizing time
  boolean _tare = true; //set this to false if you don't want tare to be performed in the next step
  LoadCell.start(stabilizingtime, _tare);
  if (LoadCell.getTareTimeoutFlag() || LoadCell.getSignalTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else {
    LoadCell.setCalFactor(1.0); // user set calibration value (float), initial value 1.0 may be used for this sketch
    Serial.println("Startup is complete");
  }
  while (!LoadCell.update());
  // calibrate(); //start calibration procedure
}

void loop() {
    static boolean newDataReady = 0;
  const int serialPrintInterval = 0; //increase value to slow down serial print activity

  unsigned long currentTime = millis();
  // wait a few seconds between measurements.
  delay(2000);
    int hive_id = 1;
  // read humidity
  float humi = dht.readHumidity();
  // read temperature as Celsius
  float tempC = dht.readTemperature();
  int soundValue = 0; //create variable to store many different readings
  for (int i = 0; i < 32; i++) //create a for loop to read
  {
    soundValue += analogRead(sound_sensor);
  } //read the sound sensor

  soundValue >>= 5; //bitshift operation

  // check if last tare operation is complete
  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
  }


  // check if any reads failed
  if (isnan(humi) || isnan(tempC) || isnan(soundValue)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print(hive_id);
    Serial.print(";");

    Serial.print(currentTime);
    Serial.print(",");

    Serial.print(humi);
    Serial.print(",");

    Serial.print(tempC);
    Serial.print(",");

    Serial.print(soundValue); //print the value of sound sensor
    Serial.print(",");

      // check for new data/start next conversion:
  if (LoadCell.update()) newDataReady = true;

  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell.getData();
      Serial.println(i);
      newDataReady = 0;
      t = millis();
    }
  }

  }
}