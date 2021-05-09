#include <Arduino.h>
#include <Led.h>

Led::Led()
{
}

void Led::begin(uint8_t ledPin)
{
    _ledPin = ledPin;

    // initialize LED digital pin as an output.
    pinMode(_ledPin, OUTPUT);
}

void Led::on()
{
    this->_cleanTask();

    // turn the LED on
    digitalWrite(LED_BUILTIN, HIGH);
}

void Led::off()
{
    this->_cleanTask();

    // turn the LED off
    digitalWrite(LED_BUILTIN, LOW);
}

void Led::_cleanTask()
{
    // clean blink task if needed
    if (_blinkTaskHandle != NULL)
    {
        vTaskDelete(_blinkTaskHandle);
        _blinkTaskHandle = NULL;
    }
}

void Led::blink(uint32_t highDelay, uint32_t lowDelay)
{

    _highDelay = highDelay;
    _lowDelay = lowDelay;

    this->_cleanTask();

    xTaskCreate(
        this->_blinkTaskImpl, // Function that should be called
        "Blink LED",          // Name of the task (for debugging)
        10000,                // Stack size (bytes)
        this,                 // Parameter to pass
        1,                    // Task priority
        &_blinkTaskHandle     // Task handle
    );
    
}

void Led::blinkSlow() {
    this->blink(1000, 1000);
}

void Led::blinkFast() {
    this->blink(300, 300);
}

void Led::_blinkTaskImpl(void *_this)
{
    static_cast<Led *>(_this)->_blinkTask();
}

void Led::_blinkTask()
{
    // infinite loop
    for (;;)
    {
        // Turn the LED on
        digitalWrite(_ledPin, HIGH);
        log_d("turn ON led (pin %u) (core %u)", _ledPin, xPortGetCoreID());

        // Pause the task for 500ms
        vTaskDelay(_highDelay / portTICK_PERIOD_MS);

        // Turn the LED off
        digitalWrite(_ledPin, LOW);
        log_d("turn OFF (led %u) (core %u)", _ledPin, xPortGetCoreID());

        // Pause the task again for 500ms
        vTaskDelay(_lowDelay / portTICK_PERIOD_MS);
    }
}
