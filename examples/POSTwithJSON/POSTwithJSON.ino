/* Hey!
 * This program will show to you how to make a simple POST request sending
 * a JSON using EasyHTTP library.
 * ArduinoJSON is a dependency!
 */

#include <EasyHTTP.h>

// Network info
char* ssid = "Your SSID";
char* password = "Your Password";

String baseURL = "http://yourapiurl.com";

EasyHTTP http(ssid, password);

void setup() {
  
  Serial.begin(115200);
  http.connectWiFi();
  http.setBaseURL(baseURL);

}

void loop() {
  DynamicJsonDocument doc(32);
  String payload = "";

  doc["sensor"] = "gps";
  serializeJson(doc, payload);
  
  String response = http.post("/test", payload);
  Serial.println(response);

  delay(3000);
}
