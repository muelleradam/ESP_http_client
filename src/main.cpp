#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include "client_class.h"

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

//Your IP address or domain name with URL path
//const char* serverNameTemp = "http://192.168.4.1/temperature";
//const char* serverNameHumi = "http://192.168.4.1/humidity";
//const char* serverNamePres = "http://192.168.4.1/pressure";
//const char* serverNameData = "http://192.168.4.1/data";

//String temperature;
//String humidity;
//String pressure;
//String data;

unsigned long previousMillis = 0;
const long interval = 100; 

//String httpGETRequest(const char* serverName);

WifiClient wifi_client;

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  String result[5];

  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED ){ 
//      temperature = httpGETRequest(serverNameTemp);
//      humidity = httpGETRequest(serverNameHumi);
//      pressure = httpGETRequest(serverNamePres);
//      data = httpGETRequest(serverNameData);
      //Serial.println("Temperature: " + temperature + " *C - Humidity: " + humidity + " % - Pressure: " + pressure + " hPa");
      //Serial.println("Data: " + data);
//      Serial.println(data + ' ' + temperature + ' ' + humidity + ' ' + pressure);
      Serial.println(wifi_client.http_requests(result));
      // save the last HTTP GET Request
      previousMillis = currentMillis;
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
}

//String httpGETRequest(const char* serverName) {
//  HTTPClient http;
//    
//  http.begin(serverName);
//  
//  int httpResponseCode = http.GET();
//  
//  String payload = "--"; 
//  
//  if (httpResponseCode>0) {
//    payload = http.getString();
//  }
//  else {
//    Serial.print("Error code: ");
//    Serial.println(httpResponseCode);
//  }
//  http.end();
//
//  return payload;
//}