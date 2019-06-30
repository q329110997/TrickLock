/*
 * led.h
 * 使用LED显示锁和解锁状态
 * 2019.06.29 19:56, 刘鑫<ginshio78@gmail.com>
 */

#ifndef LED_H_
#define LED_H_

// @func 锁状态显示, 采用按键中断
// @param void
// @return void
void Lock4Led(void);

// @func 解锁状态显示, 采用软件判断
// @param void
// @return void
void Unlock4Led(void);

#endif  // LED_H_
