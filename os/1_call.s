func:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	%edx, 8(%ebp)
	popl	%ebp
	ret
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$20, %esp
	movl	$3, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	func
	movl	$0, %eax
	leave
	ret
