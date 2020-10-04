#ifndef _UTILS_ASUKIAAA_WIRE_H_
#define _UTILS_ASUKIAAA_WIRE_H_

#include <Arduino.h>
#include <Wire.h>

#warning "utils_asukiaaa/wire.h is deprecated. Use other lib wire_asukiaaa instead."

namespace utils_asukiaaa {
  namespace wire {
    [[deprecated("Use readBytes in wire_asukiaaa instead.")]]
    int readBytes(TwoWire *wire, uint8_t deviceAddress, uint8_t registerAddress, uint8_t* data, uint8_t dataLen);
    [[deprecated("Use writeBytes in wire_asukiaaa instead.")]]
    int writeBytes(TwoWire *wire, uint8_t deviceAddress, uint8_t registerAddress, uint8_t* data, uint8_t dataLen);

    class [[deprecated("Use PeripheralHandler in wire_asukiaaa instead.")]] PeripheralHandler {
    public:
      PeripheralHandler(TwoWire* wire, int buffLen, bool (*prohibitWriting)(int index) = NULL);
      ~PeripheralHandler();
      void onReceive(int);
      void onRequest();
      uint8_t* buffs;
      int buffLen;
      unsigned long receivedAt;
      int receivedLen;

    private:
      TwoWire* wire;
      int buffIndex;
      bool (*prohibitWriting)(int index);
    };
  }
}

#endif
