# Goal
This is code for an Arduino Uno and a LCD keypad shield (DF Robot).

## LCD keypad demo

Open `arduino-uno-display.ino` in the Arduino IDE, select the Arduino Uno board
and `/dev/cu.usbmodem2101` as the port, and upload it.

The sketch displays the currently pressed keypad button on the LCD and also
sends `RIGHT`, `UP`, `DOWN`, `LEFT`, `SELECT`, or `NONE` to the serial monitor
at 9600 baud.


