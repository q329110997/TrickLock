/*
 * keypad.h
 * 矩阵键盘编码
 */
 
#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../universal/type.h"

// @func 矩阵键盘编码
// @param void
// @return int16 返回编码值, -1为无按键时的编码值
int16 KeypadEncoding(void);

#endif  // KEYPAD_H_
