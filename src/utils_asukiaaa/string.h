#ifndef _UTILS_ASUKIAAA_STRING_H_
#define _UTILS_ASUKIAAA_STRING_H_

#include <Arduino.h>

namespace utils_asukiaaa {
  namespace string {
    String padStart(String str, int len, char pad) {
      while (str.length() < len) {
        str = pad + str;
      }
      return str;
    }

    String padEnd(String str, int len, char pad) {
      while (str.length() < len) {
        str += pad;
      }
      return str;
    }
  }
}

#endif
