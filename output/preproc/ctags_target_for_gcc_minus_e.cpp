# 1 "c:\\Users\\USER\\Documents\\Arduino\\mpuLedLight\\ESP32Blynk\\ESP32Blynk.ino"

/* Comment this out to disable prints and save space */





// #define USE_ESP32S2_DEV_KIT

# 11 "c:\\Users\\USER\\Documents\\Arduino\\mpuLedLight\\ESP32Blynk\\ESP32Blynk.ino" 2
# 12 "c:\\Users\\USER\\Documents\\Arduino\\mpuLedLight\\ESP32Blynk\\ESP32Blynk.ino" 2
# 13 "c:\\Users\\USER\\Documents\\Arduino\\mpuLedLight\\ESP32Blynk\\ESP32Blynk.ino" 2


// #define PIN 5 // Use GPIO5, in case of using the SCL pin as a digital pin

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8 /* Change the pixel number according to your project*/, 4 /* Use GPIO4, in case of using the SDA pin as a digital pin*/, ((1<<6) | (1<<4) | (0<<2) | (2)) /*|< Transmit as G,R,B*/ + 0x0000 /*|< 800 KHz data transmission*/);

void BlynkWidgetWrite1 (BlynkReq __attribute__((__unused__)) &request, const BlynkParam __attribute__((__unused__)) &param)
{
  int R = param[0].asInt();
  int G = param[1].asInt();
  int B = param[2].asInt();

  // Serial.println(R);
  // Serial.println(G);
  // Serial.println(B);

  for (int i = 0; i < 8 /* Change the pixel number according to your project*/; i++)
  {
    pixels.setPixelColor(i, pixels.Color(R, G, B));
  }

  pixels.show();
}

void BlynkWidgetWrite2 (BlynkReq __attribute__((__unused__)) &request, const BlynkParam __attribute__((__unused__)) &param)
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
