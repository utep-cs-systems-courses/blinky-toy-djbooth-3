## Description
This program uses interrupts to detect when a switch is pressed or
released.

Press S1, and the green LED is illuminated.  Release it, and the red
LED is illuminated instead.

## Exploration
_LED toggle:_  A great initial project would be to modify this program to
implement a state machine that "toggled" between the red and green LEDs
each time the button is pressed. The LED should remain illuminated until
the next time the button is pressed.

_Separation of duties:_ Input and output are not always so closely
connected.  Frequently an input begins a computation that eventually
results in an output. For example, pressing "next song" on a streaming
audio player begins a complicated multi-stage process that eventually
results in a different song being played.  Suggestion: start with
something simple such as responding to the buttons using interrupts to
set state variables, and update the LEDs when the timer interrupt
occurs.  

_Time and button interaction:_
Integrate the timer mechanisms from the blink demo and have the button affect the blink sequence.

## Some Advice
When creating your own variants to the demo programs,
it's probably a good idea to keep a copy of the original program (or really understand how _git checkout_ works).  
