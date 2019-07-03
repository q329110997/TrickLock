#include "keytest.h"

#include "universal/delay.h"
#include "universal/macro.h"
#include "universal/type.h"

#include "keyboard/input.h"

#include "led/led_lattice.h"
#include "led/led_module.h"

#include <reg52.h>

extern Infor infor;

static void beep__(void) {
  int8 n = 64;
  while (n--) {
    beep = ~beep;
    Delay1Ms(1);
  }
}

// @func 比较密码, 返回1则为true
// @param infor char[] 原始密码
// @param passwd char[] 输入密码
// @return bit 返回比较结果
static bit diff_passwd(char* infor, char* passwd) {
  uint8 i;
  for (i = 0; i < 4; ++i) {
    if (infor[i] != passwd[i]) {
      return 0;
    }
  }
  return 1;
}

// @func 设置密码
// @param infor char[] 原始密码
// @param passwd char[] 输入密码
// @return void
static void set_passwd(char* infor, char* passwd) {
  uint8 i;
  for (i = 0; i < 4; ++i) {
    infor[i] = passwd[i];
  }
}

// @func 输入密码函数
// @param N int* 地址传递N, 可错误次数, N为0x11时进行错误等待
// @return bit 返回输入状态, 若为1则输入成功
static bit InputPasswd__(uint8* N) {
  char password[4];
  while ((*N)--) {
    if (InputPasswd(password)) {
      if (diff_passwd(infor.passwd, password)) {
        return 1;
      }
      InputPasswdError();
    } else {
      InputCancel();
      return 0;
    }
  }
	*N = 0x11;
  return 0;
}

void KeyTest(int16 coding) {
  uint8 N;
  uint16 S = infor.s;
  char passwd[4], new_passwd[4];
  Sts now_status = infor.sts;
  int16 input_num;
  
  switch (coding) {
    case KEY_LOCK: {  // 加锁键
      LedModuleLock();
      LedLatticeLock();
      break;
    }
    case KEY_UNLOCK: {  // 解锁键
      if (now_status == LOCK) {
        N = infor.n;
        if (InputPasswd__(&N)) {
          LedModuleUnlock();
          LedLatticeUnlock();
          break;
        }
				if (N == 0x11) {
          infor.sts = ERROR;
          ErrorWait();
          LedModuleLock();
          beep__();
          Delay1S(infor.s);
          LedLatticeLock();
				}
      }
      break;
    }
    case KEY_S_N: {  // 设置N键
			N = infor.n;
      if (InputPasswd__(&N)) {
        InputPasswdSuccess();
        if (InputNumber(&input_num)) {
          infor.n = input_num;
          SetSuccess();
          break;
        }
      }
      break;
    }
    case KEY_S_S: {  // 设置S键
			N = infor.n;
      if (InputPasswd__(&N)) {
        InputPasswdSuccess();
        if (InputNumber(&input_num)) {
          infor.s = input_num;
          SetSuccess();
          break;
        }
      }
      break;
    }
    case KEY_S_PASSWD: {  // 设置密码键
			N = infor.n;
      if (InputPasswd__(&N)) {
        InputPasswdSuccess();
        if (InputPasswd(passwd)) {
          InputPasswdSuccess();
          if (InputPasswd(new_passwd)) {
            if (diff_passwd(passwd, new_passwd)) {
              set_passwd(infor.passwd, passwd);
              SetSuccess();
              if (infor.sts == UNLOCK) {
                LedModuleLock();
                LedLatticeLock();
              }
            } else {
              InputPasswdError();
            }
            break;
          }
          InputCancel();
          break;
        }
        InputCancel();
      }
      break;
    }
    default: {
      break;
    }
  }
}