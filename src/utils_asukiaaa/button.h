#ifndef _UTILS_ASUKIAAA_BUTTON_H_
#define _UTILS_ASUKIAAA_BUTTON_H_

#include <Arduino.h>

#warning "utils_asukiaaa/button.h is deprecated. Use other lib button_asukiaaa instead."

namespace utils_asukiaaa {
  namespace button {
    class [[deprecated("Use ButtonState in button_asukiaaa instead.")]] ButtonState {
     public:
      ButtonState(bool pressedPinState = LOW, unsigned long bufferMs = 20UL);

      void update(bool newState);
      bool changedToPress();
      bool changedToRelease();
      bool isPresseing();
      bool isReleasing();

     private:
      unsigned long bufferMs;
      unsigned long changedAt;
      char timingState;
      bool onOverBufferTime;
      bool changedOverBufferTime;
      bool currentPinState;
      bool changedPinState;
      bool prevPinState;
      bool holedPinState;
      bool pressedPinState;
    };

    class [[deprecated("Use Button in button_asukiaaa instead.")]] Button: public ButtonState {
     public:
      Button(int pin,
             unsigned long bufferMs = 20UL,
             int pinModeOption = INPUT_PULLUP,
             bool pressedPinState = LOW);
      void begin();
      void update();

     private:
      int pin;
      int pinModeOption;
    };
  }
}

#endif
