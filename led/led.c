#include "led.h"
#include "../universal/type.h"
#include "../universal/delay.h"

#include <reg52.h>
#include <intrins.h>

sbit my_sclk = P3^6;  // 移位寄存器时钟信号
sbit my_clk = P3^5;   // 存储寄存器时钟信号
sbit my_ser = P3^4;    // 串行输入口

// LED 锁状态 段数据
code uint8 led_lock_seg[] = {0x00, 0x0E, 0x3E, 0x4E, 0x4E, 0x3E, 0x0E, 0x00};
// LED 解锁状态 段数据
code uint8 led_unlock_seg[] = {0x00, 0x0E, 0x6E, 0x8E, 0x8E, 0x7E, 0x0E, 0x00};
// LED 位数据
code uint8 led_bit[] = {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE};

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

void Lock4Led(void) {
	uint8 i;
  Infor* infor = generator_infor();
  infor->set_sts(LOCK);
  P0 = 0x7F;
  for (i = 0; i < 8; ++i) {
    P0 = led_bit[i];
    SendByte4Hc595(led_lock_seg[i]);
    Delay1Ms(1);
    SendByte4Hc595(0x00);
  }
  P0 = 0x00;
}

void Unlock4Led(void) {
	uint8 i;
  Infor* infor = generator_infor();
  infor->set_sts(UNLOCK);
  P0 = 0x7F;
  for (i = 0; i < 8; ++i) {
    P0 = led_bit[i];
    SendByte4Hc595(led_unlock_seg[i]);
    Delay1Ms(1);
    SendByte4Hc595(0x00);
  }
  P0 = 0x00;
}
