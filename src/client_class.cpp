#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include "client_class.h"

//Your IP address or domain name with URL path
//const char* serverNameTemp = "http://192.168.4.1/temperature";
//const char* serverNameHumi = "http://192.168.4.1/humidity";
//const char* serverNamePres = "http://192.168.4.1/pressure";
//const char* serverNameData = "http://192.168.4.1/data";

//String temperature;
//String humidity;
//String pressure;
//String data;

//unsigned long previousMillis = 0;
//const long interval = 100; 

String WifiClient::http_requests(String* result)
{
  result[0] = WifiClient::http_get_request(serverNameTemp);
  result[1] = WifiClient::http_get_request(serverNameData);
//  result[1] = WifiClient::http_get_request(serverNameHumi);
//  result[2] = WifiClient::http_get_request(serverNamePres);
//  result[3] = WifiClient::http_get_request(serverNameData);

  return WifiClient::concat_result(result);
}

String WifiClient::concat_result(String* result)
{
  String resultString;
  for(int i=0; i<sizeof(result); i++)
  {
    resultString = resultString + ' ' + result[i];
  }

  return resultString;
}

String WifiClient::http_get_request(const char* serverName) {
  HTTPClient http;
    
  http.begin(serverName);
  
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  http.end();

  return payload;
}