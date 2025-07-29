CC = msp430-gcc
AS = msp430-gcc
LD = msp430-gcc

CFLAGS = -mmcu=msp430g2553 -std=c99 -Wall -Werror -Os -Iinc
ASFLAGS = -mmcu=msp430g2553
LDFLAGS = -mmcu=msp430g2553

SRC_DIR = src
INC_DIR = inc
ASM_DIR = asm

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:.c=.o) $(ASM_DIR)/custom.o

TARGET = snake_game.elf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ASM_DIR)/custom.o: $(ASM_DIR)/custom.s43
	$(AS) $(ASFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(ASM_DIR)/*.o
	rm -f $(TARGET)
