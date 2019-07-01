/*
 * led.h
 * 使用LED显示锁和解锁状态
 * 2019.06.29 19:56, 刘鑫<ginshio78@gmail.com>
 */

#ifndef LED_H_
#define LED_H_

// @func LED锁状态显示
// @param void
// @return void
void Lock4Led(void);

// @func LED解锁状态显示
// @param void
// @return void
void Unlock4Led(void);

// @func LED解锁动画
// @param void
// @return void
void LedUnlock(void);

// @func LED锁动画
// @param void
// @return void
void LedLock(void);

#endif  // LED_H_
