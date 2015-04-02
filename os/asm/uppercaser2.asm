SECTION .bss
    BUFFLEN equ 1024            ;缓冲区的长度
    Buff: resb BUFFLEN          ;缓冲区文本本身
SECTION .data

SECTION .text
    global _start

_start:
    nop

    ;从标准输入读入满满一缓冲区文本
    read:
        mov eax, 3              ;指定sys_read 调用
        mov ebx, 0
        mov ecx, Buff
        mov edx, BUFFLEN
        int 80h
        mov esi, eax
        cmp eax, 0
        je Done

    ;设置寄存器，用于处理缓冲区这个步骤
        mov ecx, esi
        mov ebp, Buff
        dec ebp

    ;详细检查缓冲区，并将小写字符转换成大写
    Scan:
        cmp byte [ebp + ecx], 61h
        jb Next
        cmp byte [ebp + ecx], 7ah
        ja Next

    ;此时，我们拥有了一个小写字符
        sub byte [ebp + ecx], 20h

    Next:
        dec ecx
        jnz Scan

    ;将满满一缓冲区处理过的文本写出到标准输出
    Write:
        mov eax, 4
        mov ebx, 1
        mov ecx, Buff
        mov edx, esi
        int 80h
        jmp read

    Done:
        mov eax, 1
        mov ebx, 0
        int 80h
