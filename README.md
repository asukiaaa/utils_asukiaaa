# utils_asukiaaa

Utility library to supply useful functions for Arduino.

# Usage

## button

See [an example project for button](./examples/button/button.ino).

Include
```c
#include <utils_asukiaaa.h>
#include <utils_asukiaaa/button.h>
```

Define with gpio pin
```c
#define PIN_BTN 10
utils_asukiaaa::button::Button btn(PIN_BTN);
```

Call update in loop to check pin state
```
void loop() {
  btn.update();
}
```

Call process on changed to release or press
```
if (btn.changedToPress()) {
  // process on change to press
} else if (btn.changedToRelease()) {
  // process on change to release
}
```

Call process by button state
```
if (btn.isPressing()) {
  // process during pressed
} else { // btn.isReleasing()
  // process during released
}
```

## string

See [an example project for string](./examples/string/string.ino).

Include
```c
#include <utils_asukiaaa.h>
#include <utils_asukiaaa/string.h>
```

padStart and padEnd
```c
// strA becomes "0000000123"
String strA = utils_asukiaaa::string::padStart("123", 10, '0'));
// strB becomes "bb--------"
String strB = utils_asukiaaa::string::padEnd("bb", 10, '-'));
```

padNumStart and padNumEnd
```c
// strA becomes "0000000123"
String strA = utils_asukiaaa::string::padNumStart(123, 10, '0'));
// strB becomes "99--------"
String strB = utils_asukiaaa::string::padNumEnd(99, 10, '-'));
```

## wire

See [an example project for wire](./examples/wire/wire.ino).

Include
```c
#include <utils_asukiaaa.h>
#include <utils_asukiaaa/wire.h>
```

Valus for example
```c
#define TARGET_DEVICE_ADDRESS 0x08
#define TARGET_WRITE_REGISTER_ADDRESS 0x00
#define TARGET_READ_REGISTER_ADDRESS 0x03
```

### writeBytes
```c
uint8_t dataToWrite[] = {0, 1, 2};
uint8_t writeLen = 3;
int writeResult = utils_asukiaaa::wire::writeBytes(&Wire, TARGET_DEVICE_ADDRESS, TARGET_WRITE_REGISTER_ADDRESS, dataToWrite, writeLen);
if (writeResult != 0) {
   Serial.println("Failed to write because of error" + String(writeResult));
} else {
  Serial.println("Succeeded writing");
}
```

### readBytes
```c
uint8_t readLen = 3;
uint8_t dataThatRead[readLen];
int readResult = utils_asukiaaa::wire::readBytes(&Wire, TARGET_DEVICE_ADDRESS, TARGET_READ_REGISTER_ADDRESS, dataThatRead, readLen);
if (readResult != 0) {
  Serial.println("Failed to read because of error" + String(readResult));
} else {
  Serial.println("Succeeded reading");
  Serial.print("Received:");
  for (int i = 0; i < readLen; ++i) {
    Serial.print(" ");
    Serial.print(dataThatRead[i]);
  }
  Serial.println("");
}
```

### PeripheralHandler
See [wirePheripheral](examples/wirePeripheral/wirePheripheral.ino) example.
```c
const uint16_t registerLen = 10;
utils_asukiaaa::wire::PeripheralHandler wirePeri(&Wire, registerLen);
unsigned long handledReceivedAt = 0;

void setup() {
  Wire.onReceive([](int v) { wirePeri.onReceive(v); });
  Wire.onRequest([]() { wirePeri.onRequest(); });
  Wire.begin(DEVICE_ADDRESS);
}

void loop() {
  if (wirePeri.receivedAt != handledReceivedAt) {
    handledReceivedAt = wirePeri.receivedAt;
    // Do something for wirePeri.buffLen;
  }
}
```

It can prohibit writing for register by index.
```
const uint16_t registerLen = 10;
bool prohibitWriting(int index) {
  // Example: Prohibit writing for last register
  return index == registerLen - 1;
}
utils_asukiaaa::wire::PeripheralHandler wirePeri(&Wire, registerLen, prohibitWriting);
```

# License

MIT
