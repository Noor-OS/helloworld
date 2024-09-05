#!/bin/bash

# Assemble boot.asm into an object file
nasm -f elf32 src/boot.asm -o boot.o

# Compile the kernel.c into an object file
gcc -m32 -c src/kernel.c -o kernel.o -ffreestanding -nostdlib

# Link the object files to create the kernel binary
ld -m elf_i386 -T src/linker.ld -o noor.bin boot.o kernel.o

# Create a GRUB configuration file
mkdir -p iso/boot/grub
cat > iso/boot/grub/grub.cfg << EOF
menuentry "NoorOS Desk" {
    multiboot /boot/noor.bin
    boot
}
EOF

# Move the kernel binary into the ISO directory
mv noor.bin iso/boot/noor.bin

# Create the ISO file
grub-mkrescue -o nooros.iso iso # iso is dirname
