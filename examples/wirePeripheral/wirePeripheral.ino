#include <utils_asukiaaa.h>
#include <utils_asukiaaa/wire.h>

#define DEVICE_ADDRESS 0x61

const uint16_t registerLen = 10;
utils_asukiaaa::wire::PeripheralHandler wirePeri(&Wire, registerLen);
unsigned long handledReceivedAt = 0;

void setup() {
  Wire.onReceive([](int v) { wirePeri.onReceive(v); });
  Wire.onRequest([]() { wirePeri.onRequest(); });
  Wire.begin(DEVICE_ADDRESS);
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  if (wirePeri.receivedAt != handledReceivedAt) {
    handledReceivedAt = wirePeri.receivedAt;
    for (int i = 0; i < wirePeri.buffLen; ++i) {
      Serial.print(wirePeri.buffs[i]);
      Serial.print(" ");
    }
    Serial.println();
    Serial.println("receivedAt: " + String(wirePeri.receivedAt));
  }
  wirePeri.buffs[wirePeri.buffLen - 1] = millis() / 1000 % 0xff;
  delay(1);
}
