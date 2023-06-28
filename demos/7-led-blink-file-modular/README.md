## Description
This interrupt-driven program flashes the LEDs in a silly pattern.

## Exploration

_Write some some code in Assembly Language_

Translate led.c to led_s.s, and modify the Makefile to reference it.  Remember

* to put global and static vars in the data segment and instructions in the
text segment using the .data and .text directives,
* to make global symbols visible to other modules using .global, and
* to import external symbols from other modules with .extern

_Changing speed:_ Figure out how to flash the lights faster or slower.  Determine if there's a speed where the lights don't appear to flash... but glow instead!

_Counting to three:_  Change the program to slowly and repeatedly
count from zero to three, displaying the value in binary using the red
& green lights. This is simpler than the program we provided.

## Some Advice
When creating your own variants to the demo programs,
it's probably a good idea to keep a copy of the original program (or really understand how _git checkout_ works).  








