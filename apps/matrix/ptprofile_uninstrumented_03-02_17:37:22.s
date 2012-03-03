	.file	"ld-temp.o"
	.text
	.align	16, 0x90
	.type	worker,@function
worker:                                 # @worker
.Ltmp3:
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp4:
	.cfi_def_cfa_offset 16
	pushq	%rbx
.Ltmp5:
	.cfi_def_cfa_offset 24
.Ltmp6:
	.cfi_offset %rbx, -24
.Ltmp7:
	.cfi_offset %rbp, -16
	movl	(%rdi), %ecx
	movl	8(%rdi), %eax
	cmpl	%eax, %ecx
	jge	.LBB0_9
# BB#1:                                 # %for.cond.preheader.lr.ph.i
	movslq	4(%rdi), %r8
	testl	%eax, %eax
	jle	.LBB0_8
# BB#2:                                 # %for.body4.lr.ph.us.i.preheader.us.preheader
	movq	32(%rdi), %r10
	movq	24(%rdi), %r11
	movq	16(%rdi), %rdx
	movslq	%ecx, %rdi
	imulq	$8000, %rdi, %rsi       # imm = 0x1F40
	addq	%rdx, %rsi
	imulq	$8000, %r8, %r9         # imm = 0x1F40
	.align	16, 0x90
.LBB0_3:                                # %for.body4.lr.ph.us.i.preheader.us
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_4 Depth 2
                                        #       Child Loop BB0_5 Depth 3
	xorl	%edx, %edx
	.align	16, 0x90
.LBB0_4:                                # %for.body4.lr.ph.us.i.us
                                        #   Parent Loop BB0_3 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_5 Depth 3
	pxor	%xmm0, %xmm0
	movq	%rsi, %rcx
	movq	%r11, %rbx
	movl	%eax, %ebp
	.align	16, 0x90
.LBB0_5:                                # %for.body4.us.i.us
                                        #   Parent Loop BB0_3 Depth=1
                                        #     Parent Loop BB0_4 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movsd	(%rcx), %xmm1
	mulsd	(%rbx,%rdx,8), %xmm1
	addsd	%xmm1, %xmm0
	addq	$8, %rcx
	addq	$8000, %rbx             # imm = 0x1F40
	decl	%ebp
	jne	.LBB0_5
# BB#6:                                 # %for.end.us.i.us
                                        #   in Loop: Header=BB0_4 Depth=2
	imulq	$8000, %rdi, %rcx       # imm = 0x1F40
	addq	%r10, %rcx
	movsd	%xmm0, (%rcx,%rdx,8)
	incq	%rdx
	cmpl	%eax, %edx
	jne	.LBB0_4
# BB#7:                                 # %for.end17.i.us
                                        #   in Loop: Header=BB0_3 Depth=1
	addq	%r9, %rsi
	addq	%r8, %rdi
	cmpl	%eax, %edi
	jl	.LBB0_3
	jmp	.LBB0_9
	.align	16, 0x90
.LBB0_8:                                # %for.end17.i
                                        # =>This Inner Loop Header: Depth=1
	addl	%r8d, %ecx
	cmpl	%eax, %ecx
	jl	.LBB0_8
.LBB0_9:                                # %mm.exit
	xorl	%eax, %eax
	popq	%rbx
	popq	%rbp
	ret
.Ltmp8:
	.size	worker, .Ltmp8-worker
.Ltmp9:
	.cfi_endproc
.Leh_func_end0:

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Ltmp17:
	.cfi_startproc
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp18:
	.cfi_def_cfa_offset 16
	pushq	%r15
.Ltmp19:
	.cfi_def_cfa_offset 24
	pushq	%r14
.Ltmp20:
	.cfi_def_cfa_offset 32
	pushq	%r13
.Ltmp21:
	.cfi_def_cfa_offset 40
	pushq	%r12
.Ltmp22:
	.cfi_def_cfa_offset 48
	pushq	%rbx
.Ltmp23:
	.cfi_def_cfa_offset 56
	subq	$72, %rsp
.Ltmp24:
	.cfi_def_cfa_offset 128
.Ltmp25:
	.cfi_offset %rbx, -56
