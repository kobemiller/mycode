all: sandbox vidbuff

sandbox: sandbox.o
	ld -o sandbox sandbox.o
vidbuff: vidbuff.o
	ld -o vidbuff vidbuff.o
sandbox.o: sandbox.asm
	nasm -f elf -g -F stabs sandbox.asm -l sandbox.lst
vidbuff.o: vidbuff.asm
	nasm -f elf -g -F stabs vidbuff.asm -l vidbuff.lst
