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
  mul r/m8 	al 		ax
  mul r/m16 	ax 		dx and ax
  mul r/m32 	eax 		edx and eax