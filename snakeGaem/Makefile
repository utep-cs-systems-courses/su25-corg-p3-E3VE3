# ─── Makefile for MSP430 Snake Game ────────────────────────────

CPU       = msp430g2553

# Compiler flags: MCU, optimize, include your headers
CFLAGS    = -mmcu=$(CPU) -Os -Iinc -I../h

# Linker flags: point at your libs, plus TI’s include path
LDFLAGS   = -L../lib -L/opt/ti/msp430_gcc/include/ -lTimer -lLcd

# Tools
CC        = msp430-elf-gcc
AS        = msp430-elf-gcc -mmcu=$(CPU) -c

SRC_DIR   = src
ASM_DIR   = asm

SRCS      = $(wildcard $(SRC_DIR)/*.c)
OBJS      = $(SRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o) \
            $(ASM_DIR)/custom.o

TARGET    = snake_game.elf

all: $(TARGET)

# Link everything into the final .elf
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Compile C modules
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble the optimized row-concat routine
$(ASM_DIR)/custom.o: $(ASM_DIR)/custom.s
	$(AS) -o $@ $<

clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(ASM_DIR)/*.o
	rm -f $(TARGET)

# ───────────────────────────────────────────────────────────────
