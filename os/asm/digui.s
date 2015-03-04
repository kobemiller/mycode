# 目的：阶乘
#
# 递归调用一个函数

.section .data

.section .text
.global _start
.global factorial

_start:
    pushl   $4
    call    factorial
    addl    $4, %esp    # 弹出入栈的参数
    movl    %eax, %ebx
    movl    $1, %eax
    int     $0x80
# 这里是实际的函数定义
# .type指令告诉链接器factorial是一个函数
.type factorial, @function
factorial:
    pushl   %ebp
    movl    %esp, %ebp
    movl    8(%ebp), %eax   # 4(%ebp)保存返回地址，8(%ebp)保存第一个参数
    cmpl    $1, %eax
    je      end_factorial
    decl    %eax
    pushl   %eax
    call    factorial
    movl    8(%ebp), %ebx
    imull   %ebx, %eax

end_factorial:
    movl    %ebp, %esp
    popl    %ebp
    ret
