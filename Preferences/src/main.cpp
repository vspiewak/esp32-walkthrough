#include <nvs_flash.h>
#include <Preferences.h>

Preferences preferences;

void setup()
{

    Serial.begin(115200);
    Serial.println();

    //nvs_flash_erase(); // erase the NVS partition and...
    //nvs_flash_init(); // initialize the NVS partition.

    // Open Preferences with my-app namespace. Each application module, library, etc
    // has to use a namespace name to prevent key name collisions. We will open storage in
    // RW-mode (second parameter has to be false).
    // Note: Namespace name is limited to 15 chars.
    preferences.begin("my-app", false);

    // Remove all preferences under the opened namespace
    //preferences.clear();

    // Or remove the counter key only
    //preferences.remove("counter");

    // Get the counter value, if the key does not exist, return a default value of 0
    // Note: Key name is limited to 15 chars.
    unsigned int counter = preferences.getUInt("counter", 0);

    // Increase counter by 1
    counter++;

    // Print the counter to Serial Monitor
    Serial.printf("Current counter value: %u\n", counter);

    // Store the counter to the Preferences
    preferences.putUInt("counter", counter);

    // Close the Preferences
    preferences.end();

    // Wait 10 seconds
    Serial.println("Restarting in 10 seconds...");
    delay(10000);

    // Restart ESP
    ESP.restart();
}

void loop()
{
}