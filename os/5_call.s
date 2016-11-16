func:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	popl	%ebp
	ret
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$3, -12(%ebp)
	movl	$4, -8(%ebp)
	movl	$8, -4(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	func
	movl	$0, %eax
	leave
	ret
