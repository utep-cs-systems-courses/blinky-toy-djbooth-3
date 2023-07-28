#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)

#define SW1 BIT3		/* switch1 is p1.3 */
#define SWITCHES SW1		/* only 1 switch on this board */

#define SW1T BIT0         //P2.0
#define SW2T BIT1         //P2.1
#define SW3T BIT2         //P2.2
#define SW4T BIT3         //P2.3
#define P2_SWITCHES (SW1T | SW2T | SW3T | SW4T)


void main(void) 
{  
  configureClocks();
  
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;		/* leds initially off */
  
  P1REN |= SWITCHES;		/* enables resistors for switches */
  P1IE |= SWITCHES;		/* enable interrupts from switches */
  P1OUT |= SWITCHES;		/* pull-ups for switches */
  P1DIR &= ~SWITCHES;		/* set switches' bits for input */

  //P2 SWITCHES
  P2REN |= P2_SWITCHES;
  P2IE |= P2_SWITCHES;
  P2OUT |= P2_SWITCHES;
  P2DIR &= ~P2_SWITCHES;

  buzzer_init();

  or_sr(0x18);  // CPU off, GIE on
} 

int button_pressed;
int state = 0;

void state_cycle(int button_state)
{
  if (button_pressed)
    {
      switch (state)
	{
	case 0:
	  P1OUT |= LED_GREEN;
	  P1OUT &= ~LED_RED;
	  buzzer_set_period(3000);
	  state = 1;
	  break;
	case 1:
	  P1OUT |= LED_RED;
	  P1OUT &= ~LED_GREEN;
	  buzzer_set_period(8000);
	  state = 0;
	  break;
	default:
	  P1OUT &= ~LED_GREEN;
	  P1OUT &= ~LED_RED;
	  state = 0;
	}
    }
  else if(!button_pressed)
    {
      switch (state)
	{
	case 0:
	  P1OUT |= LED_GREEN;
	  P1OUT &= ~LED_RED;
	  state = 0;
	  buzzer_set_period(3000);
	  break;
	case 1:
	  P1OUT |= LED_RED;
	  P1OUT &= ~LED_GREEN;
	  buzzer_set_period(8000);
	  state = 1;
	  break;
	default:
	  P1OUT &= ~LED_GREEN;
	  P1OUT &= ~LED_RED;
	  state = 0;
	}
    }
}

void
switch_interrupt_handler()
{
  char p1val = P1IN;		/* switch is in P1 */

/* update switch interrupt sense to detect changes from current buttons */
  P1IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */

  button_pressed = p1val & SW1;
  state_cycle(button_pressed);
}

/* Switch on P1 (S2) */
void
__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHES) {	      /* did a button cause this interrupt? */
    P1IFG &= ~SWITCHES;		      /* clear pending sw interrupts */
    switch_interrupt_handler();	/* single handler for all switches */
  }
}

// Switches on P2 
void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & SW1T) {
    P2IFG &= ~P2_SWITCHES;
    P1OUT &= ~LEDS;
    buzzer_set_period(0);
    buzzer_set_period(8000);
  }
  if (P2IFG & SW2T) {
    P2IFG &= ~P2_SWITCHES;
    P1OUT &= ~LEDS;
    buzzer_set_period(0);
    buzzer_set_period(6000);
    P1OUT |= LED_RED;
  }
  if (P2IFG & SW3T) {
    P2IFG &= ~P2_SWITCHES;
    P1OUT &= ~LEDS;
    buzzer_set_period(0);
    buzzer_set_period(4000);
    P1OUT |= LED_GREEN;
  }
  if (P2IFG & SW4T) {
    P2IFG &= ~P2_SWITCHES;
    P1OUT &= ~LEDS;
    buzzer_set_period(0);
    buzzer_set_period(2000);
    P1OUT |= LEDS;
  }
}

