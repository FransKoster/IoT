# BMP280 D1 Mini

This folder contains the ESPHome configuration for a Bosch BMP280 sensor connected to a
Wemos D1 Mini over I2C.

## Files

- `bpm280.yml`: main ESPHome configuration
- `secrets.yaml`: local Wi-Fi and fallback access-point passwords; ignored by Git

## Hardware

The BMP280 is connected to the D1 Mini with I2C:

| BMP280 | D1 Mini |
| --- | --- |
| SDA | D2 / GPIO4 |
| SCL | D1 / GPIO5 |
| VCC | 3.3 V |
| GND | GND |

The configuration uses the BMP280 I2C address `0x77` and enables I2C device scanning.

## Configuration

- **Board:** Wemos D1 Mini (ESP8266)
- **Host name:** `bmp280-d1-mini`
- **Logger:** enabled
- **Home Assistant API:** enabled
- **OTA updates:** enabled through ESPHome
- **Captive portal:** enabled for initial setup or connection recovery
- **Normal Wi-Fi:** read from `secrets.yaml`
- **Fallback Wi-Fi AP:** `Bmp280-D1-Mini`, with its password read from `secrets.yaml`

The sensor measurements are published every 30 seconds with 16x oversampling:

- `BMP280 Temperature`
- `BMP280 Pressure`

## Secrets

Create or update `secrets.yaml` beside the configuration file:

```yaml
wifi_ssid: "your-wifi-network"
wifi_password: "your-wifi-password"
fallback_ap_password: "your-fallback-password"
```

Keep `secrets.yaml` out of source control. The directory `.gitignore` already excludes it.

## Build and flash

```bash
esphome compile bpm280.yml
esphome run bpm280.yml --device /dev/cu.usbserial-210
```

After flashing, the device will join the configured Wi-Fi network. If it cannot connect, it starts the `Bmp280-D1-Mini` fallback access point and captive portal.
