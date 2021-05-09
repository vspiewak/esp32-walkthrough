#ifndef _LED_H_
#define _LED_H_
#include <Arduino.h>

class Led
{
private:
    uint8_t _ledPin;
    uint32_t _highDelay;
    uint32_t _lowDelay;

    TaskHandle_t _blinkTaskHandle = NULL;
    void _cleanTask();
    static void _blinkTaskImpl(void *);
    void _blinkTask();

public:
    Led();
    void begin(uint8_t ledPin = BUILTIN_LED);
    void on();
    void off();
    void blink(uint32_t highDelay = 500, uint32_t lowDelay = 500);
    void blinkSlow();
    void blinkFast();
};

#endif