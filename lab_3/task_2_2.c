#include <stdio.h>

union Number {
  unsigned long value;
  unsigned char bytes[sizeof(unsigned long)];
};

int main() {
  union Number num;
  num.value = 0x123456ABCDEF;

  for (int i = 0; i < sizeof(unsigned long); i++) {
    printf("%02X", num.bytes[i]);
  }

  return 0;
}
