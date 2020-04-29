#include <utils_asukiaaa/string.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long nowMs = millis();
  Serial.println(nowMs);
  Serial.println(utils_asukiaaa::string::padStart(String(nowMs), 10, ' ') + "ms");
  Serial.println(utils_asukiaaa::string::padEnd(String(nowMs), 10, ' ') + "ms");
}
