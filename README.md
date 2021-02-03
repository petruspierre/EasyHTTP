# EasyHTTP

An ESP32 library to facilitate the execution of HTTP requests 🌐

# Summary

- [Getting started](#getting_started)
- [Examples](#examples)
- ~~API documentation~~

# <a name="getting_started"></a>Getting started

## Installation
First you need to install this library. So follow the steps:

#### Manual installation
- Download this repository in .ZIP format by clicking [here](https://github.com/petruspierre/EasyHTTP/archive/master.zip)
- Copy the directory inside and paste in your libraries folder (usually located in `/Documents/Arduino/libraries`)
- Open your Library Manager `Tools > Include Libraries > Manage Libraries...`
- Search for `ArduinoJSON` and install it

#### Using library manager
- Not available yet

## Setting it up

After install it, you have to include EasyHTTP in your project
```C++
#include <EasyHTTP.h>

[...]
```

Setup network constants to work with
```C++
[...]

char* ssid = "Your SSID here"; // SSID is your WiFi name
char* password = "Your password";

String baseURL = "http://yourapiurl.com"; // API that you will consume with EasyHTTP

[...]
```

Now you have  to instance a EasyHTTP object
```C++
[...]

EasyHTTP http(ssid, password);

[...]
```

Now, in your `void setup` lets connect to WiFi and set base URL
```C++
[...]
void setup() {

  Serial.begin(115200); // It will be useful in void loop
  http.connectWiFi();
  http.setBaseURL(baseURL);

}
[...]
```

In your `void loop` lets make a GET request
```C++
[...]
void loop() {

  String response = http.get("/test"); // It will make a request like GET http://yourapiurl.com/test
  Serial.println(response);

  delay(3000);

}
```

### Full code

```C++
#include <EasyHTTP.h>

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
```

# <a name="examples"></a>Examples
- [GET](https://github.com/petruspierre/EasyHTTP/blob/master/examples/GET/GET.ino)
- [POST](https://github.com/petruspierre/EasyHTTP/blob/master/examples/POST/POST.ino)
- [POST with JSON body](https://github.com/petruspierre/EasyHTTP/blob/master/examples/POSTwithJSON/POSTwithJSON.ino)
