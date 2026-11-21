#include <LiquidCrystal.h>

constexpr uint8_t LCD_RS_PIN = 8;
constexpr uint8_t LCD_ENABLE_PIN = 9;
constexpr uint8_t LCD_D4_PIN = 4;
constexpr uint8_t LCD_D5_PIN = 5;
constexpr uint8_t LCD_D6_PIN = 6;
constexpr uint8_t LCD_D7_PIN = 7;
constexpr uint8_t LCD_BACKLIGHT_PIN = 10;
constexpr uint8_t KEYPAD_PIN = A0;

LiquidCrystal lcd(
  LCD_RS_PIN,
  LCD_ENABLE_PIN,
  LCD_D4_PIN,
  LCD_D5_PIN,
  LCD_D6_PIN,
  LCD_D7_PIN
);

enum Key : uint8_t {
  KEY_NONE,
  KEY_RIGHT,
  KEY_UP,
  KEY_DOWN,
  KEY_LEFT,
  KEY_SELECT
};

Key lastReportedKey = KEY_NONE;
unsigned long lastButtonChange = 0;
constexpr unsigned long DEBOUNCE_MS = 40;

Key readKeypad() {
  const int value = analogRead(KEYPAD_PIN);

  if (value < 50) return KEY_RIGHT;
  if (value < 200) return KEY_UP;
  if (value < 350) return KEY_DOWN;
  if (value < 500) return KEY_LEFT;
  if (value < 800) return KEY_SELECT;
  return KEY_NONE;
}

const char* keyName(Key key) {
  switch (key) {
    case KEY_RIGHT: return "RIGHT";
    case KEY_UP: return "UP";
    case KEY_DOWN: return "DOWN";
    case KEY_LEFT: return "LEFT";
    case KEY_SELECT: return "SELECT";
    default: return "NONE";
  }
}

void setup() {
  pinMode(LCD_BACKLIGHT_PIN, OUTPUT);
  analogWrite(LCD_BACKLIGHT_PIN, 255);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("DF Robot Shield");
  lcd.setCursor(0, 1);
  lcd.print("Press a key");

  Serial.begin(9600);
  Serial.println("DF Robot LCD Keypad Shield");
}

void loop() {
  const Key key = readKeypad();
  const unsigned long now = millis();

  if (key != lastReportedKey && now - lastButtonChange >= DEBOUNCE_MS) {
    lastButtonChange = now;
    lastReportedKey = key;

    lcd.setCursor(0, 1);
    lcd.print("Key: ");
    lcd.print(keyName(key));
    lcd.print("     ");

    Serial.print("Key: ");
    Serial.println(keyName(key));
  }
}
