#include <utils_asukiaaa.h>
#include <utils_asukiaaa/button.h>

#define PIN_BTN 10
#define PIN_LED LED_BUILTIN

utils_asukiaaa::button::Button btn(PIN_BTN);

void setup() {
  btn.begin();
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  btn.update();
  if (btn.changedToPress()) {
    Serial.println("pressed");
  } else if (btn.changedToRelease()) {
    Serial.println("released");
  }
  digitalWrite(PIN_LED, btn.isPresseing());
}
