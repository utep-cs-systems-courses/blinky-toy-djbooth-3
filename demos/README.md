## Description
This directory contains demo programs that demonstrate basic I/O using timer and button interrupts.

Program | Description
------- | -----------
Blink   | Uses timer interrupts to flash the LEDs in a silly pattern.
Button  | Uses interrupts to detect when a switch is pressed or released.
Buzzer  | Emits a single continuous note from the buzzer.

## How to Use

The Makefile in this direcory contains rules to run the Makefile in each demo directory. Use **make** in this directory to build all demo programs and the timer library. Once the programs are built, you can load the program onto the MSP430 by changing into the corresponding demo directory and using **make load**.

You may use **mspdebug rf2500 "erase"** to clear a program from the MSP430.
