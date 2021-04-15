# ESP32 Walkthrough

My journey on ESP32 with the `LILYGO® TTGO LoRa32 V2.1_1.6 Version 868Mhz`


## Projects

* [Blink Bultin Led](./BlinkBultinLed) - Make blink the internal led.
* [Hello World](./HelloWorld) - Basic Serial print.
* [OLED with GFX](./OLEDwithGFX) - Play with OLED screen using GFX library.
* [Hibernate](./Hibernate) - Hibernate ESP32 with timer wake-up.
* [Tasks](./Tasks) - MultiTasking sample.
* [Preferences](./Preferences) - Store data in NVS memory using Preferences.h.
* [SPIFFS](./SPIFFS) - Store data in a SPIFFS partition.
* [Fast Reset](./FastReset) - Fast Reset OOP using Tasks & Preferences.h.
* [WiFi Scan](./WiFiScan) - WiFi network scan.
* [WiFi Client](./WiFiClient) - WiFi client with auto-reconnect.
* [WiFi Captive Portal](./WiFiCaptivePortal) - WiFi AP with Captive Portal.
  

## Setup

    # install esptool
    pip install -U esptool

    # install platformio
    pip install -U platformio
    export PATH="$PATH:$HOME/.local/bin"
    
    # list your OS groups
    compgen -g

    # list your groups
    groups

    # add group uucp to your user
    sudo usermod -a -G uucp vince  
    sudo usermod -a -G lock vince  

    # logout / login


## Lifecycle

    # create project directory
    mkdir HelloWorld
    cd HelloWorld
    
    # init project
    pio init \
        --board ttgo-lora32-v21 \
        --project-option "framework=arduino" \
        --project-option "monitor_speed=115200" \
        --ide vscode
    
    # build
    pio run

    # clean
    pio run -t clean

    # build
    pio run

    # upload
    pio run -t upload
    
    # monitor
    pio run -t monitor

    # upload & monitor
    pio run -t upload -t monitor
    
    # list all targets
    pio run --list-targets
    
    # list all devices
    pio device list

    # upload data/ to SPIFFS
    pio run -t uploadfs

    # erase flash
    pio run -t erase
