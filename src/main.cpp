#include <Arduino.h>

#define ADC_PIN 4
#define ADC_BITS 12
#define ADC_MAX (pow(2, ADC_BITS) - 1)

void setup()
{
  Serial.begin(115200);
  analogReadResolution(ADC_BITS);
  analogSetPinAttenuation(ADC_PIN, ADC_11db);
}

void loop()
{
  int rawValue = analogRead(ADC_PIN);
  float calcVoltage = (rawValue * 3.3) / ADC_MAX;
  float voltageMv = analogReadMilliVolts(ADC_PIN);
  float voltageMvtoV = voltageMv / 1000;
  float diff = voltageMvtoV - calcVoltage;

  if (diff < 0)
  {
    diff = diff * -1;
  }

  float errorPercent = (diff / voltageMvtoV) * 100;

  Serial.println("ADC MAX: " + String(ADC_MAX));
  Serial.println("RAW ADC Value: " + String(rawValue));
  Serial.println("Calculated voltage: " + String(calcVoltage));
  Serial.println("Calculated voltage with calibration: " + String(voltageMv));
  Serial.println("Difference in millivolts: " + String(diff * 1000));
  Serial.println("Difference in percent: " + String(errorPercent) + String("%"));
  Serial.println("==============================");
  delay(1000);
}
