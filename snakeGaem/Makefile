CPU = msp430g2553

CFLAGS = -mmcu=${} -Os -Iinc
LDFLAGS = -L../lib -lTimer -lLcd

CC = msp430-elf-gcc
AS = msp430-elf-gcc -mmcu=${CPU} -c
LD = msp430-elf-gcc

SRC_DIR = src
ASM_DIR = asm

SRCS = $(wildcard ${SRC_DIR}/*.c)
OBJS = ${SRCS:.c=.o} $(ASM_DIR)/custom.o

TARGET = snake_game.elf

all: $(TARGET)

$(TARGET): $(OBJS)
	${LD} ${LDFLAGS} -o $@ $^

${SRC_DIR}/%.o: ${SRC_DIR}/%.c
	${CC} ${CFLAGS} -c -o $@ $<

${ASM_DIR}/custom.o: ${ASM_DIR}/custom.s
	${AS} -o $@ $<

clean:
	rm -f ${SRC_DIR}/*.o
	rm -f ${ASM_DIR}/*.o
	rm -f ${TARGET}
