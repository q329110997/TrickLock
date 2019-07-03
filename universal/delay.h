/*
 * delay.h
 * 针对晶振频率12MHz的C51时延操作
 * 2019.06.26 19:09, 刘鑫 <ginshio78@gmail.com>
 * 来源: 51单片机精确延时函数集锦 (https://mkblog.cn/428/)
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "type.h"

// @func  时延50Us (5 * 10^-2 s)
// @param n uint8 时延50us的多少倍
// @return void
// void Delay50Us(uint8 n);

// @func  时延1ms (1 * 10^-3 s)
// @param n uint8 时延1ms的多少倍
// @return void
void Delay1Ms(uint8 n);

// @func  时延50ms (5 * 10^-2 s)
// @param n uint8 时延50ms的多少倍
// @return void
void Delay50Ms(uint8 n);

// @func  时延1s
// @param n uint8 时延1s的多少倍
// @return void
void Delay1S(uint8 n);

#endif  // DELAY_H_
