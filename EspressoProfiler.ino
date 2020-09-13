#include "secrets.h"

#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>


// Display
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


// Server
WebServer server(80);


const int led = 13;


void setup(void) {
  Serial.begin(115200);

  // Set up WiFi first
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  
  setupOTA();
  setupServer();
  displaySetup(); 
  setupTouch();


  Serial.println("End setup\n");
}

void loop(void) {
  loopOTA();
  loopServer();
  displayText(String(touchRead(T4)), 2);
  loopTouch();
}


void deep_sleep(){
  Serial.println("sleeping");
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  //display.ssd1306_command(SSD1306_DISPLAYON);
  WiFi.mode(WIFI_OFF);
  esp_deep_sleep_start();
}

void callback(){
  //placeholder callback function
}
