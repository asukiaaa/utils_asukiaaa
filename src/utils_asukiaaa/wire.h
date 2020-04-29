#include <Arduino.h>
#include <Wire.h>

namespace utils_asukiaaa {
  namespace wire {
    int readBytes(TwoWire *wire, uint8_t deviceAddress, uint8_t registerAddress, uint8_t* data, uint8_t dataLen) {
      wire->beginTransmission(deviceAddress);
      wire->write(registerAddress);
      uint8_t result = wire->endTransmission();
      if (result != 0) {
        return result;
      }

      wire->requestFrom(deviceAddress, dataLen);
      uint8_t index = 0;
      while (wire->available()) {
        uint8_t d = wire->read();
        if (index < dataLen) {
          data[index++] = d;
        }
      }
      return 0;
    }

    int writeBytes(TwoWire *wire, uint8_t deviceAddress, uint8_t registerAddress, uint8_t* data, uint8_t dataLen) {
      wire->beginTransmission(deviceAddress);
      wire->write(registerAddress);
      wire->write(data, dataLen);
      return wire->endTransmission();
    }
  }
}
