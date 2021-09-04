/**
   BasicHTTPSClient.ino

    Created on: 14.10.2018

*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClientSecure.h>

#include "Secrets.h"

const char* ssid = SECRET_SSID;
const char* password = SECRET_PASSWORD;

enum
{
  redButtonPin = D5,
  greenButtonPin = D2,
  blueButtonPin = D1,
  peeLedPin = D3,
  pooLedPin = D4,
  rgbRedPin = D7,
//  rgbGreenPin = ,
  rgbBluePin = D6,
};

// Prod:
const char* url = SECRET_URL_PROD;
// Dev:
//const char* url = SECRET_URL_DEV;

// This is a root certificate for Google servers. It will
//   eventually expire, but will last much longer than a
//   fingerprint.
static const char* rootCACertificate PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIFljCCA36gAwIBAgINAgO8U1lrNMcY9QFQZjANBgkqhkiG9w0BAQsFADBHMQsw
CQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZpY2VzIExMQzEU
MBIGA1UEAxMLR1RTIFJvb3QgUjEwHhcNMjAwODEzMDAwMDQyWhcNMjcwOTMwMDAw
MDQyWjBGMQswCQYDVQQGEwJVUzEiMCAGA1UEChMZR29vZ2xlIFRydXN0IFNlcnZp
Y2VzIExMQzETMBEGA1UEAxMKR1RTIENBIDFDMzCCASIwDQYJKoZIhvcNAQEBBQAD
ggEPADCCAQoCggEBAPWI3+dijB43+DdCkH9sh9D7ZYIl/ejLa6T/belaI+KZ9hzp
kgOZE3wJCor6QtZeViSqejOEH9Hpabu5dOxXTGZok3c3VVP+ORBNtzS7XyV3NzsX
lOo85Z3VvMO0Q+sup0fvsEQRY9i0QYXdQTBIkxu/t/bgRQIh4JZCF8/ZK2VWNAcm
BA2o/X3KLu/qSHw3TT8An4Pf73WELnlXXPxXbhqW//yMmqaZviXZf5YsBvcRKgKA
gOtjGDxQSYflispfGStZloEAoPtR28p3CwvJlk/vcEnHXG0g/Zm0tOLKLnf9LdwL
tmsTDIwZKxeWmLnwi/agJ7u2441Rj72ux5uxiZ0CAwEAAaOCAYAwggF8MA4GA1Ud
DwEB/wQEAwIBhjAdBgNVHSUEFjAUBggrBgEFBQcDAQYIKwYBBQUHAwIwEgYDVR0T
AQH/BAgwBgEB/wIBADAdBgNVHQ4EFgQUinR/r4XN7pXNPZzQ4kYU83E1HScwHwYD
VR0jBBgwFoAU5K8rJnEaK0gnhS9SZizv8IkTcT4waAYIKwYBBQUHAQEEXDBaMCYG
CCsGAQUFBzABhhpodHRwOi8vb2NzcC5wa2kuZ29vZy9ndHNyMTAwBggrBgEFBQcw
AoYkaHR0cDovL3BraS5nb29nL3JlcG8vY2VydHMvZ3RzcjEuZGVyMDQGA1UdHwQt
MCswKaAnoCWGI2h0dHA6Ly9jcmwucGtpLmdvb2cvZ3RzcjEvZ3RzcjEuY3JsMFcG
A1UdIARQME4wOAYKKwYBBAHWeQIFAzAqMCgGCCsGAQUFBwIBFhxodHRwczovL3Br
aS5nb29nL3JlcG9zaXRvcnkvMAgGBmeBDAECATAIBgZngQwBAgIwDQYJKoZIhvcN
AQELBQADggIBAIl9rCBcDDy+mqhXlRu0rvqrpXJxtDaV/d9AEQNMwkYUuxQkq/BQ
cSLbrcRuf8/xam/IgxvYzolfh2yHuKkMo5uhYpSTld9brmYZCwKWnvy15xBpPnrL
RklfRuFBsdeYTWU0AIAaP0+fbH9JAIFTQaSSIYKCGvGjRFsqUBITTcFTNvNCCK9U
+o53UxtkOCcXCb1YyRt8OS1b887U7ZfbFAO/CVMkH8IMBHmYJvJh8VNS/UKMG2Yr
PxWhu//2m+OBmgEGcYk1KCTd4b3rGS3hSMs9WYNRtHTGnXzGsYZbr8w0xNPM1IER
lQCh9BIiAfq0g3GvjLeMcySsN1PCAJA/Ef5c7TaUEDu9Ka7ixzpiO2xj2YC/WXGs
Yye5TBeg2vZzFb8q3o/zpWwygTMD0IZRcZk0upONXbVRWPeyk+gB9lm+cZv9TSjO
z23HFtz30dZGm6fKa+l3D/2gthsjgx0QGtkJAITgRNOidSOzNIb2ILCkXhAd4FJG
AJ2xDx8hcFH1mt0G/FX0Kw4zd8NLQsLxdxP8c4CU6x+7Nz/OAipmsHMdMqUybDKw
juDEI/9bfU1lcKwrmz3O2+BtjjKAvpafkmO8l7tdufThcV4q5O8DIrGKZTqPwJNl
1IXNDw9bg1kWRxYtnCQ6yICmJhSFm/Y3m6xv+cXDBlHz4n/FsRC6UfTd
-----END CERTIFICATE-----
)EOF";

void setClock() {
  configTime(0, 0, "pool.ntp.org", "time.nist.gov");

  Serial.print(F("Waiting for NTP time sync: "));
  time_t nowSecs = time(nullptr);
  while (nowSecs < 8 * 3600 * 2) {
    delay(500);
    Serial.print(F("."));
    yield();
    nowSecs = time(nullptr);
  }

  Serial.println();
  struct tm timeinfo;
  gmtime_r(&nowSecs, &timeinfo);
  Serial.print(F("Current time: "));
  Serial.print(asctime(&timeinfo));
}


ESP8266WiFiMulti WiFiMulti;

void setup() {
  pinMode(peeLedPin, OUTPUT);
  pinMode(pooLedPin, OUTPUT);
  pinMode(rgbRedPin, OUTPUT);
  pinMode(rgbBluePin, OUTPUT);

  digitalWrite(peeLedPin, 1);
  digitalWrite(pooLedPin, 1);
//
  digitalWrite(rgbRedPin, 1);
  digitalWrite(rgbBluePin, 0);

  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(ssid, password);

  // wait for WiFi connection
  Serial.print("Waiting for WiFi to connect...");
  while ((WiFiMulti.run() != WL_CONNECTED)) {
    Serial.print(".");
    delay(10);
  }
  Serial.println(" connected");

  setClock();

  pinMode(blueButtonPin, INPUT_PULLUP);
  pinMode(greenButtonPin, INPUT_PULLUP);
  pinMode(redButtonPin, INPUT_PULLUP);

  digitalWrite(rgbRedPin, 0);
  digitalWrite(rgbBluePin, 1);
}

void transmit(bool pee, bool poo)
{
  WiFiClientSecure *client = new WiFiClientSecure;
  X509List cert(rootCACertificate);

  if(client) {
    client->setTrustAnchors(&cert);

    {
      // Add a scoping block for HTTPClient https to make sure it is destroyed before WiFiClientSecure *client is 
      HTTPClient https;
  
      Serial.print("[HTTPS] begin...\n");

      time_t now;
      time(&now);
      char timeBuf[sizeof "2011-10-08T07:07:09Z"];
      strftime(timeBuf, sizeof timeBuf, "%Y-%m-%dT%H:%M:%SZ", gmtime(&now));
      
      uint8_t mac[6];
      WiFi.macAddress(mac);
      char macBuffer[15];
      sprintf(macBuffer, "%02x%02x%02x%02x%02x%02x", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

      char serverPathBuffer[300];
      sprintf(serverPathBuffer, "%s?coreid=%s&published_at=%s&data=[%d,%d]", url, macBuffer
      , timeBuf, pee, poo);
      String serverPath = String(serverPathBuffer);
      Serial.print(serverPath);
      
      if (https.begin(*client, serverPath)) {  // HTTPS
        Serial.print("[HTTPS] POST...\n");

        https.setFollowRedirects(HTTPC_FORCE_FOLLOW_REDIRECTS);
        
        // start connection and send HTTP header
        int httpCode = https.POST("Hello World");
  
        // httpCode will be negative on error
        if (httpCode > 0) {
          // HTTP header has been send and Server response header has been handled
          Serial.printf("[HTTPS] POST... code: %d\n", httpCode);
  
          // file found at server
          if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY || httpCode == HTTP_CODE_FOUND) {
            String payload = https.getString();
            Serial.println(payload);
          } 
        } else {
          Serial.printf("[HTTPS] POST... failed, error: %s\n", https.errorToString(httpCode).c_str());
        }
  
        https.end();
      } else {
        Serial.printf("[HTTPS] Unable to connect\n");
      }

      // End extra scoping block
    }
  
    delete client;
  } else {
    Serial.println("Unable to create client");
  }
}

void loop() {
  bool blue = digitalRead(blueButtonPin);
  bool green = digitalRead(greenButtonPin);
  bool red = digitalRead(redButtonPin);

//  Serial.printf("Blue: %d Green: %d Red: %d\n", blue, green, red);

  if(blue || green || red)
  {
    delay(50);
    blue = digitalRead(blueButtonPin);
    green = digitalRead(greenButtonPin);
    red = digitalRead(redButtonPin);

    if(blue) {
      digitalWrite(peeLedPin, 0);
      digitalWrite(pooLedPin, 1);
      transmit(true, false);
    } else if (green) {
      digitalWrite(peeLedPin, 0);
      digitalWrite(pooLedPin, 0);
      transmit(true, true);
    } else if (red) {
      digitalWrite(peeLedPin, 1);
      digitalWrite(pooLedPin, 0);
      transmit(false, true);
    }
    
    digitalWrite(peeLedPin, 1);
    digitalWrite(pooLedPin, 1);
  }

  delay(50);
}
