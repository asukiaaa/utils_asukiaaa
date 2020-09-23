#ifndef _UTILS_ASUKIAAA_STRING_H_
#define _UTILS_ASUKIAAA_STRING_H_

#include <Arduino.h>

namespace utils_asukiaaa {
  namespace string {
    String padStart(String str, unsigned int len, char pad);
    String padNumStart(int num, unsigned int len, char pad);
    String padNumStart(float num, unsigned int len, char pad);
    String padEnd(String str, unsigned int len, char pad);
    String padNumEnd(int num, unsigned int len, char pad);
    String padNumEnd(float num, unsigned int len, char pad);
  }
}

#endif
