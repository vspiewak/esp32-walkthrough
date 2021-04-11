#include <DNSServer.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"

DNSServer dnsServer;
AsyncWebServer server(80);

class CaptiveRequestHandler : public AsyncWebHandler
{
public:
    CaptiveRequestHandler() {}
    virtual ~CaptiveRequestHandler() {}

    bool canHandle(AsyncWebServerRequest *request)
    {
        //request->addInterestingHeader("ANY");
        return true;
    }

    void handleRequest(AsyncWebServerRequest *request)
    {
        AsyncResponseStream *response = request->beginResponseStream("text/html");
        response->print("<!DOCTYPE html><html><head><title>Captive Portal</title></head><body>");
        response->print("<p>This is out captive portal front page.</p>");
        response->printf("<p>You were trying to reach: http://%s%s</p>", request->host().c_str(), request->url().c_str());
        response->printf("<p>Try opening <a href='http://%s/hello'>this link</a> instead</p>", WiFi.softAPIP().toString().c_str());
        response->print("</body></html>");
        request->send(response);
    }
};

void setup()
{

    // AP SSID
    char ssid[100] = {'\0'};

    // get WiFi MAC address
    uint8_t mac[6];
    WiFi.macAddress(mac);

    // format SSID to string
    snprintf(
        ssid, sizeof(ssid),
        "node-%02X%02X%02X%02X%02X%02X",
        mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);

    log_i("ssid: %s\n", ssid);

    // start WiFi AP
    WiFi.enableAP(true);
    WiFi.softAP(ssid);

    // start DNS server
    dnsServer.start(53, "*", WiFi.softAPIP());

    // handlers...
    server.on("/hello", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/plain", "Hello, world");
    });

    // captive handler
    server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER); //only when requested from AP

    // start web server
    server.begin();
}

void loop()
{
    dnsServer.processNextRequest();
}
