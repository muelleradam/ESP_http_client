#include <Arduino.h>

class WifiClient{
const char* serverNameTemp = "http://192.168.4.1/temperature";
const char* serverNameHumi = "http://192.168.4.1/humidity";
const char* serverNamePres = "http://192.168.4.1/pressure";
const char* serverNameData = "http://192.168.4.1/data";
String temperature;
String humidity;
String pressure;
String data;
String concat_result(String* result);
String http_get_request(const char* serverName);
public:
  String http_requests(String* result);
};