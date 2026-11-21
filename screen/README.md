# Wemos D1 Mini TFT Display

This folder contains an ESPHome configuration for a Wemos D1 Mini connected to a Lolin
TFT-2.4 display using an ILI9341 controller.

## Files

- `tft.yaml`: display, Wi-Fi, API, and OTA configuration
- `secrets.yaml`: Wi-Fi, API encryption, and OTA credentials; ignored by Git

## Hardware configuration

- **Board:** Wemos D1 Mini (ESP8266)
- **Host name:** `wemos-d1-tft`
- **Display:** ILI9341, 320 x 240 pixels
- **SPI clock:** D5 / GPIO14
- **SPI MOSI:** D7 / GPIO13
- **SPI MISO:** D6 / GPIO12
- **Chip select:** D8 / GPIO15
- **Data/command:** D3 / GPIO0
- **Reset:** D4 / GPIO2

The display refreshes once per second and shows the Wi-Fi IP address and SSID, along with
sample title, status, border, and progress-bar graphics.

## Secrets

Create `secrets.yaml` beside the configuration:

```yaml
wifi_ssid: "your-wifi-network"
wifi_password: "your-wifi-password"
api_encryption_key: "a-valid-base64-32-byte-key"
ota_password: "a-strong-ota-password"
```

The fallback access point is `Wemos-D1-TFT-Fallback`.

## Build and flash

```bash
esphome compile tft.yaml
esphome run tft.yaml --device /dev/cu.usbserial-210
```
