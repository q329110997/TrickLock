#include "led_lattice.h"

#include "../universal/type.h"
#include "../universal/delay.h"
#include "../universal/macro.h"

#include <reg52.h>
#include <intrins.h>

extern Infor infor;

// LED 锁状态 段数据
static code uint8 led_lattice_lock_seg[] = {0x00, 0x0E, 0x3E, 0x4E, 0x4E, 0x3E, 0x0E, 0x00};
// LED 解锁状态 段数据
static code uint8 led_lattice_unlock_seg[] = {0x00, 0x0E, 0x6E, 0x8E, 0x8E, 0x7E, 0x0E, 0x00};
// LED 错误状态 段数据
static code uint8 led_lattice_error_seg[] = {0x81, 0x42, 0x24, 0x18, 0x18, 0x24, 0x42, 0x81};
// LED 设置成功 段数据
static code uint8 led_lattice_s_seg[] = {0x08, 0x04, 0x02, 0x01, 0x04, 0x10, 0x40, 0x00};
// LED 密码输入成功 段数据
static code uint8 led_lattice_success_seg[] = {0x3C, 0x42, 0x81, 0x81, 0x81, 0x81, 0x42, 0x3C};
// LED 等待状态 段数据
static code uint8 led_lattice_wait_seg[] = {0x00, 0x00, 0x04, 0x00, 0x04, 0x00, 0x04, 0x00};
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

void Lock4LedLattice(void) {
	uint8 i;
  LED_LATTICE = 0x7F;
  for (i = 0; i < 8; ++i) {
    LED_LATTICE = led_lattice_bit[i];
    SendByte4Hc595(led_lattice_lock_seg[i]);
    Delay1Ms(1);
    SendByte4Hc595(0x00);
  }
  LED_LATTICE = 0x00;
}

void Unlock4LedLattice(void) {
	uint8 i;
  LED_LATTICE = 0x7F;
  for (i = 0; i < 8; ++i) {
    LED_LATTICE = led_lattice_bit[i];
    SendByte4Hc595(led_lattice_unlock_seg[i]);
    Delay1Ms(1);
    SendByte4Hc595(0x00);
  }
  LED_LATTICE = 0x00;
}

void LedLatticeUnlock(void) {
  uint8 i = 3, j;
	infor.sts = UNLOCK;
  while (i--) {
    for (j = 60; j > 0; --j) {
      Lock4LedLattice();
    }
    for (j = 60; j > 0; --j) {
      Unlock4LedLattice();
    }
    Delay50Ms(6);
  }
}

void LedLatticeLock(void) {
  uint8 i = 3, j;
  infor.sts = LOCK;
  while (i--) {
    for (j = 60; j > 0; --j) {
      Unlock4LedLattice();
    }
    for (j = 60; j > 0; --j) {
      Lock4LedLattice();
    }
    Delay50Ms(6);
  }
}

void InputPasswdError(void) {
  uint8 i, j;
  for (j = 75; j > 0; --j) {
    LED_LATTICE = 0x7F;
    for (i = 0; i < 8; ++i) {
      LED_LATTICE = led_lattice_bit[i];
      SendByte4Hc595(led_lattice_error_seg[i]);
      Delay1Ms(1);
      SendByte4Hc595(0x00);
    }
    LED_LATTICE = 0x00;
  }
}

void InputPasswdSuccess(void) {
  uint8 i, j;
  for (j = 75; j > 0; --j) {
    LED_LATTICE = 0x7F;
    for (i = 0; i < 8; ++i) {
      LED_LATTICE = led_lattice_bit[i];
      SendByte4Hc595(led_lattice_success_seg[i]);
      Delay1Ms(1);
      SendByte4Hc595(0x00);
    }
    LED_LATTICE = 0x00;
  }
}

void SetSuccess(void) {
  uint8 i, j;
  for (j = 75; j > 0; --j) {
    LED_LATTICE = 0x7F;
    for (i = 0; i < 8; ++i) {
      LED_LATTICE = led_lattice_bit[i];
      SendByte4Hc595(led_lattice_s_seg[i]);
      Delay1Ms(1);
      SendByte4Hc595(0x00);
    }
    LED_LATTICE = 0x00;
  }
}

void ErrorWait(void) {
  uint8 i, j, k;
  for (k = 3; k > 0; --k) {
    for (j = 55; j > 0; --j) {
      LED_LATTICE = 0x7F;
      for (i = 0; i < 8; ++i) {
        LED_LATTICE = led_lattice_bit[i];
        SendByte4Hc595(led_lattice_wait_seg[i]);
        Delay1Ms(1);
        SendByte4Hc595(0x00);
      }
      LED_LATTICE = 0x00;
    }
    Delay50Ms(3);
  }
}
