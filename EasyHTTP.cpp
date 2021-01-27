#include "EasyHTTP.h"

EasyHTTP::EasyHTTP(char* ssid, char* password) {
  _ssid  = ssid;
  _password  = password;
}

void EasyHTTP::connectWiFi() {
  Serial.print("[EasyHTTP] Connecting to: ");
  Serial.println(_ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(_ssid, _password);
  
  while(WiFi.status() != WL_CONNECTED){
    Serial.print("|");
    delay(200);
  }
  Serial.println();
  Serial.println("[EasyHTTP] Suscessfully connected.");
}

void EasyHTTP::setBaseURL(String baseURL) {
  _baseURL = baseURL;
}

String EasyHTTP::get(String path) {
  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    String url = _baseURL + path;

    http.begin(url);
    int httpCode = http.GET();
    String response = "";

    if(httpCode > 0) {
      response = http.getString();
      DynamicJsonDocument doc(32);
      deserializeJson(doc, response);
      lastCode = httpCode;
    }
    else {
      Serial.println("[EasyHTTP] Error on HTTP request");
    }
    Serial.println("[EasyHTTP] GET " + url + " " + httpCode);
    http.end();

    return response;
  } else {
    Serial.println("[EasyHTTP] Error on WiFi connection");
  }
}

String EasyHTTP::post(String path, String payload) {
  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    String url = _baseURL + path;

    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    int httpCode = http.POST(payload);
    String response = "";

    if(httpCode > 0) {
      response = http.getString();
      DynamicJsonDocument doc(32);
      deserializeJson(doc, response);
      lastCode = httpCode;
    }
    else {
      Serial.println("[EasyHTTP] Error on HTTP request");
    }
    Serial.println("[EasyHTTP] POST " + url + " " + httpCode);
    http.end();

    return response;
  } else {
    Serial.println("[EasyHTTP] Error on WiFi connection");
  }
}

String EasyHTTP::post(String path) {
  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    String url = _baseURL + path;

    http.begin(url);
    http.addHeader("Content-Type", "text/plain");

    int httpCode = http.POST("");
    String response = "";

    if(httpCode > 0) {
      response = http.getString();
      DynamicJsonDocument doc(32);
      deserializeJson(doc, response);
      lastCode = httpCode;
    }
    else {
      Serial.println("[EasyHTTP] Error on HTTP request");
    }
    Serial.println("[EasyHTTP] POST " + url + " " + httpCode);
    http.end();

    return response;
  } else {
    Serial.println("[EasyHTTP] Error on WiFi connection");
  }
}
