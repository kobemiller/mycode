; 十六进制转储实用工具

SECTION .bss
    BUFFLEN equ 10
    Buff resb BUFFLEN

SECTION .data
    Dumplin: db "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00", 10
    DUMPLEN equ $-Dumplin
    ASClin: db "|................|", 10
    ASCLEN equ $-ASClin
    FULLLEN equ $-Dumplin

; hexdigits表用来把数字值转换位它们的十六进制等值
Hexdigits: db "0123456789ABCDEF"

Dotxlat:
    db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
	db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
	db 20h,21h,22h,23h,24h,25h,26h,27h,28h,29h,2Ah,2Bh,2Ch,2Dh,2Eh,2Fh
	db 30h,31h,32h,33h,34h,35h,36h,37h,38h,39h,3Ah,3Bh,3Ch,3Dh,3Eh,3Fh
	db 40h,41h,42h,43h,44h,45h,46h,47h,48h,49h,4Ah,4Bh,4Ch,4Dh,4Eh,4Fh
	db 50h,51h,52h,53h,54h,55h,56h,57h,58h,59h,5Ah,5Bh,5Ch,5Dh,5Eh,5Fh
	db 60h,61h,62h,63h,64h,65h,66h,67h,68h,69h,6Ah,6Bh,6Ch,6Dh,6Eh,6Fh
	db 70h,71h,72h,73h,74h,75h,76h,77h,78h,79h,7Ah,7Bh,7Ch,7Dh,7Eh,2Eh
	db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
	db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
	db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
	db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
	db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
	db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
	db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh
	db 2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh,2Eh

SECTION .text
; clearline 将一个十六进制转储行字符串清零，即将其变为16个0
Clearline:
    pushad                      ; 保存主调程序的所有通用寄存器
    mov edx, 15
.poke:
    mov eax, 0
    call Dumpchar
    sub edx, 1
    jae .poke
    popad
    ret

; Dumpchar 插入一个值到十六进制转储字符串中
Dumpchar:
    push ebx
    push edi

    mov bl, byte [Dotxlat + eax]
    mov byte [ASClin + edx + 1], bl

    mov ebx, eax
    lea edi, [edx * 2 + edx]

    and eax, 0000000Fh
    mov al, byte [Hexdigits + eax]
    mov byte [Dumplin + edi + 2], al

    and ebx, 000000F0h
    shr ebx, 4
    mov bl, byte [Hexdigits + ebx]
    mov byte [Dumplin + edi + 1], bl

    pop edi
    pop ebx
    ret

; printline 将dumpline显示到标准输出
Printline:
    pushad
    mov eax, 4
    mov ebx, 1
    mov ecx, Dumplin
    mov edx, FULLLEN
    int 80h
    popad
    ret

;loadbuff 通过INT 80h sys_read 将一个缓冲区从标准输入装满数据
Loadbuff:
    push eax
    push ebx
    push edx
    mov eax, 3
    mov ebx, 0
    mov ecx, Buff
    mov edx, BUFFLEN
    int 80h
    mov ebp, eax        ;保存从文件中读入的字节数
    xor ecx, ecx
    pop edx
    pop ebx
    pop eax
    ret

Newlines:
    pushad
    cmp edx, 15
    ja .exit
    mov ecx, EOLs
    mov eax, 4
    mov ebx, 1
    int 80h
.exit:
    popad 
    ret

EOLs db 10,10

global _start
_start:
    nop
    nop

    xor esi, esi        ;将整个字节计数器清零
    call Loadbuff
    cmp ebp, 0
    jbe Exit

Scan:
    xor eax, eax
    mov al, byte [Buff + ecx]
    mov edx, esi
    and edx, 0000000Fh
    call Dumpchar

    inc esi
    inc ecx
    cmp ecx, ebp
    jb .modtest
    call Loadbuff
    cmp ebp, 0
    jbe Done

.modtest:
    test esi, 0000000Fh
    jnz Scan
    call Printline
    call Clearline
    jmp Scan

Done:
    call Printline
    call Newlines

Exit:
    mov eax, 1
    mov ebx, 0
    int 80h

