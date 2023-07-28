//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "libTimer.h"
#include "led.h"

int main(void) {
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;

  configureClocks();		/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();	/* enable periodic interrupt */
  
  or_sr(0x18);			/* CPU off, GIE on */
}

// global state vars that control blinking
int blinkLimit = 5;  // duty cycle = 1/blinkLimit
int blinkCount = 0;  // cycles 0...blinkLimit-1
int secondCount = 0; // state var representing repeating time 0…1s

int state = 0;
char green;
char red;

void state_cycle()
{
  switch (state)
    {
    case 0:
      green = 0xFF;
      red = 0x00;
      state = 1;
      break;
    case 1:
      green = 0x00;
      red = 0xFF;
      state = 2;
      break;
    case 2:
      green = 0xFF;
      red = 0xFF;
      state = 0;
      break;
    default:
      green = 0x00;
      red = 0x00;
      state = 0;
      break;
    }
}

void
__interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  // handle blinking 
  blinkCount ++;
  if (blinkCount >= blinkLimit) { // on for 1 interrupt period
    blinkCount = 0;
    P1OUT &= ~LEDS;
  }
  else		          // off for blinkLimit - 1 interrupt periods
    {
      P1OUT |= (green & LED_GREEN);
      P1OUT |= (red & LED_RED);
    }

  // measure a second
  secondCount ++;
  if (secondCount >= 250) {  // once each second
    secondCount = 0;
    blinkLimit ++;	     // reduce duty cycle
    if (blinkLimit >= 8) { // but don't let duty cycle go below 1/7.
      blinkLimit = 0;
      state_cycle();
    }
  }
}

