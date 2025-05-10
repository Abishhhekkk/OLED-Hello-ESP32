#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED width
#define SCREEN_HEIGHT 64 // OLED height
#define OLED_RESET    -1 // Reset pin (not needed)
#define SCREEN_ADDRESS 0x3C // I2C address

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
    Serial.begin(115200);

    // Initialize OLED display
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
        Serial.println("SSD1306 allocation failed");
        for (;;); // Stop execution if display not found
    }

    display.clearDisplay(); // Clear buffer

    // Display text
    display.setTextSize(2);     // Text size
    display.setTextColor(WHITE); // Text color
    display.setCursor(10, 20);  // Position (X, Y)
    display.println("Hello!");
    
    display.display(); // Show content
}

void loop() {
    // Nothing in loop
}
