    ; delay_cycles.S
    .cpu   msp430g2553
    .text
    .align 2
    .global delay_cycles
    .type  delay_cycles, @function

delay_cycles:
    push   R15           ; save caller-saved
    mov    R12, R15      ; copy count → R15
1:
    dec    R15           ; decrement
    jnz    1b            ; loop until zero
    pop    R15           ; restore
    ret                  ; back to C
