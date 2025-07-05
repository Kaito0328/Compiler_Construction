	.text
	.globl  mrn
	.p2align 4, 0x90
mrn:
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $0, %rsp
	pushq   %rdi
	movq    $0x0, %rax
	pushq   %rax
	popq    %rax
	popq    %r10
	cmpq    %rax,   %r10
	setl    %al
	movzbq    %al,   %rax
	pushq    %rax
	popq    %rax
	testq   %rax, %rax
	jnz    .L_TRUE_0
	pushq   %rdi
	movq    $0x0, %rax
	pushq   %rax
	popq    %rax
	popq    %r10
	cmpq    %rax,   %r10
	sete    %al
	movzbq    %al,   %rax
	pushq    %rax
	popq    %rax
	testq   %rax, %rax
	jnz    .L_TRUE_0
.L_FALSE_0:
	movq $0x0,    %rax
	pushq    %rax
	jmp    .L_END_AND0
.L_TRUE_0:
	movq $0x1,    %rax
	pushq    %rax
	jmp    .L_END_AND0
.L_END_AND0:
	popq    %rax
	cmpq    $0,   %rax
	je    LBB0_1
	movq    $0x0, %rax
	pushq   %rax
	popq    %rax
	jmp    L.XCC.RE.mrn
	jmp    LBB0_2
LBB0_1:
	movq    $0xa, %rax
	pushq   %rax
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	pushq   %rdi
	movq    $0x1, %rax
	pushq   %rax
	popq    %r10
	popq    %rax
	subq    %r10,   %rax
	pushq    %rax
	leaq    mrn(%rip), %rax
	pushq   %rax
	popq    %r11
	popq    %rdi
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
	popq    %r10
	popq    %rax
	mulq    %r10
	pushq    %rax
	pushq   %rdi
	popq    %r10
	popq    %rax
	addq    %r10,   %rax
	pushq    %rax
	popq    %rax
	jmp    L.XCC.RE.mrn
LBB0_2:
L.XCC.RE.mrn:
	movq    %rbp, %rsp
	popq    %rbp
	retq
	.text
L.XCC.STR0:
	.ascii  "mrn(%ld) = %ld\n\0"
	.text
	.globl  main
	.p2align 4, 0x90
main:
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $16, %rsp
	movq    $0x0, %rax
	pushq   %rax
	movq    -8(%rbp),   %rax 	# i, 0
	leaq -8(%rbp),    %rax
	pushq %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
LBB0_3:
	movq    -8(%rbp), %rax 	# i, 0
	pushq   %rax
	movq    $0xb, %rax
	pushq   %rax
	popq    %rax
	popq    %r10
	cmpq    %rax,   %r10
	setl    %al
	movzbq    %al,   %rax
	pushq    %rax
	popq    %rax
	cmpq    $0,   %rax
	je    LBB0_4
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	movq    -8(%rbp), %rax 	# i, 0
	pushq   %rax
	leaq    mrn(%rip), %rax
	pushq   %rax
	popq    %r11
	popq    %rdi
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
	movq    -8(%rbp), %rax 	# i, 0
	pushq   %rax
	leaq    L.XCC.STR0(%rip), %rax 	# "mrn(%ld) = %ld\n"
	pushq   %rax
	movq    printf@GOTPCREL(%rip), %rax
	pushq   %rax
	popq    %r11
	popq    %rdi
	popq    %rsi
	popq    %rdx
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
	movq    -8(%rbp), %rax 	# i, 0
	pushq   %rax
	movq    $0x1, %rax
	pushq   %rax
	popq    %r10
	popq    %rax
	addq    %r10,   %rax
	pushq    %rax
	movq    -8(%rbp),   %rax 	# i, 0
	leaq -8(%rbp),    %rax
	pushq %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
	jmp    LBB0_3
LBB0_4:
L.XCC.RE.main:
	movq    %rbp, %rsp
	popq    %rbp
	retq
