mkdir -p isodir/boot/grub
cp MyKernel.bin isodir/boot/MyKernel.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o MyKernel.iso isodir
