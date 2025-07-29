/* msp430g2553.ld — link script for MSP430G2553 */
MEMORY
{
  FLASH (RX) : ORIGIN = 0xC000, LENGTH = 0x4000  /* 16 KB at top of 0x0000–0x3FFF */
  RAM   (RW) : ORIGIN = 0x0200, LENGTH = 0x0600  /* 1.5 KB at 0x0200–0x07FF */
}

SECTIONS
{
  /* Interrupt vector table */
  .vectors : {
    KEEP(*(.isr_vector))    /* keep the reset & ISR vectors */
  } > FLASH

  /* Code and read‑only data */
  .text : {
    *(.text*)               /* all .text sections */
    *(.rodata*)             /* all .rodata sections */
  } > FLASH

  /* Initialized data */
  .data : {
    *(.data*)
  } > RAM AT > FLASH

  /* Uninitialized data */
  .bss : {
    *(.bss*)
    *(COMMON)
  } > RAM
}
