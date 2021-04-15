#include <Arduino.h>

void setup()
{

    Serial.begin(115200);
    log_i("Starting...");
}

void loop()
{

    // get hall sensor value
    int val = hallRead();

    // log value
    log_i("hall sensor value: %i", val);

    // delay 1s
    delay(1000);
}