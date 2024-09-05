bits 32
section .text
    align 4
    dd 0x1BADB002            ; Multiboot magic number
    dd 0x00                  ; Flags
    dd -(0x1BADB002 + 0x00)  ; Checksum

global start
extern kernel_main
start:
    cli                      ; Clear interrupts
    call kernel_main         ; Call the kernel main function
    hlt                      ; Halt the CPU