## Description
This program uses interrupts to detect when a switch is pressed or
released.

Press S1, and the green LED is illuminated.  Release it, and the red
LED is illuminated instead.

This implementation separates different domains of control to different files:

* led.c controls the leds based on state vars
* switches.c responds to the switch and sets the values of state vars

Suggested activity:

Integrate time driven led blink logic whose behavior changes depending
on state vars representing the button state.  Be sure have separate files for
* controlling leds based upon led state vars
* reading buttons and updating button state vars
* responding to the progress of time (wd timer);  examining button
state, and updating led state (has own state var/s)


