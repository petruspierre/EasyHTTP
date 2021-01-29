/* Hey!
 * This program will show to you how to make a simple GET request using EasyHTTP library.
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
  String response = http.get("/test");
  Serial.println(response);

  delay(3000);
}
