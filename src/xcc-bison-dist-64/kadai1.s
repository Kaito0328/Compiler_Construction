	.globl  i
	 .data
	.p2align  3
i:
	.skip   8

	.globl  sum
	 .data
	.p2align  3
sum:
	.skip   8

	.text
L.XCC.STR1:
	.ascii  "sum = %ld\n\0"
L.XCC.STR0:
	.ascii  "i = %ld\n\0"
	.text
	.globl  main
	.p2align 4, 0x90
main:
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $0, %rsp
	movq    $0x5, %rax
	pushq   %rax
	leaq    i(%rip),   %rax
	pushq    %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
	movq    $0x0, %rax
	pushq   %rax
	leaq    sum(%rip),   %rax
	pushq    %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
LBB0_1:
	movq    $0x0, %rax
	pushq   %rax
	pushq   i(%rip)
	popq    %rax
	popq    %r10
	cmpq    %rax,   %r10
	setl    %al
	movzbq    %al,   %rax
	pushq    %rax
	popq    %rax
	cmpq    $0,   %rax
	je    LBB03
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	pushq   i(%rip)
	leaq    L.XCC.STR0(%rip), %rax 	# "i = %ld\n"
	pushq   %rax
	movq    printf@GOTPCREL(%rip), %rax
	pushq   %rax
	popq    %r11
	popq    %rdi
	popq    %rsi
	movb    $0, %al
	call    *%r11
# restore caller-saved registers
	popq   %r11
	popq   %r10
	popq   %r9
	popq   %r8
	popq   %rsi
	popq   %rdi
	popq   %rdx
	popq   %rcx
	pushq   %rax
	addq    $8, %rsp
	pushq   sum(%rip)
	pushq   i(%rip)
	popq    %r10
	popq    %rax
	addq    %r10,   %rax
	pushq    %rax
	leaq    sum(%rip),   %rax
	pushq    %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
	pushq   i(%rip)
	movq    $0x1, %rax
	pushq   %rax
	popq    %r10
	popq    %rax
	subq    %r10,   %rax
	pushq    %rax
	leaq    i(%rip),   %rax
	pushq    %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
	jmp    LBB0_1
LBB03:# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	pushq   sum(%rip)
	leaq    L.XCC.STR1(%rip), %rax 	# "sum = %ld\n"
	pushq   %rax
	movq    printf@GOTPCREL(%rip), %rax
	pushq   %rax
	popq    %r11
	popq    %rdi
	popq    %rsi
	movb    $0, %al
	call    *%r11
# restore caller-saved registers
	popq   %r11
	popq   %r10
	popq   %r9
	popq   %r8
	popq   %rsi
	popq   %rdi
	popq   %rdx
	popq   %rcx
	pushq   %rax
	addq    $8, %rsp
L.XCC.RE.main:
	movq    %rbp, %rsp
	popq    %rbp
	retq
