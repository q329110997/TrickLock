#include "keytest.h"

#include "universal/macro.h"
#include "universal/type.h"
#include "universal/delay.h"

#include "keyboard/keypad.h"
#include "keyboard/indepkey.h"
#include "keyboard/input.h"

#include "led/test_led.h"
#include "led/led_lattice.h"
#include "led/led_module.h"

#include <reg52.h>
#include <stdlib.h>


// @func 主函数, 密码锁
// @param void
// @return void
void main(void) {
  int16 encode_value;
	LedModuleLock();	
  while (1) {
    encode_value = IndepkeyEncoding();
    if (encode_value != -1) {
      KeyTest(encode_value);
    }
    encode_value = KeypadEncoding();
    if (encode_value != -1) {
      KeyTest(encode_value);
    }
  }
}