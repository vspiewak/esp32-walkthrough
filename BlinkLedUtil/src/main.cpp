#include <Arduino.h>
#include <Led.h>

Led led;

void setup()
{
    Serial.begin(115200);
    //
    led.begin();

}

void loop()
{
 
    log_d("led on");
    led.on();
    delay(1000);

    log_d("blink fast");
    led.blinkFast();
    delay(5000);
    
    log_d("led off");
    led.off();
    delay(1000);

    log_d("blink slow");
    led.blinkSlow();
    delay(5000);

}