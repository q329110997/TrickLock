#include "keypad.h"

#include "../universal/delay.h"
#include "../universal/macro.h"

#include <reg52.h>

// @func 矩阵键盘按键检测
// @param void
// @return int16 用于编码
static int16 KeyDown(void) {
  uint8 a = 0;
  int16 col = -1, row = -1;
  KEYPAD = 0x0F;
  if (KEYPAD != 0x0F) {
    Delay1Ms(10);
    if (KEYPAD != 0x0F) {
      KEYPAD = 0x0F;  //测试列
      switch (KEYPAD) {
        case 0x07: {
          col = 0;
          break;
        }
        case 0x0B: {
          col = 1;
          break;
        }
        case 0x0D: {
          col = 2;
          break;
        }
        case 0x0E: {
          col = 3;
          break;
        }
      }
      KEYPAD = 0xF0;  //测试行
      switch (KEYPAD) {
        case 0x70: {
          row = 0;
          break;
        }
        case 0xB0: {
          row = 1;
          break;
        }
        case 0xD0: {
          row = 2;
          break;
        }
        case 0xE0: {
          row = 3;
          break;
        }
      }
      while (a < 45 && KEYPAD != 0xF0) {
        Delay1Ms(10);
        a++;
      }
    }
  }
  if (row == -1 || col == -1) {
    return -1;
  } else {
    return row * 0x10 + col;
  }
}

int16 KeypadEncoding(void) {
  int16 key = KeyDown();
  switch (key) {
    case -1: {   // 无输入
      return -1;
    }
    case S1: {
      return 7;  // 7
    }
    case S2: {
      return 8;  // 8
    }
    case S3: {
      return 9;  // 9
    }
    case S4: {
      return KEY_S_PASSWD;  // 设置密码
    }
    case S5: {
      return 4;  // 4
    }
    case S6: {
      return 5;  // 5
    }
    case S7: {
      return 6;  // 6
    }
    case S8: {
      return KEY_CANCEL;  // 取消输入
    }
    case S9: {
      return 1;  // 1
    }
    case S10: {
      return 2;  // 2
    }
    case S11: {
      return 3;  // 3
    }
    case S12: {
      return KEY_DELETE;  // 删除输入
    }
    case S14: {
      return 0;  // 0
    }
    case S16: {
      return KEY_CONFIRM;  // 确认输入
    }
    default: {
      return KEY_NULL;  // 空键
    }
  }
}
