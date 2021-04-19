#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <qrcode.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

#define QR_VERSION 3                                     // 29x29px
const uint8_t QR_SCALEFACTOR = (SCREEN_HEIGHT - 4) / 29; // 4px borderlines

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{

    Serial.begin(115200);
    Serial.println("Starting...");

    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
    {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;
    }

    // clean display
    display.clearDisplay();
    display.display();

    const char *qr = "https://dailybrain.fr";

    // Create the QR code
    QRCode qrcode;
    uint8_t qrcodeData[qrcode_getBufferSize(QR_VERSION)];
    qrcode_initText(&qrcode, qrcodeData, QR_VERSION, ECC_HIGH, qr);
    

    // Serial print

    // Top quiet zone
    Serial.print("\n\n\n\n");

    for (uint8_t y = 0; y < qrcode.size; y++)
    {

        // Left quiet zone
        Serial.print("        ");

        // Each horizontal module
        for (uint8_t x = 0; x < qrcode.size; x++)
        {

            // Print each module (UTF-8 \u2588 is a solid block)
            Serial.print(qrcode_getModule(&qrcode, x, y) ? "\u2588\u2588" : "  ");
        }

        Serial.print("\n");
    }

    // Bottom quiet zone
    Serial.print("\n\n\n\n");


    // OLED print
    uint16_t offset_x = 3;
    uint16_t offset_y = 3;

    // draw qr code
    for (uint8_t y = 0; y < qrcode.size; y++)
        for (uint8_t x = 0; x < qrcode.size; x++)
            if (!qrcode_getModule(&qrcode, x, y)) // "black"
                display.fillRect(
                    x * QR_SCALEFACTOR + offset_x,
                    y * QR_SCALEFACTOR + offset_y,
                    QR_SCALEFACTOR,
                    QR_SCALEFACTOR,
                    WHITE);

    // draw horizontal frame lines
    display.fillRect(0, 0, qrcode.size * QR_SCALEFACTOR + 2 * offset_x, offset_y, WHITE);
    display.fillRect(0, qrcode.size * QR_SCALEFACTOR + offset_y, qrcode.size * QR_SCALEFACTOR + 2 * offset_x, offset_y, WHITE);

    // draw vertical frame lines
    display.fillRect(0, 0, offset_x, qrcode.size * QR_SCALEFACTOR + 2 * offset_y, WHITE);
    display.fillRect(qrcode.size * QR_SCALEFACTOR + offset_x, 0, offset_x, qrcode.size * QR_SCALEFACTOR + 2 * offset_y, WHITE);

    // draw screen
    display.display();
}

void loop()
{
}