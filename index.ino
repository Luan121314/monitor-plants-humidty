int pinSensorHumidity = A0;
int value = 0;
int intervalLoop = 3600000; //Interval of publish is 1 hours

void setup() {
  Serial.begin(115200);
  String ssid     = "myssid";
  String password = "mypassword";
  setupWIFI(ssid, password);
  pinMode(pinSensorHumidity, INPUT);

}

void loop() {
  float readSensor = analogRead(pinSensorHumidity); 
  value = map(readSensor, 0, 1023, 100, 0);

  uint32_t espID = ESP.getChipId();
  String body = "{\"unity\":\"%\",\"deviceId\":" +String(espID)+ ",\"value\":" +String(value)+ "}";
  publish(body);
  delay(intervalLoop);
}
