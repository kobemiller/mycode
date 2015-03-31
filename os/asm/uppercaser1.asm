section .bss
  Buff resb 1
  
section .data

section .text
  global _start
  
_start: 
  nop
  
  Read: 	mov eax, 3 		; 指定sys_read调用
		mov ebx, 0 		; 指定文件描述符0：标准输入
		mov ecx, Buff		; 传递即将从中读取数据的缓冲区的地址
		mov edx, 1 		; 告诉sys_read从标准输入读入一个字符
		int 80h			; 调用sys_read
		cmp eax, 0		; 观察sys_read在EAX寄存器的返回值
		je Exit			; 如果为零，意思是EOF，则跳转到Exit
					; 如果不为零，则测试它是否为一个小写字母
		cmp byte [Buff], 61h	; 将输入字符与小写字母'a'相比较
		jb Write		; 如果在ASCII中比a小，则不是小写字符
		cmp byte [Buff], 7Ah	; 测试输入字符与小写字符’z‘比较
		ja Write		; 如果再ASCII中比’z‘大，则不是小写字符
					; 此时我们已经拥有一个小写字符
		sub byte [Buff], 20h 	; 从小写字符中减去20h，得出相应的大写字符
	
  Write:	mov eax, 4		; 指定sys_write调用
		mov ebx, 1 		; 指定文件描述符1：标准输出
		mov ecx, Buff 		; 传递要写出的字符地址
		mov edx, 1 		; 传递要写出的字符数量
		int 80h 		; 调用sys_write
		jmp Read 		; 跳转到开始处，获取另外一个字符
		
 Exit: 		mov eax, 1		; 退出系统调用代码
		mov ebx, 0 		; 将零作为返回值返回linux
		int 80h 		; 进行内核调用以退出程序
	  