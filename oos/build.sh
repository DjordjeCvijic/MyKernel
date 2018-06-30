export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

nasm -f elf32 -o start.o start.asm


i686-elf-gcc -I./include -c main.c -o main.o  -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -I./include -c scrn.c -o scrn.o  -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -I./include -c gdt.c -o gdt.o  -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -I./include -c idt.c -o idt.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -I./include -c isrs.c -o isrs.o  -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -I./include -c irq.c -o irq.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -I./include -c timer.c -o timer.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -I./include -c kb.c -o kb.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
i686-elf-gcc -I./include -c beep.c -o beep.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

i686-elf-gcc -T link.ld -o kernel.bin -ffreestanding -O2 -nostdlib start.o main.o scrn.o gdt.o isrs.o idt.o irq.o timer.o kb.o beep.o -lgcc


