## Description
This interrupt-driven program uses Pulse Width Modulation (PWM) to
illuminate an LED dimmly. 

A common approach for controlling the apparent intensity of an LED is to
vary the fraction of time it receives power by pulsing it on and
off quickly.  The fraction of time a device is pulsed on is
frequently called its "duty cycle."

Human perception of brightness is (conveniently) logarithmic.  A
doubling or halving of duty cycle corresponds to a significant
difference in (perceptible) brightness. 

This program uses timer interrupts to illuminate an led through a
off-dim-bright sequence.  The "dim" setting illuminates the LED 25%
of the time.

## Exploration

_Changing brightness:_ Implement multiple
brightness settings, perhaps by adding a brighter (e.g. 1/2) and
dimmer (1/8) duty cycle periods to the sequence.  Hint: you may need
to change the range of the PWM counter to implement 1/8 brightness.

_Human factors_

Timing sensitivity: Characterize the limits of your ability to
discerning that a light is flashing rather than dim by varying the
flash frequency.  (hint: You can change the cycle time for the PWM
counter by changing its range.

Intensity sensitivity: Determine the limits of your ability to
discern differences in brightness.  For example, can you discern
3/4 or 5/8 from 1/2 duty cycle?   







