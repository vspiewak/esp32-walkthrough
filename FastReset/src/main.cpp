#include <Arduino.h>
#include <Preferences.h>
#include <FastReset.h>

Preferences preferences;
FastReset fastReset;

void setup()
{
    Serial.begin(115200);

    fastReset.begin();
}

void loop()
{
    log_d("In loop...");

    delay(1000);
}