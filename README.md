# Lab 2: Blinky-Buzzy Toy

For your second project, your task is to use the MSP430
Microcontroller and your creativity to design a toy. Each MSP430 board
is equipped with buttons, LED's, a speaker, and 4 button switches
Utilizing these features and your knowledge of I/O, develop a
program to turn the board into a toy.

This toy should at minimum:

* generate sounds,
* dynamically change the LEDs that are illuminated, both brighly and dimmly,
* implement a state machine to maintain the state of the toy,
* and use the four buttons on the expansion board (P2.0-3) to transition the state machine.

**Furthermore, at least one of the functions to transition the state machine must be written by you in assembly language.**

## Getting Started 

Inside this repository you will find two directories:
1. The 'demos' directory contains sample programs for you to review and learn from. These example programs are a great starting point in understanding how to program the MSP430 microcontroller. See the readme in the demo directory on how to compile and run the demo programs.
2. The 'project' directory should contain the source code for your toy.

## What Should Be In Your Repo

Your project will be graded on the following items:
* Source code for your toy (only .c, .s and .h files).
* A README containing a description of your toy, how to compile it, how to run it, and how to use it.
* A Makefile with appropriate rules to build and clean your toy.
