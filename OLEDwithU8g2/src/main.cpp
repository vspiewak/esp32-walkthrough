#include <Arduino.h>
#include <Wire.h>
#include "U8x8lib.h"

// Create U8x8 instance for SSD1306 OLED display (no reset) using hardware I2C.
U8X8_SSD1306_128X64_NONAME_HW_I2C display(/*reset*/ U8X8_PIN_NONE);

void setup()
{

	// Set serial speed
	Serial.begin(115200);
	Serial.println("Starting ESP32...");

	display.begin();

}

void loop()
{


	Serial.println("Check the OLED screen");

	display.setFont(u8x8_font_victoriamedium8_r);
	display.drawString(0, 0, "DailyBrain123456");  // print text to screen (column 0, row 0)

	display.setFont(u8x8_font_5x7_r);
	display.drawString(0, 1, "DailyBrain !");  // print text to screen (column 0, row 1)

	display.setFont(u8x8_font_amstrad_cpc_extended_r);
	display.drawString(0, 2, "DailyBrain !");  // print text to screen (column 0, row 2)

	display.setFont(u8x8_font_victoriabold8_r);
	display.drawString(0, 3, "DailyBrain !");  // print text to screen (column 0, row 3)

	display.setFont(u8x8_font_torussansbold8_r);
	display.drawString(0, 4, "DailyBrain !");  // print text to screen (column 0, row 4)

	display.setFont(u8x8_font_torussansbold8_r);
	display.drawString(0, 5, "DailyBrain !");  // print text to screen (column 0, row 5)

	display.setFont(u8x8_font_victoriamedium8_r);
	display.drawString(0, 6, "DailyBrain123456");  // print text to screen (column 0, row 6)

	uint8_t transmitSymbol[8] = {0x18, 0x18, 0x00, 0x24, 0x99, 0x42, 0x3c, 0x00}; 
	display.drawTile(15, 1, 1, transmitSymbol);

}