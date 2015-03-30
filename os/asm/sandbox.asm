section .data
;EatMsg: db "eat at Joe's", 10
;EatLen: equ $-EatMsg
Snippet db "KANGAROO"

section .text

global _start

_start:
  nop
  ;
  ;mov eax, 'WXYZ'
  ;mov ax, 067FEH
  ;mov bx, ax
  ;mov cl, bh
  ;mov ch, bl
  ;xchg cl, ch
  
  ;mov al, [EatMsg]
  ;mov ax, [EatMsg]
  ;mov [EatMsg], byte 'G'
  
  ;mov eax, 0FFFFFFFFH
  ;mov ebx, 02DH
  ;dec ebx
  ;inc eax
  
  ;mov eax, 5
  ;Domore: dec eax
  ;jnz Domore
  
 ; mov ebx, Snippet
  ;mov eax, 8
  
  ;Domore: add byte [ebx], 32
;	  inc ebx
;	  dec eax
;	  jnz Domore
  mov eax, 42
  neg eax
  add eax, 42
  mov ax, -42
  movsx ebx, ax
  ;...
  ;
  nop
  
section .bss
  