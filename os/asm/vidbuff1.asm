; 通过伪造全屏内存映射文本IO，演示字符串指令操作

SECTION .data
    EOL equ 10
    FILLCHR equ 32
    HBARCHR equ 196
    STRTROW equ 2

    Dataset db 9,71,17,52,55,18,29,36,18,68,77,63,58,44,0

    Message db "Data current as of 04/12/2015"
    MSGLEN equ $-Message

    Clrhome db 27, "[2J",27,"[01;01H"
    CLRLEN equ $-Clrhome
SECTION .bss
    COLS equ 81
    ROWS equ 25
    Vidbuff resb COLS * ROWS
SECTION .text

global _start
%macro Clearterminal 0
    pushad
    mov eax, 4
    mov ebx, 1
    mov ecx, Clrhome
    mov edx, CLRLEN
    int 80h
    popad
%endmacro

Show:
    pushad
    mov eax, 4
    mov ebx, 1
    mov ecx, Vidbuff
    mov edx, COLS * ROWS
    int 80h
    popad
    ret

Clrvid:
    push eax
    push ecx
    push edi
    cld
    mov al, FILLCHR
    mov edi, Vidbuff
    mov ecx, COLS * ROWS
    rep stosb
    mov edi, Vidbuff
    dec edi
    mov ecx, ROWS
Pteol:
    add edi, COLS
    mov byte [edi], EOL
    loop Pteol
    pop edi
    pop ecx
    pop eax
    ret

Wrtln:
    push eax
    push ebx
    push ecx
    push edi
    cld
    mov edi, Vidbuff
    dec eax
    dec ebx
    mov ah, COLS
    mul ah
    add edi, eax
    add edi, ebx
    rep movsb
    pop edi
    pop ecx
    pop ebx
    pop eax
    ret

Wrthb:
    push eax
    push ebx
    push ecx
    push edi
    cld
    mov edi, Vidbuff
    dec eax
    dec ebx

    mov ah, COLS
    mul ah
    add edi, eax
    add edi, ebx
    mov al, HBARCHR
    rep stosb
    pop edi
    pop ecx
    pop ebx
    pop eax
    ret

Ruler:
    push eax
    push ebx
    push ecx
    push edi
    mov edi, Vidbuff
    dec eax
    dec ebx
    mov ah, COLS
    mul ah
    add edi, eax
    add edi, ebx

    mov al, '1'
    Dochar: stosb
    add al, '1'
    aaa
    add al, '0'
    loop Dochar
    pop edi
    pop ecx
    pop ebx
    pop eax
    ret

_start:
    nop

    Clearterminal
    call Clrvid

    mov eax, 1
    mov ebx, 1
    mov ecx, COLS - 1
    call Ruler

    mov esi, Dataset
    mov ebx, 1
    mov ebp, 0

.blast:
    mov eax, ebp
    add eax, STRTROW
    mov cl, byte [esi + ebp]
    cmp ecx, 0
    je .rule2
    call Wrthb
    inc ebp
    jmp .blast
.rule2:
    mov eax, ebp
    add eax, STRTROW
    mov ebx, 1
    mov ecx, COLS - 1
    call Ruler

    mov esi, Message
    mov ecx, MSGLEN
    mov ebx, COLS
    sub ebx, ecx
    shr ebx, 1
    mov eax, 24
    call Wrtln

    call Show
Exit:
    mov eax, 1
    mov ebx, 0
    int 80h

