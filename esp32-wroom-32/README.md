# ESP32 WROOM 32 - Basic Setup

This folder contains the basic ESPHome setup for an ESP32-WROOM-32 board.

It provides the standard ESPHome connectivity and management services without any connected sensors or actuators. Use this configuration as a starting point for ESP32 projects.

## Files

- `esp32-wroom.yaml`: basic ESPHome configuration
- `secrets.yaml`: local Wi-Fi and fallback access-point passwords (not committed)

## Basic configuration

- **Board:** ESP32-WROOM-32 (configured as `esp32dev` with the `esp32` variant)
- **Host name:** `esp32-wroom`
- **Friendly name:** `ESP32 Wroom 32`
- **Logger:** enabled
- **Home Assistant API:** enabled
- **OTA updates:** enabled through ESPHome
- **Captive portal:** enabled for connection setup and recovery

## Wi-Fi

Normal Wi-Fi credentials are read from `secrets.yaml`. If the board cannot connect, it starts a fallback access point:

- **Fallback SSID:** `ESP32 Wroom 32`
- **Fallback password:** read from `secrets.yaml`

Create or update `secrets.yaml` beside the configuration file:

```yaml
wifi_ssid: "your-wifi-network"
wifi_password: "your-wifi-password"
fallback_ap_password: "your-fallback-password"
```

Keep `secrets.yaml` out of source control. The directory `.gitignore` already excludes it.

## Build and flash

```bash
esphome compile esp32-wroom.yaml
esphome run esp32-wroom.yaml --device /dev/cu.usbserial-210
```
