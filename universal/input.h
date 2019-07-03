/*
 * input.h
 * 矩阵按键输入
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "type.h"

#include <reg52.h>

// @func 输入密码
// @param input char[] 获取输入的四位密码
// @return bit 是否输入成功, 返回1则成功
bit InputPasswd(char input[]);

// @func 输入整数
// @param input int16* 传入input的地址, 获取输入值
// @return bit 是否输入成功, 返回1则成功
bit InputNumber(int16* input);

#endif  // INPUT_H_
