/*
 * macro.h
 * 定义通用的宏函数, 或各个模块的宏定义
 * 2019.06.29 19:53, 刘鑫<ginshio78@gmail.com>
 */

#ifndef MACRO_H_
#define MACRO_H_

// 模块宏定义
#define KEYPAD P1  // 矩阵键盘 (P1)

////////////////////////////////////
// 通用宏函数

////////////////////////////////////
// 通用定义
sbit my_sclk = P3^6;  // 移位寄存器时钟信号
sbit my_clk = P3^5;   // 存储寄存器时钟信号
sbit my_ser = P3^4;   // 串行输入口

#endif  // MACRO_H_
