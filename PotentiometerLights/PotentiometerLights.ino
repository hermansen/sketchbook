#include <Adafruit_NeoPixel.h>

#define PIN 2   // input pin Neopixel is attached to

#define NUMPIXELS      24 // number of neopixels in strip

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 10; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int potIn = 0;

void setup() {
  // Initialize the NeoPixel library.
  pixels.begin();
  pinMode(A0, INPUT);
  // pivk a random color for the lights
  setColor();
  Serial.begin(9600);
}

void loop() {
  potIn = analogRead(8);
  int numLights = map(potIn, 0, 1023, 0, 24);
  Serial.println(numLights);
  lightTheLights(numLights);
  // Delay for a period of time (in milliseconds).
  delay(delayval);
}

void lightTheLights(int numLights) {
  for (int i=0; i < numLights; i++) {
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor));
  }
  
  for (int i=NUMPIXELS-1; i >= numLights; i--) {
     pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  // This sends the updated pixel color to the hardware.
  pixels.show();  
}

// setColor()
// picks random values to set for RGB
void setColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}
