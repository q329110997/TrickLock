#include "test_led.h"

#include "../universal/delay.h"
#include "../universal/macro.h"

#include <reg52.h>
#include <intrins.h>

// LED 数字 段数据
static code uint8 led_lattice_seg[10][8] = {
  {0x00, 0x00, 0x7F, 0x41, 0x41, 0x7F, 0x00, 0x00},  // 0
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0x00, 0x00},  // 1
  {0x00, 0x00, 0x4F, 0x49, 0x49, 0x79, 0x00, 0x00},  // 2
  {0x00, 0x00, 0x49, 0x49, 0x49, 0x7F, 0x00, 0x00},  // 3
  {0x00, 0x00, 0x78, 0x08, 0x08, 0x7F, 0x00, 0x00},  // 4
  {0x00, 0x00, 0x79, 0x49, 0x49, 0x4F, 0x00, 0x00},  // 5
  {0x00, 0x00, 0x7F, 0x49, 0x49, 0x4F, 0x00, 0x00},  // 6
  {0x00, 0x00, 0x40, 0x40, 0x40, 0x7F, 0x00, 0x00},  // 7
  {0x00, 0x00, 0x7F, 0x49, 0x49, 0x7F, 0x00, 0x00},  // 8
  {0x00, 0x00, 0x79, 0x49, 0x49, 0x7F, 0x00, 0x00}   // 9
};
// LED 位数据
static code uint8 led_lattice_bit[] = {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE};

// @func 向 HC595 发送一字节信息, 控制 LED 点阵
static void SendByte4Hc595(uint8 dat) {
  uint8 a;
  my_sclk = 0;
  my_clk = 0;
  for (a = 0; a < 8; ++a) {
    my_ser = dat >> 7;
    dat <<= 1;
    my_sclk = 1;
    _nop_();
    _nop_();
    my_sclk = 0;
  }
  my_clk = 1;
  _nop_();
  _nop_();
  my_clk = 0;
}

// @func 在LED上输出结果
// @param j uint8 带输出的字节
// @return void
static void led_lattice_output(uint8 j) {
  uint8 i;
  LED_LATTICE = 0x7F;
  for (i = 0; i < 8; ++i) {
    LED_LATTICE = led_lattice_bit[i];
    SendByte4Hc595(led_lattice_seg[j][i]);
    Delay1Ms(1);
    SendByte4Hc595(0x00);
  }
  LED_LATTICE = 0x00;
}

void test_input_passwd(char passwd[4]) {
  uint8 i, t;
  for (i = 0; i < 4; ++i) {
    for (t = 66; t > 0; --t) {
      led_lattice_output(passwd[i] - '0');
    }
  }
}

void test_input_number(uint16 num) {
  uint8 tmp, i;
  while (num) {
    tmp = num % 10;
    num /= 10;
    for (i = 66; i > 0; --i) {
      led_lattice_output(tmp);
    }
  }
}
