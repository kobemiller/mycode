; mov所不能做的事情就是将数据直接从一个内存地址移到另一个内存地址
; 中间需要经过寄存器
  mov EAX, 42h 		;源操作数是立即数（只有源操作数可以是立即数）
			;立即数是内置在机器指令本身内部的数据
  mov EBX, EDI 		;两个都是32位寄存器数据
  mov BX,  CX 		;两个都是16位寄存器数据
  mov DL,  BH 		;两个都是8位寄存器数据
  mov [EBP], EDI 	;目标操作数是32位内存数据，该内存的地址存放在ebp中
  mov EDX, [ESI] 	;源操作数是32位内存数据，该内存的地址存放在ESI中
; 汇编语言中，变量名代表的是地址，而不是数据。
; 加[]，表示的才是数据
  mov ax, -42
  movsx ebx, ax 	；movsx--》带符号扩展一起移动
; mul&div==》处理无符号计算
; imul&idiv==》处理有符号计算
; mul操作数不能是立即数
      显式操作数 	隐式操作数（因子2） 	隐式操作数（结果）
  mul r/m8 	al 			ax
  mul r/m16 	ax 			dx and ax
  mul r/m32 	eax 			edx and eax
      显式操作数 	隐式操作数（商的整数部分） 	隐式操作数（商的余数部分）
  div r/m8 	al 			ah
  div r/m16 	ax 			dx
  div r/m32 	eax 			edx
; r8==>al ah bl bh cl ch dl dh
; r16=>ax bx cx dx bp sp si di
; sr==>cs ds ss es fs gs
; r32=>eax ebx ecx edx ebp esp esi edi
; m8==>8位内存数据
; m16=>16位内存数据
; m32=>32位内存数据
; i8==>8位立即数
; i16=>16立即数
; i32=>32立即数
; d8==>8位有符号位移
; d16=>16位有符号位移
; d32=>32位有符号位移
; .data段包含了已初始化的数据，这些数据是可执行文件的一部分，所以定义的初始化数据项越多，
; 可执行文件就会越大，运行的时候，也就需要更长时间才能从磁盘加载到内存
; .bss段中定义的数据项则不会添加到可执行文件中
; .text段中不进行数据项的定义
; _start必须在.text段的顶部标记为全局的
  Twolinemsg: db "eat at Joe's...", 10, "...Ten million files can't all be wrong", 10
; 10在linux中代表行结束（EOL）字符

; push 		;将一个在源代码中指定的16位或者32位寄存器值或者内存值压入堆栈
; pushf 	;将16位标志寄存器的值压入堆栈
; pushfd 	;将Eflags寄存器的全部32位值压入堆栈
; pusha 	;将所有8个16位寄存器压入堆栈
; pushad 	;将所有8个32位通用寄存器压入堆栈

; pop的工作方式和push类似，都只能操作16位或32位操作数