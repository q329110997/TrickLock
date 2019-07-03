/*
 * led_module.h
 * LED 模块显示
 */
 
#ifndef LED_MODULE_H_
#define LED_MODULE_H_

// @func LED模块显示锁状态, 0x04为加锁状态
// @param void
// @return void
void LedModuleUnlock(void);

// @func LED模块显示解锁状态, 0x40为解锁状态
// @param void
// @return void
void LedModuleLock(void);

#endif  // LED_MODULE_H_