#include <ESP8266WiFi.h>

void setupWIFI(String ssid, String password){
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  
}