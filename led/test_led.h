/*
 * test_led.h
 * 读入输入, 在 led点阵 上, 输出相应的数字
 * 2019.07.01 15:56, 刘鑫 <ginshio78@gmail.com> 
 */
 
#ifndef TEST_LED_H_
#define TEST_LED_H_

#include "../universal/type.h"

// @func 在LED点阵上输出密码
// @param passwd char[] 用户从矩阵键盘输入的密码
// @return void
void test_input_passwd(char passwd[4]);

// @func 在LED点阵上逆序输出数字
// @param num uint16 用户从矩阵键盘输入的数字
// @return void
void test_input_number(uint16 num);

#endif  // TEST_LED_H_
