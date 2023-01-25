#include <Arduino.h>
#line 1 "c:\\Users\\USER\\Documents\\Arduino\\mpuLedLight\\ESP32Blynk\\ESP32Blynk.ino"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLTZwpzG5t"
#define BLYNK_DEVICE_NAME "mpuLeds"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define APP_DEBUG
// #define USE_ESP32S2_DEV_KIT

#include "BlynkEdgent.h"
#include <Adafruit_NeoPixel.h>
#include <SPI.h>

#define PIN 4 // Use GPIO4, in case of using the SDA pin as a digital pin
// #define PIN 5 // Use GPIO5, in case of using the SCL pin as a digital pin
#define NUMPIXELS 8 // Change the pixel number according to your project
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#line 19 "c:\\Users\\USER\\Documents\\Arduino\\mpuLedLight\\ESP32Blynk\\ESP32Blynk.ino"
void BlynkWidgetWrite1(BlynkReq __attribute__((__unused__)) &request, const BlynkParam __attribute__((__unused__)) &param);
#line 37 "c:\\Users\\USER\\Documents\\Arduino\\mpuLedLight\\ESP32Blynk\\ESP32Blynk.ino"
void BlynkWidgetWrite2(BlynkReq __attribute__((__unused__)) &request, const BlynkParam __attribute__((__unused__)) &param);
#line 47 "c:\\Users\\USER\\Documents\\Arduino\\mpuLedLight\\ESP32Blynk\\ESP32Blynk.ino"
void setup();
#line 55 "c:\\Users\\USER\\Documents\\Arduino\\mpuLedLight\\ESP32Blynk\\ESP32Blynk.ino"
void loop();
#line 19 "c:\\Users\\USER\\Documents\\Arduino\\mpuLedLight\\ESP32Blynk\\ESP32Blynk.ino"
BLYNK_WRITE(V1)
{
  int R = param[0].asInt();
  int G = param[1].asInt();
  int B = param[2].asInt();

   Serial.println(R);
   Serial.println(G);
   Serial.println(B);

  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(R, G, B));
  }

  pixels.show();
}

BLYNK_WRITE(V2)
{
  int Bright = param.asInt();
  pixels.setBrightness(Bright);
  Serial.println(Bright);
  pixels.show();
}
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

void setup()
{
  // Debug console
  Serial.begin(9600);

  BlynkEdgent.begin();//auth, ssid, pass
}

void loop()
{
  BlynkEdgent.run();
}

