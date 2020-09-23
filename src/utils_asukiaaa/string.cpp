#include "utils_asukiaaa/string.h"

namespace utils_asukiaaa {
  namespace string {
    String padStart(String str, unsigned int len, char pad) {
      while (str.length() < len) {
        str = pad + str;
      }
      return str;
    }

    String padNumStart(int num, unsigned int len, char pad) {
      return padStart(String(num), len, pad);
    }

    String padNumStart(float num, unsigned int len, char pad) {
      return padStart(String(num), len, pad);
    }

    String padEnd(String str, int unsigned len, char pad) {
      while (str.length() < len) {
        str += pad;
      }
      return str;
    }

    String padNumEnd(int num, unsigned int len, char pad) {
      return padEnd(String(num), len, pad);
    }

    String padNumEnd(float num, unsigned int len, char pad) {
      return padEnd(String(num), len, pad);
    }
  }
}
