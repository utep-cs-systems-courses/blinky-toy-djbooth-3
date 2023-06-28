# makfile configuration
COMMON_OBJECTS  = main.o 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: led-c.elf led-s.elf 

#additional rules for files
led-c.elf: ${COMMON_OBJECTS} greenControl-c.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a
led-s.elf: ${COMMON_OBJECTS} greenControl-s.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load-c: led-c.elf
	msp430loader.sh $^

load-s: led-s.elf 
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

main.o: led.h
greenControl-c.o: led.h
wdInterruptHandler.o:  led.h

green-on-c.o: led.h greenControl_c.c
