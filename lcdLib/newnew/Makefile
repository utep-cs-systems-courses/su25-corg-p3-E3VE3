COMMON_OBJECTS = main.o tamagotchi.o display.o buzzer.o lcdutils.o lcddraw.o libTimer.o

CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -Os
LDFLAGS = -L/opt/ti/msp430_gcc/include

CC = msp430-elf-gcc
AS = msp430-elf-as

tamagotchi.elf: ${COMMON_OBJECTS}
	${CC} ${CFLAGS} -o $@ $^

load: tamagotchi.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *.hex
