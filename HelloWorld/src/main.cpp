#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("Setup...");
}
 
void loop() {
    Serial.println("Hello !");
    delay(1000);
}