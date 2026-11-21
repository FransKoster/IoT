# IoT ESPHome configurations

This repository contains ESPHome configurations for small ESP8266 and ESP32 devices.
Each subfolder is an independent configuration with its own local secrets and generated
build cache.

## Devices

| Folder | Hardware | Configuration |
| --- | --- | --- |
| [`bmp280/`](bmp280/) | Wemos D1 Mini + BMP280 | Temperature and pressure sensors |
| [`esp32-cam/`](esp32-cam/) | ESP32-CAM with OV2640 | Camera stream and snapshot servers |
| [`esp32-wroom-32/`](esp32-wroom-32/) | ESP32-WROOM-32 | Basic Wi-Fi/API/OTA setup |
| [`rgb7/`](rgb7/) | Wemos D1 Mini + 7 WS2812 LEDs | Addressable RGB light |
| [`screen/`](screen/) | Wemos D1 Mini + ILI9341 TFT | 320 x 240 information display |
| [`sht30/`](sht30/) | Wemos D1 Mini + SHT30 | Temperature and humidity sensors |

## Common setup

Each folder contains an ESPHome YAML file and an ignored `secrets.yaml`. Install ESPHome
and compile or flash a device from the folder that owns the configuration:

```bash
esphome compile DEVICE.yaml
esphome run DEVICE.yaml
```

Create `secrets.yaml` from the keys documented in the relevant folder. Do not commit real
Wi-Fi passwords, API keys, or OTA passwords. Generated `.esphome/` directories are also
ignored in the device folders.

ESPHome normally discovers the device over the network for OTA updates. Add `--device`
with a serial port if a physical USB connection is required, for example:

```bash
esphome run DEVICE.yaml --device /dev/cu.usbserial-210
```
