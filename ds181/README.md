# DS181 Multi-Sensor

This folder contains an ESPHome configuration for multiple Dallas-family temperature sensors
connected to an Adafruit HUZZAH ESP8266 board through a shared GPIO one-wire bus.

## Files

- `ds181.yaml`: ESPHome device and sensor configuration
- `.gitignore`: excludes generated ESPHome output

## Hardware

- **Board:** Adafruit HUZZAH ESP8266
- **Device name:** `ds181multi`
- **One-wire platform:** GPIO
- **Data pin:** GPIO2
- **Power:** Connect sensors to a suitable 3.3 V supply and common ground
- **Pull-up:** Provide a suitable pull-up resistor from the one-wire data line to 3.3 V

All five sensors share the same bus and are selected by their unique 64-bit address. Find these addresses by reading the logs at startup:

```
[13:50:59.300][C][gpio.one_wire:020]: GPIO 1-wire bus:
[13:50:59.300][C][gpio.one_wire:137]:   Pin: GPIO2
[13:50:59.300][C][gpio.one_wire:091]:   Found devices:
[13:50:59.329][C][gpio.one_wire:094]:     0x09030297793dd828 (DS18B20)
[13:50:59.329][C][gpio.one_wire:094]:     0x78030297792e1c28 (DS18B20)
```

Measurements are refreshed every 30 seconds.

| Sensor | Address |
| --- | --- |
| `temp 1` | `0x09030297793DD828` |
| `temp 2` | `0x78030297792E1C28` |


## Network and services

The configuration connects directly to the configured Wi-Fi network and enables:

- ESPHome logger
- Home Assistant native API
- ESPHome OTA updates

The Wi-Fi credentials are currently stored directly in `ds181.yaml`. Consider moving them
to an ignored `secrets.yaml` before committing real credentials.

## Build and flash

Run ESPHome from this folder:

```bash
esphome compile ds181.yaml
esphome run ds181.yaml --device /dev/ttyUSB0
```

The serial device path varies by operating system and adapter. After the initial flash,
subsequent uploads can normally use the device hostname over the network.
