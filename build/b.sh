#!/bin/bash

export IDF_PATH=/opt/ESP8266_RTOS_SDK
export ESP8266_TOOLCHAIN=/opt/xtensa-lx106-elf
export PATH=$ESP8266_TOOLCHAIN/bin:$IDF_PATH/tools:$PATH
cmake ..
make
make flash
idf.py -p /dev/ttyUSB0 monitor -C ../
