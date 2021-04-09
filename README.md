# ESP32 Walkthrough


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


## Projects

* [BlinkBultinLed](./BlinkBultinLed) - Make blink the internal led.
* [HelloWorld](./HelloWorld) - Basic Serial print.
* [WifiClientWithAutoReconnect ](./WifiClientWithAutoReconnect) - WiFi client with auto-reconnect.