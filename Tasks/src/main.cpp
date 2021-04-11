#include <Arduino.h>

TaskHandle_t taskHandle_1 = NULL;

void echoHello(void *parameter)
{
    // infinite loop
    for (;;)
    {

        log_i("hello (core %u)", xPortGetCoreID());

        // Pause the task for 1000ms
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void echoWorld(void *parameter)
{
    // infinite loop
    for (;;)
    {

        log_i("world (core %u)", xPortGetCoreID());

        // Pause the task for 1000ms
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void blinkFast(void *parameter)
{
    // infinite loop
    for (;;)
    {
        // Turn the LED on
        digitalWrite(LED_BUILTIN, HIGH);
        log_i("turn ON led (core %u)", xPortGetCoreID());

        // Pause the task for 500ms
        vTaskDelay(500 / portTICK_PERIOD_MS);

        // Turn the LED off
        digitalWrite(LED_BUILTIN, LOW);
        log_i("turn OFF led (core %u)", xPortGetCoreID());

        // Pause the task again for 500ms
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void setup()
{

    Serial.begin(115200);
    log_i("running on core %u", xPortGetCoreID());

    // initialize LED digital pin as an output.
    pinMode(LED_BUILTIN, OUTPUT);

    // Turn the LED off
    digitalWrite(LED_BUILTIN, LOW);

    xTaskCreate(
        echoHello,    // Function that should be called
        "Echo Hello", // Name of the task (for debugging)
        10000,        // Stack size (bytes)
        NULL,         // Parameter to pass
        1,            // Task priority
        NULL          // Task handle
    );

    xTaskCreate(
        echoWorld,    // Function that should be called
        "Echo World", // Name of the task (for debugging)
        10000,        // Stack size (bytes)
        NULL,         // Parameter to pass
        2,            // Task priority
        NULL          // Task handle
    );

    xTaskCreate(
        blinkFast,    // Function that should be called
        "Toggle LED", // Name of the task (for debugging)
        10000,        // Stack size (bytes)
        NULL,         // Parameter to pass
        1,            // Task priority
        &taskHandle_1 // Task handle
    );
}

void loop()
{

    log_i("running on core %u", xPortGetCoreID());
    delay(5000);

    if (taskHandle_1 != NULL)
    {
        log_i("task blinkFast state %u", eTaskGetState(taskHandle_1));
        log_i("delete task blinkFast");

        vTaskDelete(taskHandle_1);
        taskHandle_1 = NULL;
    }
}