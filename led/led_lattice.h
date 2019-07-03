/*
 * led.h
 * 使用LED显示锁和解锁状态
 * 2019.06.29 19:56, 刘鑫<ginshio78@gmail.com>
 */

#ifndef LED_LATTICE_H_
#define LED_LATTICE_H_

// @func LED点阵锁状态显示
// @param void
// @return void
void Lock4LedLattice(void);

// @func LED点阵解锁状态显示
// @param void
// @return void
void Unlock4LedLattice(void);

// @func LED点阵解锁动画
// @param void
// @return void
void LedLatticeUnlock(void);

// @func LED点阵锁动画
// @param void
// @return void
void LedLatticeLock(void);

// ???
void InputPasswdError(void);

void InputPasswdSuccess(void);

// ???
void SetSuccsse(void);

// ???
void ErrorWait(void);

#endif  // LED_LATTICE_H_
