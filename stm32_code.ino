#include <OneWire.h>
#include <DallasTemperature.h>

#define PROBE_PIN PB8
#define LED_PIN PB4

OneWire oneWire(PROBE_PIN);
DallasTemperature ds18b20(&oneWire);

bool manualSwitch = true;
unsigned long lastSendTime = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  ds18b20.begin();
}

void loop() {
  while (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    if (command == "1") {
      manualSwitch = true;
    } else if (command == "0") {
      manualSwitch = false;
      digitalWrite(LED_PIN, LOW);
    }
  }
  ds18b20.requestTemperatures();
  float probeTemp = ds18b20.getTempCByIndex(0);
  if (manualSwitch && !isnan(probeTemp)) {
    if (probeTemp < 25) {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }
  if (!isnan(probeTemp)) {
    if (millis() - lastSendTime >= 2000) {
      Serial.println(probeTemp);
      lastSendTime = millis();
    }
  }
}