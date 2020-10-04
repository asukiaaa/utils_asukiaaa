#ifndef _UTILS_ASUKIAAA_STRING_H_
#define _UTILS_ASUKIAAA_STRING_H_

#include <Arduino.h>

#warning "utils_asukiaaa/string.h is deprecated. Use other lib string_asukiaaa instead."

namespace utils_asukiaaa {
  namespace string {
    [[deprecated("Use padStart in string_asukiaaa instead.")]]
    String padStart(String str, unsigned int len, char pad);
    [[deprecated("Use padNumStart in string_asukiaaa instead.")]]
    String padNumStart(int num, unsigned int len, char pad);
    [[deprecated("Use padNumStart in string_asukiaaa instead.")]]
    String padNumStart(float num, unsigned int len, char pad);
    [[deprecated("Use padEnd in string_asukiaaa instead.")]]
    String padEnd(String str, unsigned int len, char pad);
    [[deprecated("Use padNumEnd in string_asukiaaa instead.")]]
    String padNumEnd(int num, unsigned int len, char pad);
    [[deprecated("Use padNumEnd in string_asukiaaa instead.")]]
    String padNumEnd(float num, unsigned int len, char pad);
  }
}

#endif
