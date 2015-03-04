#目的：本程序寻找一组数据项中的最大值
#
#变量：寄存器有以下用途
#
# %edi - 保存正在检测的数据项索引
# %ebx - 当前已经找到的最大数据项
# %eax - 当前数据项

#使用一下内存位置：
#
# data_items - 包含数据项 0表示数据结束

.section .data

data_items:     #这些是数据项
    .long 3, 67, 34, 222, 45, 75, 54, 34, 44, 33, 22, 11, 66, 0

.section .text

.global _start
_start:
    movl $0, %edi
    movl data_items(, %edi, 4), %eax    #加载数据的第一个字节
    movl %eax, %ebx

start_loop:         #开始循环
    cmpl $0, %eax   #检测是否到达数据尾
    je loop_exit
    incl %edi       #加载下一个值
    movl data_items(, %edi, 4), %eax
    cmpl %ebx, %eax
    jle start_loop  #若新数据项不大于原最大值，则跳到循环起始处
    movl %eax, %ebx #将新值移入最大值寄存器
    jmp start_loop

loop_exit:
    movl $1, %eax
    int $0x80

