// create the code for the leds to go along with the design on p5js 
//made by Ariela Ridgley
//final project

#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>
// NeoPixel strip setup
#define PIN A1          
#define NUMPIXELS 30    
// data the led strip would read
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  CircuitPlayground.begin();
  strip.begin();
  strip.show(); // Ensure all LEDs are off initially
  CircuitPlayground.setBrightness(400);
  Serial.begin(9600);
  


}

void loop() {
  // create the motions for the accelemetor
  float x = CircuitPlayground.motionX();
  float y = CircuitPlayground.motionY();
  float z = CircuitPlayground.motionZ();
  
  float magnitude = sqrt(x * x + y * y + z * z);
  
  
  
  if (magnitude > 12.0) {
    // Strong movement (shake, fast tilt): Set LEDs to Red
    setStripColor(255, 0, 0); // Red
    Serial.println("Strong movement detected: Red");
  }  else if (x > 1.5) {
    // Moderate movement (gentle shake, tilt right): Set LEDs to Purple
    setStripColor(128, 0, 128); // Purple
    Serial.println("Tilt Right detected: Purple");
  } 
  else if (y > 1.5) {
    // Slight movement (tilt down, subtle shake): Set LEDs to Yellow
    setStripColor(255, 255, 0); // Yellow
    Serial.println("Tilt down detected: Yellow");
  }  else if (x < -1.5) {
    // Moderate movement (gentle shake, tilt left): Set LEDs to Green
    setStripColor(0, 255, 0); // Green
    Serial.println("Tilt Left detected: Green");
    } else if (y < - 2.0) {
    // Slight movement (tilt up, subtle shake): Set LEDs to Coral
    setStripColor(255, 127, 80); // Coral
    Serial.println("Tilt up detected: Coral");
  }
  else if (magnitude > 4.0) {
    // Minimal or no movement: Set LEDs to Blue
    setStripColor(0, 0, 255); // Blue
    Serial.println("No significant movement detected: Blue");
  }

  delay(100);  // Small delay for smoother operation
}
  
  
   
  


// Function to set the entire strip to a specific color
void setStripColor(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(i, r, g, b);
  }
  strip.show(); // Send data to the LEDs
}
