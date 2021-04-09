#include <WiFi.h>

const char *ssid = "your-ssid";
const char *password = "your-password";

void WiFiReady(WiFiEvent_t event, WiFiEventInfo_t info)
{
    log_i("WiFi ready");
}

void WiFiStationConnected(WiFiEvent_t event, WiFiEventInfo_t info)
{
    log_i("Connected to WiFi (%s)", ssid);
}

void WiFiGotIP(WiFiEvent_t event, WiFiEventInfo_t info)
{
    const char *ip = WiFi.localIP().toString().c_str();
    log_i("WiFi IP address: %s", ip);
}

void WiFiStationDisconnected(WiFiEvent_t event, WiFiEventInfo_t info)
{
    log_i("Disconnected from WiFi access point");
    log_i("WiFi lost connection. Reason: %u", info.disconnected.reason);
    log_i("Trying to Reconnect to WiFi (%s)", ssid);
    WiFi.begin(ssid, password);
}

void setup()
{
    Serial.begin(115200);
    log_i("Starting...");

    WiFi.disconnect(true);
    WiFi.mode(WIFI_STA);

    //delay(1000);

    WiFi.onEvent(WiFiReady, SYSTEM_EVENT_WIFI_READY);
    WiFi.onEvent(WiFiStationConnected, SYSTEM_EVENT_STA_CONNECTED);
    WiFi.onEvent(WiFiGotIP, SYSTEM_EVENT_STA_GOT_IP);
    WiFi.onEvent(WiFiStationDisconnected, SYSTEM_EVENT_STA_DISCONNECTED);

    WiFi.begin(ssid, password);
    log_i("Trying to connect to WiFi (%s)...", ssid);
}

void loop()
{
    log_i("In loop");
    if (WiFi.isConnected()) {
        String ssid = WiFi.SSID();
        int8_t rssi = WiFi.RSSI();
        log_i("WiFi connected (%s) (%i dBm)", ssid.c_str(), rssi);
    }
    delay(1000);
}