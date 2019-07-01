/**************************************************************************************
*		              矩阵按键实验												  *
实现现象：下载程序后数码管显示0，按下矩阵按键上的按键显示对应的数字
			S1-S4：0-3
			S5-S8：4-7
			S9-S12：8-B
			S13-S16：C-F。
注意事项：如果不想让点阵模块显示，可以将74HC595模块上的JP595短接片拔掉。																				  
***************************************************************************************/

#include <reg52.h>			 //此文件中定义了单片机的一些特殊功能寄存器

#include "universal/macro.h"
#include "universal/type.h"
#include "universal/delay.h"
#include "universal/input.h"

#include "led/test_led.h"

int main(void) {
  int16 num;
  char passwd[4];
  while (1) {
    if (InputNumber(&num)) {
      test_input_number(num);
    }
    if (InputPasswd(passwd)) {
      test_input_passwd(passwd);
    }
  }
}