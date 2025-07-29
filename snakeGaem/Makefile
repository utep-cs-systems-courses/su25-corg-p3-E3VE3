CPU       := msp430g2553
MCUFLAG   := -mmcu=$(CPU)
OPT       := -Os
INC       := -Iinc

CC        := msp430-elf-gcc

# All C sources in the project root
CSRCS     := $(wildcard *.c)
# Convert them to .o
COBJS     := $(CSRCS:.c=.o)

# One assembly source in asm/
AOBJS     := asm/custom.o

# Everything to link
OBJS      := $(COBJS) $(AOBJS)

TARGET    := snake_game.elf

.PHONY: all clean

all: $(TARGET)

# Link step: includes main.o, game_logic.o, display.o, etc., plus custom.o
$(TARGET): $(OBJS)
	$(CC) $(MCUFLAG) $(OPT) $(INC) -o $@ $^

# Compile any .c in the root
%.o: %.c
	$(CC) $(MCUFLAG) $(OPT) $(INC) -c $< -o $@

# Assemble your custom row‑concatenation routine
asm/custom.o: asm/custom.s
	$(CC) $(MCUFLAG) $(OPT) -c $< -o $@

clean:
	rm -f *.o asm/*.o $(TARGET)
