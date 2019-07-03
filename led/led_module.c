#include "led_module.h"

#include "../universal/macro.h"

void LedModuleUnlock(void) {
  LED_MODULE = KEY_UNLOCK;
}

void LedModuleLock(void) {
  LED_MODULE = KEY_LOCK;
}
