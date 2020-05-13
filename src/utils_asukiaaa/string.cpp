#include <utils_asukiaaa/string.h>

namespace utils_asukiaaa {
  namespace string {
    String padStart(String str, int len, char pad) {
      while (str.length() < len) {
        str = pad + str;
      }
      return str;
    }

    String padNumStart(int num, int len, char pad) {
      return padStart(String(num), len, pad);
    }

    String padNumStart(float num, int len, char pad) {
      return padStart(String(num), len, pad);
    }

    String padEnd(String str, int len, char pad) {
      while (str.length() < len) {
        str += pad;
      }
      return str;
    }

    String padNumEnd(int num, int len, char pad) {
      return padEnd(String(num), len, pad);
    }

    String padNumEnd(float num, int len, char pad) {
      return padEnd(String(num), len, pad);
    }
  }
}
