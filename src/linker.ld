OUTPUT_FORMAT(elf32-i386)
ENTRY(start)
SECTIONS
{
    . = 0x00100000;          /* Load address (1MB) */
    .text : { *(.text) }
    .data : { *(.data) }
    .bss : { *(.bss) }
}