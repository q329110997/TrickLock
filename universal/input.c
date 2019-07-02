#include "input.h"

#include "delay.h"
#include "macro.h"

#include <string.h>

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
      while (a < 50 && KEYPAD != 0xF0) {
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

int16 Encoding(void) {
  int16 key = KeyDown();
  while (key == -1) {
    key = KeyDown();
  }
  switch (key) {
    case 0x00: {
      return 7;  // 7
    }
    case 0x01: {
      return 8;  // 8
    }
    case 0x02: {
      return 9;  // 9
    }
    case 0x03: {
      return 0x99;  // 设置密码
    }
    case 0x10: {
      return 4;  // 4
    }
    case 0x11: {
      return 5;  // 5
    }
    case 0x12: {
      return 6;  // 6
    }
    case 0x13: {
      return 0x88;  // 取消输入
    }
    case 0x20: {
      return 1;  // 1
    }
    case 0x21: {
      return 2;  // 2
    }
    case 0x22: {
      return 3;  // 3
    }
    case 0x23: {
      return 0x77;  // 删除输入
    }
    case 0x31: {
      return 0;  // 0
    }
    case 0x33: {
      return 0x66;  // 确认输入
    }
    default: {
      return 0x55;  // 空键
    }
  }
}

bit InputPasswd(char input[4]){
  uint8 i;
  int16 tmp;
  for (i = 1; i < 5; i++) {
    INPUT:
    tmp = Encoding();
    switch (tmp) {
      case 0x99:    // 设置密码
      case 0x66:    // 确认输入
      case 0x55: {  // 空键
        i--;
        break;
      }
      case 0x77: {  // 删除输入
        if (i != 1) {
          i--;
        }
        i--;
        break;
      }
      case 0x88: {  // 取消输入
        memset(input, 0, sizeof(input));
        return 0;
      }
      default: {
        input[i - 1] = tmp + '0';
      }
    }
  }
  while (1) {
    tmp = Encoding();
    switch (tmp) {
      case 0x66: {  // 确认输入
        return 1;
      }
      case 0x77: {  // 删除输入
        i = 4;
        goto INPUT;
      }
      case 0x88: {  // 取消输入
        memset(input, 0, sizeof(input));
        return 0;
      }
      default: {
        break;
      }
    }
  }
}

bit InputNumber(int16* input) {
  int16 tmp;
  *input = 0;
  while (1) {
    tmp = Encoding();
    switch (tmp) {
      case 0x99:    // 设置密码
      case 0x55: {  // 空键
        break;
      }
      case 0x66: {  // 确认输入
        if (*input == 0) {
          *input = 3;
        }
        return 1;
      }
      case 0x77: {  // 删除输入
        *input /= 10;
        break;
      }
      case 0x88: {  // 取消输入
        *input = 0;
        return 0;
      }
      default: {
        *input = *input * 10 + tmp;
      }
    }
  }
}