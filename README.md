# xiot sample (lightbulb) on esp8266

## 配置编译环境 (esp-idf编译环境的配置,请参考官方文档)
1. 下载ESP8266的sdk:
```bash
git clone https://github.com/espressif/ESP8266_RTOS_SDK.git
```

2. 使用Release版分支
```bash
git branch v32 -t origin/release/v3.2
git checkout v32
```

3. 配置toolchain和sdk
```bash
export IDF_PATH=/opt/ESP8266_RTOS_SDK
export ESP8266_TOOLCHAIN=/opt/xtensa-lx106-elf
export PATH=$ESP8266_TOOLCHAIN/bin:$PATH
```

## 编译（后续版本仅支持cmake）
```bash
git submodule update --init
mkdir b
cd b
cmake ..
make 
```

## 如何烧写？ 
```bash
make falsh
```

## 如何调试？
1. 打开串口，观察LOG。
2. 使用app绑定并测试此设备。
```

## 板子启动后，将自动连接到路由器
```
ssid: gkct
pasword: hellogkct
```
