	.text
	.globl  mod
	.p2align 4, 0x90
mod:
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $0, %rsp
	pushq   %rdi
	pushq   %rdi
	pushq   %rsi
	popq    %r10
	popq    %rax
	xorq %rdx, %rdx
	divq    %r10
	pushq    %rax
	pushq   %rsi
	popq    %r10
	popq    %rax
	mulq    %r10
	pushq    %rax
	popq    %r10
	popq    %rax
	subq    %r10,   %rax
	pushq    %rax
	popq    %rax
	jmp    L.XCC.RE.mod
L.XCC.RE.mod:
	movq    %rbp, %rsp
	popq    %rbp
	retq
	.text
	.globl  swap
	.p2align 4, 0x90
swap:
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $16, %rsp
	pushq   %rdi
	popq    %rax
	movq    0(%rax), %rax
	pushq   %rax
	movq    -8(%rbp),   %rax 	# tmp, 0
	leaq -8(%rbp),    %rax
	pushq %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
	pushq   %rsi
	popq    %rax
	movq    0(%rax), %rax
	pushq   %rax
	pushq   %rdi
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
	movq    -8(%rbp), %rax 	# tmp, 0
	pushq   %rax
	pushq   %rsi
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
L.XCC.RE.swap:
	movq    %rbp, %rsp
	popq    %rbp
	retq
	.text
	.globl  bubble_sort
	.p2align 4, 0x90
bubble_sort:
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $16, %rsp
	pushq   %rsi
	movq    $0x1, %rax
	pushq   %rax
	popq    %r10
	popq    %rax
	subq    %r10,   %rax
	pushq    %rax
	movq    -8(%rbp),   %rax 	# i, 0
	leaq -8(%rbp),    %rax
	pushq %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
LBB0_0:
	movq    $0x0, %rax
	pushq   %rax
	movq    -8(%rbp), %rax 	# i, 0
	pushq   %rax
	popq    %rax
	popq    %r10
	cmpq    %rax,   %r10
	setl    %al
	movzbq    %al,   %rax
	pushq    %rax
	popq    %rax
	cmpq    $0,   %rax
	je    LBB0_1
	movq    $0x0, %rax
	pushq   %rax
	movq    -16(%rbp),   %rax 	# j, 8
	leaq -16(%rbp),    %rax
	pushq %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
LBB0_2:
	movq    -16(%rbp), %rax 	# j, 8
	pushq   %rax
	movq    -8(%rbp), %rax 	# i, 0
	pushq   %rax
	popq    %rax
	popq    %r10
	cmpq    %rax,   %r10
	setl    %al
	movzbq    %al,   %rax
	pushq    %rax
	popq    %rax
	cmpq    $0,   %rax
	je    LBB0_3
	movq    $0x1, %rax
	pushq   %rax
	movq    -16(%rbp), %rax 	# j, 8
	pushq   %rax
	popq    %r10
	popq    %rax
	addq    %r10,   %rax
	pushq    %rax
	pushq   %rdi
	popq    %rax
	popq    %r10
	imulq   $8, %r10
	addq    %r10, %rax
	pushq   %rax
	popq    %rax
	movq    0(%rax), %rax
	pushq   %rax
	movq    -16(%rbp), %rax 	# j, 8
	pushq   %rax
	pushq   %rdi
	popq    %rax
	popq    %r10
	imulq   $8, %r10
	addq    %r10, %rax
	pushq   %rax
	popq    %rax
	movq    0(%rax), %rax
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
	movq    $0x1, %rax
	pushq   %rax
	movq    -16(%rbp), %rax 	# j, 8
	pushq   %rax
	popq    %r10
	popq    %rax
	addq    %r10,   %rax
	pushq    %rax
	pushq   %rdi
	popq    %rax
	popq    %r10
	imulq   $8, %r10
	addq    %r10, %rax
	pushq   %rax
	movq    -16(%rbp), %rax 	# j, 8
	pushq   %rax
	pushq   %rdi
	popq    %rax
	popq    %r10
	imulq   $8, %r10
	addq    %r10, %rax
	pushq   %rax
	leaq    swap(%rip), %rax
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
LBB0_4:
	movq    $0x1, %rax
	pushq   %rax
	movq    -16(%rbp), %rax 	# j, 8
	pushq   %rax
	popq    %r10
	popq    %rax
	addq    %r10,   %rax
	pushq    %rax
	movq    -16(%rbp),   %rax 	# j, 8
	leaq -16(%rbp),    %rax
	pushq %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
	jmp    LBB0_2
