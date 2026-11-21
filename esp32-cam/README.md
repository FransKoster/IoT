# ESP32-CAM

This folder contains the ESPHome configuration for an ESP32-CAM module (OV2640).

## Files

- `esp32-cam.yaml`: main ESPHome configuration
- `secrets.yaml`: local Wi-Fi and fallback access-point password; ignored by Git

## Hardware configuration

- **Board:** ESP32-CAM / ESP32-WROVER (ESP32 dev board variant)
- **Host name:** `esp32-cam`
- **Camera:** OV2640
- **Resolution:** VGA
- **JPEG quality:** 10
- **External clock:** GPIO0 at 20 MHz
- **I2C:** SDA GPIO26, SCL GPIO27
- **Power down:** GPIO32
- **Camera data:** GPIO5, 18, 19, 21, 34, 35, 36, 39
- **VSYNC:** GPIO25
- **HREF:** GPIO23
- **Pixel clock:** GPIO22

The board starts an `ESP32-CAM` fallback access point when normal Wi-Fi cannot be reached.

## Secrets

Create `secrets.yaml` beside the configuration:

```yaml
wifi_ssid: "your-wifi-network"
wifi_password: "your-wifi-password"
fallback_ap_password: "your-fallback-password"
```

## Camera endpoints

After flashing and connecting to Wi-Fi:

- Stream: `http://<device-ip>:8080`
- Snapshot: `http://<device-ip>:8081`

## Build and flash

```bash
esphome compile esp32-cam.yaml
esphome run esp32-cam.yaml --device /dev/cu.usbserial-210
```
