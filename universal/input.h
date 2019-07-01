/*
 */

#ifndef PASSWORD_H_
#define PASSWORD_H_

#include <reg52.h>

#include "type.h"

// 
int16 Encoding(void);

// @func 输入密码
// @param input char[4] 获取输入的四位密码
// @return void
bit InputPasswd(char input[4]);

// @func 输入整数
// @param void
// @return uint16 获取输入的整数
bit InputNumber(int16* input);

#endif