#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ESP8266HTTPClient.h>

#define BLYNK_TEMPLATE_ID "TMPL3_W99DzEu"
#define BLYNK_TEMPLATE_NAME "led x esp8266"
#define BLYNK_AUTH_TOKEN "g6kPqq3-eciadXJJ1FERCn6g4-9-nDcH"

char ssid[] = "ECED";
char pass[] = "eced@tiet1";

String apiKey = "4L4T1ZUKW7T6SBER";
String server = "http://api.thingspeak.com/update";

WiFiClient client;
unsigned long lastUploadTime = 0;

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi Connected. Ready to control LED & log to ThingSpeak.");
}

BLYNK_WRITE(V0) {
  int value = param.asInt();
  Serial.println(value);
}

void loop() {
  Blynk.run();
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    data.trim();
    if (data.length() > 0) {
      String probe = data;
      if (WiFi.status() == WL_CONNECTED && millis() - lastUploadTime >= 2000) {
        HTTPClient http;
        String url = server + "?api_key=" + apiKey + "&field1=" + probe;
        http.begin(client, url);
        int httpCode = http.GET();
        http.end();
        Serial.println("Logged to ThingSpeak → Probe Temp: " + probe + " °C [Code: " + String(httpCode) + "]");
        lastUploadTime = millis();
      }
    }
  }
}