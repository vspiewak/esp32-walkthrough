# ESP32 Walkthrough

My journey on ESP32 with the `LILYGO® TTGO LoRa32 V2.1_1.6 Version 868Mhz`


## Projects

* [Blink Bultin Led](./BlinkBultinLed) - Make blink the internal led.
* [Hello World](./HelloWorld) - Basic Serial print.
* [Wifi Client](./WifiClient) - WiFi client with auto-reconnect.
  

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
