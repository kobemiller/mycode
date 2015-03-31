; 演示了linux INT 80H系统调用显示文本的用法
;
; nasm -f elf -g -F stabs eatsyscall.asm
; -f 告诉nasm对目标代码文件采用哪种格式
; -F 调试信息的格式为stabs，还有一种叫DWARF
; ld -o eatsyscall eatsyscall.o

SECTION .data 		; 包含已初始化的数据段

EatMsg: db "Eat at Joe's!", 10
EatLen: equ $-EatMsg

SECTION .bss 		; 包含未初始化的数据的段
SECTION .text 		; 包含代码的段

global _start 		; 连接器需要据此找到入口点

_start:
	nop 		; 这个无操作指令让gdb非常高兴
	mov eax, 4 	; 指定sys_write系统调用(通过将服务的编号放入寄存器EAX中来告诉调度程序需要哪个系统服务)
	mov ebx, 1 	; 指定文件描述符1：标准输出
	mov ecx, EatMsg ; 传递显示信息的偏移地址
	mov edx, EatLen ; 传递显示消息的长度
	int 80H 	; 进行系统调用来输出文本到标准输出
	mov eax, 1 	; 指定exit系统调用
	mov ebx, 0 	; 返回一个零代码
	int 80H 	; 进行系统调用来终止程序
