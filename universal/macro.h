/*
 * macro.h
 * 定义通用的宏函数, 或各个模块的宏定义、端口定义
 * 2019.06.29 19:53, 刘鑫<ginshio78@gmail.com>
 */

#ifndef MACRO_H_
#define MACRO_H_

#include <reg52.h>

////////////////////////////////////
// 模块宏定义
#define LED_LATTICE  P0  // LED 点阵 (P0)
#define LCD          P0  // LCD1602  (P0)
#define KEYPAD       P1  // 矩阵键盘 (P1)
#define LED_MODULE   P2  // LED 模块 (P2)

// 矩阵键盘
#define KEY_S_PASSWD  0x99   // 设置密码键
#define KEY_CANCEL    0x88   // 取消键
#define KEY_DELETE    0x77   // 删除键
#define KEY_CONFIRM   0x66   // 确认键
#define KEY_NULL      0x55   // 空键

// 独立键盘
#define KEY_LOCK      0xF0   // 锁
#define KEY_UNLOCK    0x0F   // 解锁
#define KEY_S_N       0x33   // 设置N
#define KEY_S_S       0x44   // 设置S

////////////////////////////////////
// 通用宏函数

////////////////////////////////////
// 通用端口定义
sbit k1 = P3^1;  // 独立键盘 K1
sbit k2 = P3^0;  // 独立键盘 K2
sbit k3 = P3^2;  // 独立键盘 K3
sbit k4 = P3^3;  // 独立键盘 K4

sbit my_sclk = P3^6;  // 移位寄存器时钟信号
sbit my_clk = P3^5;   // 存储寄存器时钟信号
sbit my_ser = P3^4;   // 串行输入口

#endif  // MACRO_H_
