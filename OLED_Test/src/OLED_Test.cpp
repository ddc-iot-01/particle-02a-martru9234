/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#line 1 "/home/brian/Particle/OLED_Test/src/OLED_Test.ino"
/*
 * Project OLED_Test
 * Description:
 * Author:
 * Date:
 */

#include "Particle.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
void setup();
void loop();
void printhello();
#line 14 "/home/brian/Particle/OLED_Test/src/OLED_Test.ino"
#define OLED_ADDR   0x3C
Adafruit_SSD1306 display(-1);


#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

/*=========================================================================
    SSD1306 Displays
    -----------------------------------------------------------------------
    The driver is used in multiple displays (128x64, 128x32, etc.).
    Select the appropriate display below to create an appropriately
    sized framebuffer, etc.
    -----------------------------------------------------------------------*/
     #define SSD1306_128_64     // 128x64 pixel display
//   #define SSD1306_128_32     // 128x32 pixel display
//   #define SSD1306_96_16      //  96x16 pixel display

int delayTime=1000;

void setup() {

  Serial.begin(9600);
  Wire.begin();

   // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

  printhello();

delay(delayTime);

}

void loop() {   // no loop
}


void printhello() {
  display.clearDisplay();
  display.display();

  // display a pixel in each corner of the screen
  display.drawPixel(0, 0, WHITE);
  display.drawPixel(127, 0, WHITE);
  display.drawPixel(0, 63, WHITE);
  display.drawPixel(127, 63, WHITE);

  // display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(27,30);
  display.print("Hello, world!");

  // update display with all of the above graphics
  display.display();
}