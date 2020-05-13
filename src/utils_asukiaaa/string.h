#ifndef _UTILS_ASUKIAAA_STRING_H_
#define _UTILS_ASUKIAAA_STRING_H_

#include <Arduino.h>

namespace utils_asukiaaa {
  namespace string {
    String padStart(String str, int len, char pad);
    String padNumStart(int num, int len, char pad);
    String padNumStart(float num, int len, char pad);
    String padEnd(String str, int len, char pad);
    String padNumEnd(int num, int len, char pad);
    String padNumEnd(float num, int len, char pad);
  }
}

#endif
