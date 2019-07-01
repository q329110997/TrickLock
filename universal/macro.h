/*
 * macro.h
 * 定义通用的宏函数, 或各个模块的宏定义、端口定义
 * 2019.06.29 19:53, 刘鑫<ginshio78@gmail.com>
 */

#ifndef MACRO_H_
#define MACRO_H_

// 模块宏定义
#define LED_LATTICE P0  // LED 点阵 (P0)
#define LCD P0          // LCD1602  (P0)
#define KEYPAD P1       // 矩阵键盘 (P1)
#define LED_MODULE P2   // LED 模块 (P2)

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