LBB0_3:
	movq    -8(%rbp), %rax 	# i, 0
	pushq   %rax
	movq    $0x1, %rax
	pushq   %rax
	popq    %r10
	popq    %rax
	subq    %r10,   %rax
	pushq    %rax
	movq    -8(%rbp),   %rax 	# i, 0
	leaq -8(%rbp),    %rax
	pushq %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
	jmp    LBB0_0
LBB0_1:
L.XCC.RE.bubble_sort:
	movq    %rbp, %rsp
	popq    %rbp
	retq
	.text
	.globl  make_array
	.p2align 4, 0x90
make_array:
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
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	pushq   %rdx
	movq    srandom@GOTPCREL(%rip), %rax
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
	addq    $8, %rsp
LBB0_5:
	movq    -8(%rbp), %rax 	# i, 0
	pushq   %rax
	pushq   %rsi
	popq    %rax
	popq    %r10
	cmpq    %rax,   %r10
	setl    %al
	movzbq    %al,   %rax
	pushq    %rax
	popq    %rax
	cmpq    $0,   %rax
	je    LBB0_6
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	movq    random@GOTPCREL(%rip), %rax
	pushq   %rax
	popq    %r11
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
	movq    -16(%rbp),   %rax 	# j, 8
	leaq -16(%rbp),    %rax
	pushq %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	pushq   %rsi
	movq    -16(%rbp), %rax 	# j, 8
	pushq   %rax
	leaq    mod(%rip), %rax
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
	movq    -8(%rbp), %rax 	# i, 0
	pushq   %rax
	pushq   %rdi
	popq    %rax
	popq    %r10
	imulq   $8, %r10
	addq    %r10, %rax
	pushq   %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
	movq    $0x1, %rax
	pushq   %rax
	movq    -8(%rbp), %rax 	# i, 0
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
	jmp    LBB0_5
LBB0_6:
L.XCC.RE.make_array:
	movq    %rbp, %rsp
	popq    %rbp
	retq
	.text
L.XCC.STR0:
	.ascii  "%ld\n\0"
	.text
	.globl  main
	.p2align 4, 0x90
main:
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $32, %rsp
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	movq    $0x1, %rax
	pushq   %rax
	pushq   %rsi
	popq    %rax
	popq    %r10
	imulq   $8, %r10
	addq    %r10, %rax
	pushq   %rax
	popq    %rax
	movq    0(%rax), %rax
	pushq   %rax
	movq    atol@GOTPCREL(%rip), %rax
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
	movq    -24(%rbp),   %rax 	# size, 16
	leaq -24(%rbp),    %rax
	pushq %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	movq    $0x8, %rax
	pushq   %rax
	movq    -24(%rbp), %rax 	# size, 16
	pushq   %rax
	popq    %r10
	popq    %rax
	mulq    %r10
	pushq    %rax
	movq    malloc@GOTPCREL(%rip), %rax
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
	movq    -16(%rbp),   %rax 	# p, 8
	leaq -16(%rbp),    %rax
	pushq %rax
	popq    %rax
	popq    %r10
	movq    %r10, 0(%rax)
	pushq    %r10
	addq    $8, %rsp
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	movq    $0x0, %rax
	pushq   %rax
	movq    -24(%rbp), %rax 	# size, 16
	pushq   %rax
	movq    -16(%rbp), %rax 	# p, 8
	pushq   %rax
	leaq    make_array(%rip), %rax
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
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	movq    -24(%rbp), %rax 	# size, 16
	pushq   %rax
	movq    -16(%rbp), %rax 	# p, 8
	pushq   %rax
	leaq    bubble_sort(%rip), %rax
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
LBB0_7:
	movq    -8(%rbp), %rax 	# i, 0
	pushq   %rax
	movq    -24(%rbp), %rax 	# size, 16
	pushq   %rax
	popq    %rax
	popq    %r10
	cmpq    %rax,   %r10
	setl    %al
	movzbq    %al,   %rax
	pushq    %rax
	popq    %rax
	cmpq    $0,   %rax
	je    LBB0_8
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
	movq    -16(%rbp), %rax 	# p, 8
	pushq   %rax
	popq    %rax
	popq    %r10
	imulq   $8, %r10
	addq    %r10, %rax
	pushq   %rax
	popq    %rax
	movq    0(%rax), %rax
	pushq   %rax
	leaq    L.XCC.STR0(%rip), %rax 	# "%ld\n"
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
	movq    $0x1, %rax
	pushq   %rax
	movq    -8(%rbp), %rax 	# i, 0
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
	jmp    LBB0_7
LBB0_8:
L.XCC.RE.main:
	movq    %rbp, %rsp
	popq    %rbp
	retq
