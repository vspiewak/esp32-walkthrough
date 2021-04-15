#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

#define second_to_microseconds 1000 * 1000

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{

	// Set serial speed
	Serial.begin(115200);

	Serial.println("Starting ESP32...");

	// initialize LED digital pin as an output.
    pinMode(LED_BUILTIN, OUTPUT);

    // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED_BUILTIN, HIGH);

	// SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
	if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
	{
		Serial.println(F("SSD1306 allocation failed"));
		for (;;)
			;
	}

	// turn OFF display
	display.ssd1306_command(SSD1306_DISPLAYOFF);

	// Hibernate
	Serial.println("Will hibernate in 1s...");
	Serial.flush();

	delay(1000);

	esp_sleep_enable_timer_wakeup(5 * second_to_microseconds);
	esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_SLOW_MEM, ESP_PD_OPTION_OFF);
	esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_FAST_MEM, ESP_PD_OPTION_OFF);
	esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);
	esp_deep_sleep_start();

	// Will never print it !
	Serial.println("Wake up !");

}

void loop()
{
}