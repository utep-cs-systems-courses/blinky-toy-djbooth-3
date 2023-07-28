## Description
This program uses interrupts to detect when a switch is pressed or
released.

Press S1, and the green LED is illuminated.  Release it, and the red
LED is illuminated instead.

## Suggested Activities
_LED toggle:_  A great initial project would be to modify this program to
implement a state machine that "toggled" between the red and green LEDs
each time the button is pressed. The LED should remain illuminated until
the next time the button is pressed.

_Time and button interaction:_
Integrate the timer mechanisms from the blink demo and have the button
changes a state variable that modifies the blink sequence.


## Some Advice
When creating your own variants to the demo programs,
it's probably a good idea to keep a copy of the original program (or really understand how _git checkout_ works).  

