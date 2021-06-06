#include <WiFiClientSecure.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

HTTPClient http;
WiFiClientSecure clientWIFI;


void publish(String body){

  if ((WiFi.status() != WL_CONNECTED)) {
    Serial.println("WIFI not connected");
    return;
  }
    clientWIFI.setInsecure();

    const char* hostUrl = "urlhost";

    Serial.print("[HTTP] begin...\n");
    if (http.begin(clientWIFI, hostUrl)) {  // HTTP
      http.addHeader("Content-Type", "application/json");

      Serial.print("[HTTP] POST...\nResponse: ");
      int httpCode = http.POST(body);

      if (httpCode > 0) {
        Serial.printf("[HTTP] POST... code: %d\n", httpCode);

          // if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(body);
        // }
      } else {
          Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}