# utils_asukiaaa

Utility library to supply useful functions for Arduino.

# Usage

## string

See [an example project for string](./examples/string/string.ino).

Include
```c
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
#include <utils_asukiaaa/wire.h>
```

Valus for example
```c
#define TARGET_DEVICE_ADDRESS 0x08
#define TARGET_WRITE_REGISTER_ADDRESS 0x00
#define TARGET_READ_REGISTER_ADDRESS 0x03
```

writeBytes
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

readBytes
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

# License

MIT
