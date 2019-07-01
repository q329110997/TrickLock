#include "universal/delay.h"
#include "led/test_led.h"

#include <reg52.h>
#include <intrins.h>

int main(void) {
	uint16 i = 0;
	char passwd1[] = {'0', '1', '2', '3'};
	uint16 m = 5678;
	while (1) {
		if (i % 2 == 0) {
		  test_input_passwd(passwd1);
			test_input_number(m);
		} else {
			LedLock();
			LedUnlock();
		}
		Delay1S(5);
		i++;
	}
  return 0;
}
