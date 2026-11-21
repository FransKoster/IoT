# SHT30 D1 Mini

This folder contains an ESPHome configuration for an SHT30 temperature and humidity sensor
connected to a Wemos D1 Mini over I2C.

## Files

- `sht30.yml`: sensor and network configuration
- `secrets.yaml`: local Wi-Fi and fallback access-point password; ignored by Git

## Hardware configuration

- **Board:** Wemos D1 Mini (ESP8266)
- **Host name:** `sht30-d1-mini`
- **I2C address:** `0x45`
- **SDA:** D2 / GPIO4
- **SCL:** D1 / GPIO5
- **Update interval:** 30 seconds
- **I2C scanning:** enabled

The fallback access point is currently named `Bmp280-D1-Mini` by the YAML file. This appears
to be a copy/paste name and can be changed to an SHT30-specific name if desired.

## Measurements

- `SHT30 Temperature`
- `SHT30 Humidity`

## Secrets

Create `secrets.yaml` beside the configuration:

```yaml
wifi_ssid: "your-wifi-network"
wifi_password: "your-wifi-password"
fallback_ap_password: "your-fallback-password"
```

## Build and flash

```bash
esphome compile sht30.yml
esphome run sht30.yml --device /dev/cu.usbserial-210
```
