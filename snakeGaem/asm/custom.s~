            .cdecls C, LIST, "msp430.h"
            .text
            .global _fast_concatenate
            .align 2

_fast_concatenate:
            MOV     #0, R13         ; result = 0
            MOV     R12, R14        ; copy pointer to R14
            MOV     #8, R15         ; loop counter

next_bit:
            RLA     R13             ; shift result left
            MOV     @R14+, R12      ; load next row element
            CMP     #0, R12
            JZ      skip_set
            INC     R13             ; set bit if non-zero

skip_set:
            DEC     R15
            JNZ     next_bit

            RET
