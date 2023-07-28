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
  
  or_sr(0x18);		/* CPU off, GIE on */
}

static int blinkLimit = 5; // state variable representing reciprocal of duty cycle
static int blinkCount = 0; // state variable representing blink state
static int redBlinkCount = 0; // state variable representing blink state for LED_RED
static int secondCount = 0; // state variable representing repeating time 0...1s

void greenControl(int on)
{
  if (on) {
    P1OUT |= LED_GREEN;
  }
  else {
    P1OUT &= ~LED_GREEN;
  }
}

void redControl(int on)
{
  if (!on) {
    P1OUT |= LED_RED;
  }
  else {
    P1OUT &= ~LED_RED;
  }
}


// blink state machine
void blinkUpdate() // called every 1/250s to blink with duty cycle 1/blinkLimit
{
  blinkCount++;
  redBlinkCount++;
  
  if (blinkCount >= blinkLimit) {
    blinkCount = 0;
    greenControl(1);
    redControl(0);
  }
  else if (redBlinkCount >= blinkLimit) {
    redBlinkCount = 0;
    greenControl(0);
    redControl(1);
  }
  else {
    greenControl(0);
    redControl(0);
  }
}

void oncePerSecond() // repeatedly start bright and gradually lower duty cycle, one step/sec
{
  blinkLimit ++;  // reduce duty cycle
  if (blinkLimit >= 8)  // but don't let duty cycle go below 1/7.
    blinkLimit = 0;
}

void secondUpdate()  // called every 1/250 sec to call oncePerSecond once per second
{
  secondCount ++;
  if (secondCount >= 250) { // once each second
    secondCount = 0;
    oncePerSecond();
  } }

void timeAdvStateMachines() // called every 1/250 sec
{
  blinkUpdate();
  secondUpdate();
}


void __interrupt_vec(WDT_VECTOR) WDT()	/* 250 interrupts/sec */
{
  // handle blinking   
  timeAdvStateMachines();
} 

