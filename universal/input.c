#include "input.h"

#include "delay.h"
#include "macro.h"

#include "../keyboard/keypad.h"

#include <string.h>

// @func 比较tmp与-1是否相等, 相等为无按键, 直到有按键中止
#define TMPEQ_1() \
  tmp = KeypadEncoding();  \
  while (tmp == -1) {  \
    tmp = KeypadEncoding();  \
  }

bit InputPasswd(char input[]){
  uint8 i;
  int16 tmp;
  for (i = 1; i < 5; i++) {
    INPUT:
    TMPEQ_1();
    switch (tmp) {
      case KEY_S_PASSWD:  // 设置密码
      case KEY_CONFIRM:   // 确认输入
      case KEY_NULL: {    // 空键
        i--;
        break;
      }
      case KEY_DELETE: {  // 删除输入
        if (i != 1) {
          i--;
        }
        i--;
        break;
      }
      case KEY_CANCEL: {  // 取消输入
        memset(input, 0, sizeof(input));
        return 0;
      }
      default: {
        input[i - 1] = tmp + '0';
      }
    }
  }
  while (1) {
    TMPEQ_1();
    switch (tmp) {
      case KEY_CONFIRM: {  // 确认输入
        return 1;
      }
      case KEY_DELETE: {   // 删除输入
        i = 4;
        goto INPUT;
      }
      case KEY_CANCEL: {   // 取消输入
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
    TMPEQ_1();
    switch (tmp) {
      case KEY_S_PASSWD:    // 设置密码
      case KEY_NULL: {      // 空键
        break;
      }
      case KEY_CONFIRM: {   // 确认输入
        if (*input == 0) {
          *input = 3;
        }
        return 1;
      }
      case KEY_DELETE: {   // 删除输入
        *input /= 10;
        break;
      }
      case KEY_CANCEL: {   // 取消输入
        *input = 0;
        return 0;
      }
      default: {
        *input = *input * 10 + tmp;
      }
    }
  }
}