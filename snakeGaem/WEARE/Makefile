COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS         = -L/opt/ti/msp430_gcc/include -L../lib
CC              = msp430-elf-gcc
AS              = msp430-elf-as
AR              = msp430-elf-ar

all: main.elf libLcd.a

libLcd.a: font-11x16.o font-5x7.o font-8x12.o lcdutils.o lcddraw.o song_images.o
	$(AR) crs $@ $^

lcddraw.o: lcddraw.c lcddraw.h lcdutils.h
lcdutils.o: lcdutils.c lcdutils.h
song_images.o: song_images.c song_images.h lcddraw.c lcddraw.o lcdutils.c lcdutils.h

install: libLcd.a
	mkdir -p ../h ../lib
	mv $^ ../lib
	cp *.h ../h

main.elf: ${COMMON_OBJECTS} main.o led.o switches.o statemachines.o buzzer.o wdInterruptHandler.o p2_interrupt_handler.o libLcd.a ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: main.elf
	msp430loader.sh main.elf

clean:
	rm -f *.o *.elf *~
	rm -f libLcd.a *.o
