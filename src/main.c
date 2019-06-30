#include "universal/delay.h"
#include "led/led.h"

int main(void) {
	while (1) {
		uint16 n = 5000;
	  while (n--) {
		  Lock4Led();
		}
		n = 5000;
		while (n--) {
		  Unlock4Led();
		}
	}
  return 0;
}
