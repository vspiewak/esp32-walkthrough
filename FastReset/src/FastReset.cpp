#include <Arduino.h>
#include <FastReset.h>

FastReset::FastReset() // : _started(false)
{
}

void FastReset::begin(uint16_t timeout)
{
    _timeout = timeout;

    // open namesapce
    _prefs.begin(_FAST_RESET_PREF_NAMESPACE_, false);

    // get stored count
    _count = _prefs.getUShort(_FAST_RESET_PREF_KEY_, 0);

    // increment
    _count++;

    // log count
    log_d("fast-reset count: %u", _count);

    // store
    _prefs.putUShort(_FAST_RESET_PREF_KEY_, _count);

    // Task to stop the count
    xTaskCreate(
        this->_stopTaskImpl, // Function that should be called
        "Stop Fast Reset",   // Name of the task (for debugging)
        1500,                // Stack size (bytes)
        this,                // Parameter to pass
        1,                   // Task priority
        NULL                 // Task handle
    );
}

uint16_t FastReset::count()
{
    return _count;
}

void FastReset::_stopTaskImpl(void *_this)
{
    static_cast<FastReset *>(_this)->_stopTask();
}

void FastReset::_stopTask()
{
    // wait for timeout
    vTaskDelay((_timeout * 1000) / portTICK_PERIOD_MS);

    // log expiration
    log_d("fast-reset expired");

    // reset count
    _prefs.putUShort(_FAST_RESET_PREF_KEY_, 0);

    // delete task
    vTaskDelete(NULL);
}