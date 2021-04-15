#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DailyBrainBitmap.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{

	// Set serial speed
	Serial.begin(115200);

	Serial.println("Starting ESP32...");

	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
	{
		Serial.println(F("SSD1306 allocation failed"));
		for (;;)
			;
	}

	// display default buffer: Adafruit splash screen
	display.display();

	// delay 2s
	delay(2000);

	// turn OFF display
	display.ssd1306_command(SSD1306_DISPLAYOFF);

	// delay 2s
	delay(2000);

	// turn ON display
	display.ssd1306_command(SSD1306_DISPLAYON);

	// clear buffer
	display.clearDisplay();

	// draw bitmap
	display.drawBitmap(0, 0, dailybrainBitmap, 128, 64, WHITE);

	// display buffer
	display.display();

	// delay 2s
	delay(2000);

	// invert black on white
	display.invertDisplay(true);

	// delay 2s
	delay(2000);

	// revert to white on white
	display.invertDisplay(false);
	
	// clear buffer
	display.clearDisplay();

	// draw text
	display.setTextColor(WHITE);
	display.setTextSize(1);
	display.setCursor(0, 0);
	display.print("First thing.");
	display.print("Second thing.\n");
	display.print("\n");
	display.print("Third thing.\n");
	display.print("\n");
	
	display.setTextSize(2);
	display.print("Size 2 !\n");

	// display buffer
	display.display();

	// delay 2s
	delay(2000);

	// clear buffer
	display.clearDisplay();

	// draw a rect
	display.drawRect(0, 0, 4, 4, WHITE);

	// display buffer
	display.display();

	// clear buffer
	display.clearDisplay();
	display.display();

}

void loop()
{
}