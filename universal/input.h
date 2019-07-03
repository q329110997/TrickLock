/*
 * input.h
 * ???
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "type.h"

#include <reg52.h>

// @func 输入密码
// @param input char[4] 获取输入的四位密码
// @return void
bit InputPasswd(char input[]);

// @func 输入整数
// @param void
// @return uint16 获取输入的整数
bit InputNumber(int16* input);

#endif  // INPUT_H_
