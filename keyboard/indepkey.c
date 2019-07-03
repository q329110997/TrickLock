#include "indepkey.h"

#include "../universal/delay.h"
#include "../universal/macro.h"

#include <reg52.h>

// @func 生成独立键盘编码函数
#define GENE_ENCODE(x, z) \
  Delay1Ms(10);  \
  if (k##x == 0) {  \
    ret = z;  \
  }  \
  while (!k##x);

int16 IndepkeyEncoding(void) {
  int16 ret = -1;
  if (k1 == 0) {
    GENE_ENCODE(1, KEY_LOCK);
  }
	if (k2 == 0) {
    GENE_ENCODE(2, KEY_UNLOCK);
  }
	if (k3 == 0) {
    GENE_ENCODE(3, KEY_S_N);
  }
	if (k4 == 0) {
    GENE_ENCODE(4, KEY_S_S);
  }
  return ret;
}
