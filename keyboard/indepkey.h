/*
 * indepkey.h
 * 独立键盘编码
 */
 
#ifndef INDEP_KEY_H_
#define INDEP_KEY_H_

#include "../universal/type.h"

// @func 独立键盘编码
// @param void
// @return int16 返回编码值, -1为无按键时的编码值
int16 IndepkeyEncoding(void);

#endif  // INDEP_KEY_H_
