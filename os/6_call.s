func1:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	addl	%edx, %eax
	popl	%ebp
	ret
func2:
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
	subl	$24, %esp
	movl	$3, -12(%ebp)
	movl	$4, -8(%ebp)
	movl	$8, -4(%ebp)
	leal	-8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, (%esp)
	call	func1
	movl	-4(%ebp), %eax
	movl	%eax, (%esp)
	call	func2
	movl	$0, %eax
	leave
	ret
