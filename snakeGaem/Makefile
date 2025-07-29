CPU       := msp430g2553
MCUFLAG   := -mmcu=$(CPU)
OPT       := -Os
INC       := -Iinc

CC        := msp430-elf-gcc

# gather all .c → .o
CSRCS     := $(wildcard *.c)
COBJS     := $(CSRCS:.c=.o)

# one assembly routine
AOBJS     := asm/custom.o

OBJS      := $(COBJS) $(AOBJS)
TARGET    := snake_game.elf

LDFLAGS   := -Wl,-T,msp430g2553.ld

.PHONY: all clean

all: $(TARGET)

# link everything (no -mmcu here, it's only needed at compile time)
$(TARGET): $(OBJS)
	$(CC) $(MCUFLAG) $(OPT) $(INC) $(LDFLAGS) -o $@ $^

# compile C files
%.o: %.c
	$(CC) $(MCUFLAG) $(OPT) $(INC) -c $< -o $@

# assemble the fast routine
asm/custom.o: asm/custom.s
	$(CC) $(MCUFLAG) $(OPT) -c $< -o $@

clean:
	rm -f *.o asm/*.o $(TARGET)
