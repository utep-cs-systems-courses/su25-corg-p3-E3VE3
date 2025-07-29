CPU       := msp430g2553
CFLAGS    := -mmcu=$(CPU) -Os -Iinc -I../h
LDFLAGS   := -L../lib -L/opt/ti/msp430_gcc/include/ -lTimer -lLcd

CC        := msp430-elf-gcc
AS        := msp430-elf-gcc
ASMFLAGS  := -mmcu=$(CPU) -c

SRC_DIR   := src
ASM_DIR   := asm

# ← Here’s the tweak ↓
CSRCS     := $(wildcard $(SRC_DIR)/*.c)
COBJS     := $(CSRCS:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)
AOBJS     := $(ASM_DIR)/custom.o
OBJS      := $(COBJS) $(AOBJS)

TARGET    := snake_game.elf

all: $(TARGET)

# Link everything—now includes main.o, game_logic.o, display.o, etc.
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

# Compile each C source
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble your custom row‑packer
$(ASM_DIR)/custom.o: $(ASM_DIR)/custom.s
	$(AS) $(ASMFLAGS) $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o $(ASM_DIR)/*.o $(TARGET)
