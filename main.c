#include "universal/delay.h"
#include "universal/type.h"
#include "led/led_lattice.h"
#include "led/test_led.h"

#include <reg52.h>
#include <intrins.h>

int main(void) {
	uint16 i = 0;
	char passwd1[] = {'0', '1', '2', '3'};
	char passwd2[] = {'4', '5', '6', '7'};
	uint16 m = 5678;
	uint8 n = 90;
	while (1) {
		if (i % 3 == 0) {
		  test_input_passwd(passwd1);
			test_input_number(m);
		} else if (i % 3 == 1) {
		  test_input_passwd(passwd2);
			test_input_number(n);
		} else {
      LedLock();
      LedUnlock();
    }
		Delay1S(5);
		i++;
	}
  return 0;
}
