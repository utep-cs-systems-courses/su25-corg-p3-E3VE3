    .global updateSmiley
    .extern smileyX, smileyY, dx, dy

updateSmiley:
    mov.w smileyX, r12
    add.w dx, r12
    mov.w r12, smileyX

    mov.w smileyY, r13
    add.w dy, r13
    mov.w r13, smileyY
    ret
