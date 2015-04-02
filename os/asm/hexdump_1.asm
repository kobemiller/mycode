;如何把二进制值转化成16进制字符串表达式

SECTION .bss
    BUFFLEN equ 16
    Buff: resb BUFFLEN

SECTION .data
    HexStr: db "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00", 10
    HEXLEN equ $-HexStr

    Digits: db "0123456789ABCDEF"

SECTION .text

global _start
_start: 
    nop

    Read:   mov eax, 3
            mov ebx, 0
            mov ecx, Buff
            mov edx, BUFFLEN
            int 80h
            mov ebp, eax        ;存储从文件中读入的字节数以备后用
            cmp eax, 0
            je Done
        
            mov esi, Buff       ;将文件缓冲区的地址存入esi
            mov edi, HexStr     ;将线性字符串的地址存入edi
            xor ecx, ecx        ;将线性字符串指针清零

    Scan:
            xor eax, eax

            mov edx, ecx        ;将字符计数器的值复制到edx
            shl edx, 1          ;通过左移操作数将指针的值乘以2
            add edx, ecx        ;完成乘以3操作

            mov al, byte [esi + ecx]    ;从输入缓冲区中取出一个字节，送入al
            mov ebx, eax

            and al, 0fh                         ;屏蔽除了低半字节之外的所有内容
            mov al, byte [Digits + eax]         ;查找与该半字节相等的字符
            mov byte [HexStr + edx + 2], al     ;将最低有效位（LSB）字符位元（digit）写入线性字符串

            shr bl, 4                           ;将字符的高四位移入低四位
            mov bl, byte [Digits + ebx]         ;查找与该半字节相等的字符
            mov byte [HexStr + edx + 1], bl     ;将最高有效位（MSB）的字符位元写入线性字符串

            inc ecx             ;增加线性字符串指针的值
            cmp ecx, ebp        ;与缓冲区中的字符串进行比较
            jna Scan

            mov eax, 4
            mov ebx, 1
            mov ecx, HexStr
            mov edx, HEXLEN
            int 80h
            jmp Read
    Done:
            mov eax, 1
            mov ebx, 0
            int 80h
