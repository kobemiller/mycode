	func:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %ecx
	movl	8(%ebp), %edx
	movl	%ecx, (%edx)
	popl	%ebp
	ret
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$20, %esp
	movl	$3, -8(%ebp)
	movl	$4, -4(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	func
	movl	$0, %eax
