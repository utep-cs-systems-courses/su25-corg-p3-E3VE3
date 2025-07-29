# Target MCU
CPU       := msp430g2553

# Compiler flags: MCU, optimize, include headers
CFLAGS    := -mmcu=$(CPU) -Os -Iinc -I../h

# Linker flags: library paths and libs
LDFLAGS   := -L../lib -L/opt/ti/msp430_gcc/include/ -lTimer -lLcd

# Toolchain
CC        := msp430-elf-gcc
AS        := msp430-elf-gcc
ASMFLAGS  := -mmcu=$(CPU) -c

# Where our code lives
SRC_DIR   := src
ASM_DIR   := asm

# 1) Gather every C source -> object
CSRCS     := $(wildcard $(SRC_DIR)/*.c)
COBJS     := $(CSRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)

# 2) Add your one assembly object
AOBJS     := $(ASM_DIR)/custom.o

# 3) All objects to link
OBJS      := $(COBJS) $(AOBJS)

# Final output
TARGET    := snake_game.elf

.PHONY: all clean

all: $(TARGET)

# Link step: now includes main.o, game_logic.o, display.o, etc., plus custom.o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Compile C modules
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble the optimized row‑concatenate routine
$(ASM_DIR)/custom.o: $(ASM_DIR)/custom.s
	$(AS) $(ASMFLAGS) $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(ASM_DIR)/*.o $(TARGET)
