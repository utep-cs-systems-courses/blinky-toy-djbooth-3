#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

int main() {
    configureClocks();
    enableWDTInterrupts();
 
    buzzer_init();
    buzzer_set_period(1000);    /* start buzzing!!! 2MHz/1000 = 2kHz*/


    or_sr(0x18);          // CPU off, GIE on
}

static int secondCount = 0;
static int i = 1;
static int cycles = 8000;

void
__interrupt_vec(WDT_VECTOR) WDT() {

  secondCount++;

  if (secondCount == (i*10))
    {
      i++;
      buzzer_set_period(cycles);
      cycles -= 30;
    }
  else if (cycles == 2000)
    {
      secondCount = 0;
      cycles = 8000;
      i = 1;
    }
}
