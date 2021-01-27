#ifndef EasyHTTP_h
#define EasyHTTP_h

#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoJson.h>
#include <HTTPClient.h>

class EasyHTTP {
  public: 
    EasyHTTP(char* ssid, char* password);
    void connectWiFi();
    void setBaseURL(String baseURL);
    int getLastCode();
    String get(String path);
    String post(String path, String payload);
    String post(String path);

    int lastCode;
  private:
    char* _ssid;
    char* _password;
    String _baseURL;
};

#endif
