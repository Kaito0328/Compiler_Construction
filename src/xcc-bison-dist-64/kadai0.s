	.text
L.XCC.STR0:
	.ascii  "hello, world, %d, %d\n\0"
	.text
	.globl  main
	.p2align 4, 0x90
main:
	pushq   %rbp
	movq    %rsp, %rbp
	subq    $0, %rsp
# save caller-saved registers
	pushq   %rcx
	pushq   %rdx
	pushq   %rdi
	pushq   %rsi
	pushq   %r8
	pushq   %r9
	pushq   %r10
	pushq   %r11
	movq    $0x14, %rax
	pushq   %rax
	movq    $0xa, %rax
	pushq   %rax
	leaq    L.XCC.STR0(%rip), %rax 	# "hello, world, %d, %d\n"
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
	movq    exit@GOTPCREL(%rip), %rax
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
L.XCC.RE.main:
	movq    %rbp, %rsp
	popq    %rbp
	retq
