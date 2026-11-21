# RGB7 D1 Mini

This folder contains an ESPHome configuration for seven WS2812 addressable RGB LEDs
connected to a Wemos D1 Mini.

## Files

- `rgb7.yml`: light and network configuration
- `secrets.yaml`: local Wi-Fi and fallback access-point password; ignored by Git

## Hardware configuration

- **Board:** Wemos D1 Mini (ESP8266)
- **Host name:** `rgb7-d1-mini`
- **LED controller:** WS2812
- **Pixel count:** 7
- **Color order:** GRB
- **Data pin:** D4 / GPIO2
- **Entity name:** `RGB7`

The fallback access point is `Rgb7-D1-Mini`. The configuration enables logging, the
Home Assistant API, OTA updates, and the captive portal.

## Secrets

Create `secrets.yaml` beside the configuration:

```yaml
wifi_ssid: "your-wifi-network"
wifi_password: "your-wifi-password"
fallback_ap_password: "your-fallback-password"
```

## Build and flash

```bash
esphome compile rgb7.yml
esphome run rgb7.yml --device /dev/cu.usbserial-210
```
