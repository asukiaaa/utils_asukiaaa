#ifndef _UTILS_ASUKIAAA_WIRE_H_
#define _UTILS_ASUKIAAA_WIRE_H_

#include <Arduino.h>
#include <Wire.h>

namespace utils_asukiaaa {
  namespace wire {
    int readBytes(TwoWire *wire, uint8_t deviceAddress, uint8_t registerAddress, uint8_t* data, uint8_t dataLen);
    int writeBytes(TwoWire *wire, uint8_t deviceAddress, uint8_t registerAddress, uint8_t* data, uint8_t dataLen);

    class PeripheralHandler {
    public:
      PeripheralHandler(TwoWire* wire, int buffLen);
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
    };
  }
}

#endif
