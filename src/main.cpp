#include <Arduino.h>

#define ADC_PIN 4
#define ADC_MAX 4095

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  int rawValue = analogRead(ADC_PIN);
  float calcVoltage = (rawValue * 3.3) / ADC_MAX;
  float voltageMv = analogReadMilliVolts(ADC_PIN);
  float voltageMvtoV = voltageMv / 1000;
  float diff = voltageMvtoV - calcVoltage;
  Serial.println("RAW ADC Value: " + String(rawValue));
  Serial.println("Calculated voltage: " + String(calcVoltage));
  Serial.println("Calculated voltage with calibration: " + String(voltageMv));
  Serial.println("Difference in millivolts: " + String(diff * 1000));
  Serial.println("==============================");
  delay(1000);
}
