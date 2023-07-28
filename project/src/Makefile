# makfile configuration
COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: p2.elf 

#additional rules for files
p2.elf: ${COMMON_OBJECTS} buzzer.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: p2.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.c~ *.h~ *~ *.c# *.elf

main.o: buzzer.h led.h

buzzer.o: buzzer.h
