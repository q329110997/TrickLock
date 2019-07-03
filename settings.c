#include "settings.h"

#include "universal/delay.h"
#include "universal/macro.h"
#include "universal/type.h"
#include "universal/input.h"

#include "led/led_lattice.h"
#include "led/led_module.h"
#include "led/test_led.h"

#include <reg52.h>

extern Infor infor;

static bit diff_passwd(char* infor, char* passwd) {
  uint8 i;
  for (i = 0; i < 4; ++i) {
    if (infor[i] != passwd[i]) {
      return 0;
    }
  }
  return 1;
}

static void set_passwd(char* infor, char* passwd) {
  uint8 i;
  for (i = 0; i < 4; ++i) {
    infor[i] = passwd[i];
  }
}

static uint8 InputPasswd__(uint8* N) {
  char password[4];
  while (N--) {
    if (InputPasswd(password)) {
      if (diff_passwd(infor.passwd, password)) {
        return 1;
      }
      InputPasswdError();
    } else {
      LedModuleLock();
      return 0;
    }
  }
  return 0x11;
}

void setting(int16 coding) {
  uint8 N;
  uint16 S = infor.s;
  char passwd[4];
  Sts now_status = infor.sts;
  int16 input_num;
  
  switch (coding) {
    case KEY_LOCK: {
      LedModuleLock();
      LedLatticeLock();
      break;
    }
    case KEY_UNLOCK: {
      if (now_status != UNLOCK) {
        N = infor.n
        if (InputPasswd__(&N)) {
          LedModuleUnlock();
          LedLatticeUnlock();
          break;
        }
        // TODO
      }
      break;
    }
    case KEY_S_N: {
      if (InputPasswd__(infor.n)) {
        InputPasswdSuccess();
        if (InputNumber(&input_num)) {
          infor.n = input_num;
          test_input_number(infor.n);
          // SetSuccsse();
          break;
        }
      }
      LedLatticeLock();
      break;
    }
    case KEY_S_S: {
      if (InputPasswd__(infor.n)) {
        InputPasswdSuccess();
        if (InputNumber(&input_num)) {
          infor.s = input_num;
          test_input_number(infor.s);
          // SetSuccsse();
          break;
        }
      }
      LedLatticeLock();
      break;
    }
    case KEY_S_PASSWD: {
      if (InputPasswd__(infor.n)) {
        InputPasswdSuccess();
        if (InputPasswd(passwd)) {
          set_passwd(infor.passwd, passwd);
          // SetSuccsse();
          test_input_passwd(infor.passwd);
          break;
        }
      }
      LedLatticeLock();
    }
    default: {
      break;
    }
  }
}