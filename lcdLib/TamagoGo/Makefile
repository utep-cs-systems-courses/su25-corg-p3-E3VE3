COMMON_OBJECTS = main.o lcdutils.o lcddraw.o state_transition.o libTimer.o

CPU = msp430g2553
CFLAGS = -mmcu=${CPU} -Os
LDFLAGS = -L/opt/ti/msp430_gcc/include

# Use internal toolchain compiler
CC = msp430-elf-gcc
AS = msp430-elf-as

# Target binary
tamagotchi.elf: $(COMMON_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Load to board
load: tamagotchi.elf
	msp430loader.sh $^

# Clean build artifacts
clean:
	rm -f *.o *.elf *.hex

# Assembly file rule
state_transition.o: state_transition.s43
	$(AS) -mmcu=${CPU} -o $@ $<