.Ltmp26:
	.cfi_offset %r12, -48
.Ltmp27:
	.cfi_offset %r13, -40
.Ltmp28:
	.cfi_offset %r14, -32
.Ltmp29:
	.cfi_offset %r15, -24
.Ltmp30:
	.cfi_offset %rbp, -16
	xorl	%r8d, %r8d
	xorl	%r9d, %r9d
	xorl	%edx, %edx
	.align	16, 0x90
.LBB1_1:                                # %for.cond1.preheader
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_2 Depth 2
	movl	$1000, %ebp             # imm = 0x3E8
	movl	%r9d, %ecx
	movq	%r8, %rax
	.align	16, 0x90
.LBB1_2:                                # %for.body3
                                        #   Parent Loop BB1_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, a(%rax)
	movsd	%xmm0, b(%rax)
	incl	%ecx
	addq	$8, %rax
	decl	%ebp
	jne	.LBB1_2
# BB#3:                                 # %for.inc12
                                        #   in Loop: Header=BB1_1 Depth=1
	incl	%r9d
	addq	$8000, %r8              # imm = 0x1F40
	incq	%rdx
	cmpl	$1000, %edx             # imm = 0x3E8
	jne	.LBB1_1
# BB#4:                                 # %for.end14
	cmpl	$2, %edi
	jne	.LBB1_11
# BB#5:                                 # %if.end
	movq	8(%rsi), %rdi
	xorb	%al, %al
	callq	atoi
	movl	%eax, %ebx
	movslq	%ebx, %r15
	leaq	(,%r15,8), %rbp
	movq	%rbp, %rdi
	callq	malloc
	movq	%rax, %r14
	leaq	16(%rsp), %rdi
	callq	pthread_attr_init
	leaq	(%rbp,%rbp,4), %rdi
	callq	malloc
	movq	%rax, %rbp
	testl	%r15d, %r15d
	jle	.LBB1_10
# BB#6:
	xorl	%r15d, %r15d
	leaq	16(%rsp), %r12
	movq	%rbp, 8(%rsp)           # 8-byte Spill
	movq	%rbp, %r13
	movq	%r14, %rbp
	.align	16, 0x90
.LBB1_7:                                # %for.body29
                                        # =>This Inner Loop Header: Depth=1
	movl	%r15d, (%r13)
	movl	%ebx, 4(%r13)
	movl	$1000, 8(%r13)          # imm = 0x3E8
	movq	$a, 16(%r13)
	movq	$b, 24(%r13)
	movq	$c, 32(%r13)
	movq	%rbp, %rdi
	movq	%r12, %rsi
	movl	$worker, %edx
	movq	%r13, %rcx
	callq	pthread_create
	addq	$8, %rbp
	addq	$40, %r13
	incl	%r15d
	cmpl	%r15d, %ebx
	jne	.LBB1_7
# BB#8:
	movq	8(%rsp), %rbp           # 8-byte Reload
	.align	16, 0x90
.LBB1_9:                                # %for.body52
                                        # =>This Inner Loop Header: Depth=1
	movq	(%r14), %rdi
	xorl	%esi, %esi
	callq	pthread_join
	addq	$8, %r14
	decl	%ebx
	jne	.LBB1_9
.LBB1_10:                               # %for.end58
	movq	%rbp, %rdi
	xorb	%al, %al
	callq	free
	xorl	%eax, %eax
	addq	$72, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.LBB1_11:                               # %if.then
	movq	(%rsi), %rsi
	movl	$.L.str, %edi
	xorb	%al, %al
	callq	printf
	movl	$1, %edi
	callq	exit
.Ltmp31:
	.size	main, .Ltmp31-main
.Ltmp32:
	.cfi_endproc
.Leh_func_end1:

	.type	a,@object               # @a
	.local	a
	.comm	a,8000000,16
	.type	b,@object               # @b
	.local	b
	.comm	b,8000000,16
	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	 "Usage: %s n\n  where n is no. of thread\n"
	.size	.L.str, 40

	.type	c,@object               # @c
	.local	c
	.comm	c,8000000,16

	.section	".note.GNU-stack","",@progbits
