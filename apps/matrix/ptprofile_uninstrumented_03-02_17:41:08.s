	.file	"ld-temp.o"
	.file	1 "/home/kuitang/CYG2/apps/matrix/matrix.c"
	.section	.debug_info,"",@progbits
.Lsection_info:
	.section	.debug_abbrev,"",@progbits
.Lsection_abbrev:
	.section	.debug_aranges,"",@progbits
	.section	.debug_macinfo,"",@progbits
	.section	.debug_line,"",@progbits
.Lsection_line:
	.section	.debug_loc,"",@progbits
	.section	.debug_pubnames,"",@progbits
	.section	.debug_pubtypes,"",@progbits
	.section	.debug_str,"",@progbits
.Lsection_str:
	.section	.debug_ranges,"",@progbits
.Ldebug_range:
	.section	.debug_loc,"",@progbits
.Lsection_debug_loc:
	.text
.Ltext_begin:
	.data
	.text
	.align	16, 0x90
	.type	worker,@function
worker:                                 # @worker
.Ltmp3:
	.cfi_startproc
.Lfunc_begin0:
	.loc	1 38 0                  # matrix.c:38:0
# BB#0:                                 # %entry
	.loc	1 40 3 prologue_end     # matrix.c:40:3
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
	#DEBUG_VALUE: worker:arg <- RDI+0
	movl	(%rdi), %ecx
	movl	8(%rdi), %eax
	cmpl	%eax, %ecx
	jge	.LBB0_9
# BB#1:                                 # %for.cond.preheader.lr.ph.i
	#DEBUG_VALUE: worker:arg <- RDI+0
	movslq	4(%rdi), %r8
	.loc	1 28 10                 # matrix.c:28:10
.Ltmp8:
	testl	%eax, %eax
	jle	.LBB0_8
.Ltmp9:
# BB#2:                                 # %for.body4.lr.ph.us.i.preheader.us.preheader
	#DEBUG_VALUE: worker:arg <- RDI+0
	.loc	1 40 3                  # matrix.c:40:3
	movq	32(%rdi), %r10
	movq	24(%rdi), %r11
	movq	16(%rdi), %rdx
	.loc	1 30 12                 # matrix.c:30:12
.Ltmp10:
	movslq	%ecx, %rdi
.Ltmp11:
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
	.loc	1 27 3                  # matrix.c:27:3
	movq	%rsi, %rcx
	.loc	1 30 12                 # matrix.c:30:12
	movq	%r11, %rbx
	movl	%eax, %ebp
	.align	16, 0x90
.LBB0_5:                                # %for.body4.us.i.us
                                        #   Parent Loop BB0_3 Depth=1
                                        #     Parent Loop BB0_4 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	.loc	1 31 2                  # matrix.c:31:2
	movsd	(%rcx), %xmm1
	mulsd	(%rbx,%rdx,8), %xmm1
	addsd	%xmm1, %xmm0
	.loc	1 30 12                 # matrix.c:30:12
	addq	$8, %rcx
	addq	$8000, %rbx             # imm = 0x1F40
	decl	%ebp
	jne	.LBB0_5
# BB#6:                                 # %for.end.us.i.us
                                        #   in Loop: Header=BB0_4 Depth=2
	.loc	1 32 7                  # matrix.c:32:7
	imulq	$8000, %rdi, %rcx       # imm = 0x1F40
	addq	%r10, %rcx
	movsd	%xmm0, (%rcx,%rdx,8)
	.loc	1 28 10                 # matrix.c:28:10
	incq	%rdx
	cmpl	%eax, %edx
	jne	.LBB0_4
# BB#7:                                 # %for.end17.i.us
                                        #   in Loop: Header=BB0_3 Depth=1
	.loc	1 27 3                  # matrix.c:27:3
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
.Ltmp12:
.LBB0_9:                                # %mm.exit
	xorl	%eax, %eax
	.loc	1 41 3                  # matrix.c:41:3
	popq	%rbx
	popq	%rbp
	ret
.Ltmp13:
.Ltmp14:
	.size	worker, .Ltmp14-worker
.Lfunc_end0:
.Ltmp15:
	.cfi_endproc
.Leh_func_end0:

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Ltmp23:
	.cfi_startproc
.Lfunc_begin1:
	.loc	1 45 0                  # matrix.c:45:0
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp24:
	.cfi_def_cfa_offset 16
	pushq	%r15
.Ltmp25:
	.cfi_def_cfa_offset 24
	pushq	%r14
.Ltmp26:
	.cfi_def_cfa_offset 32
	pushq	%r13
.Ltmp27:
	.cfi_def_cfa_offset 40
	pushq	%r12
.Ltmp28:
	.cfi_def_cfa_offset 48
	pushq	%rbx
.Ltmp29:
	.cfi_def_cfa_offset 56
	subq	$72, %rsp
.Ltmp30:
	.cfi_def_cfa_offset 128
.Ltmp31:
	.cfi_offset %rbx, -56
.Ltmp32:
	.cfi_offset %r12, -48
.Ltmp33:
	.cfi_offset %r13, -40
.Ltmp34:
	.cfi_offset %r14, -32
.Ltmp35:
	.cfi_offset %r15, -24
.Ltmp36:
	.cfi_offset %rbp, -16
	#DEBUG_VALUE: main:argc <- EDI+0
	#DEBUG_VALUE: main:argv <- RSI+0
	xorl	%r8d, %r8d
	xorl	%r9d, %r9d
.Ltmp37:
	#DEBUG_VALUE: i <- 0+0
	xorl	%edx, %edx
	.align	16, 0x90
.LBB1_1:                                # %for.cond1.preheader
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_2 Depth 2
	#DEBUG_VALUE: main:argc <- EDI+0
	#DEBUG_VALUE: main:argv <- RSI+0
	#DEBUG_VALUE: i <- 0+0
	movl	$1000, %ebp             # imm = 0x3E8
	.loc	1 52 8 prologue_end     # matrix.c:52:8
.Ltmp38:
	movl	%r9d, %ecx
	movq	%r8, %rax
	.align	16, 0x90
.LBB1_2:                                # %for.body3
                                        #   Parent Loop BB1_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	#DEBUG_VALUE: main:argc <- EDI+0
	#DEBUG_VALUE: main:argv <- RSI+0
	#DEBUG_VALUE: i <- 0+0
	.loc	1 54 2                  # matrix.c:54:2
.Ltmp39:
	cvtsi2sd	%ecx, %xmm0
	movsd	%xmm0, a(%rax)
	.loc	1 55 2                  # matrix.c:55:2
	movsd	%xmm0, b(%rax)
.Ltmp40:
	.loc	1 53 10                 # matrix.c:53:10
	incl	%ecx
	addq	$8, %rax
	decl	%ebp
	jne	.LBB1_2
.Ltmp41:
# BB#3:                                 # %for.inc12
                                        #   in Loop: Header=BB1_1 Depth=1
	#DEBUG_VALUE: main:argc <- EDI+0
	#DEBUG_VALUE: main:argv <- RSI+0
	#DEBUG_VALUE: i <- 0+0
	.loc	1 52 8                  # matrix.c:52:8
	incl	%r9d
	addq	$8000, %r8              # imm = 0x1F40
	incq	%rdx
	cmpl	$1000, %edx             # imm = 0x3E8
	jne	.LBB1_1
.Ltmp42:
# BB#4:                                 # %for.end14
	#DEBUG_VALUE: main:argc <- EDI+0
	#DEBUG_VALUE: main:argv <- RSI+0
	.loc	1 58 3                  # matrix.c:58:3
	cmpl	$2, %edi
	jne	.LBB1_11
.Ltmp43:
# BB#5:                                 # %if.end
	#DEBUG_VALUE: main:argv <- RSI+0
	.loc	1 62 7                  # matrix.c:62:7
	movq	8(%rsi), %rdi
	xorb	%al, %al
	callq	atoi
.Ltmp44:
	movl	%eax, %ebx
	.loc	1 71 27                 # matrix.c:71:27
	movslq	%ebx, %r15
	leaq	(,%r15,8), %rbp
	movq	%rbp, %rdi
	callq	malloc
	movq	%rax, %r14
	leaq	16(%rsp), %rdi
	.loc	1 72 3                  # matrix.c:72:3
	callq	pthread_attr_init
	.loc	1 73 15                 # matrix.c:73:15
	leaq	(%rbp,%rbp,4), %rdi
	callq	malloc
	movq	%rax, %rbp
.Ltmp45:
	#DEBUG_VALUE: i <- 0+0
	.loc	1 62 7                  # matrix.c:62:7
	testl	%r15d, %r15d
	jle	.LBB1_10
# BB#6:
	xorl	%r15d, %r15d
	leaq	16(%rsp), %r12
	.loc	1 75 8                  # matrix.c:75:8
.Ltmp46:
	movq	%rbp, 8(%rsp)           # 8-byte Spill
	movq	%rbp, %r13
	movq	%r14, %rbp
	.align	16, 0x90
.LBB1_7:                                # %for.body29
                                        # =>This Inner Loop Header: Depth=1
	.loc	1 76 5                  # matrix.c:76:5
.Ltmp47:
	movl	%r15d, (%r13)
	.loc	1 77 5                  # matrix.c:77:5
	movl	%ebx, 4(%r13)
	.loc	1 78 5                  # matrix.c:78:5
	movl	$1000, 8(%r13)          # imm = 0x3E8
	.loc	1 79 5                  # matrix.c:79:5
	movq	$a, 16(%r13)
	.loc	1 80 5                  # matrix.c:80:5
	movq	$b, 24(%r13)
	.loc	1 81 5                  # matrix.c:81:5
	movq	$c, 32(%r13)
	.loc	1 82 5                  # matrix.c:82:5
	movq	%rbp, %rdi
	movq	%r12, %rsi
	movl	$worker, %edx
	movq	%r13, %rcx
	callq	pthread_create
.Ltmp48:
	.loc	1 75 8                  # matrix.c:75:8
	addq	$8, %rbp
	addq	$40, %r13
	incl	%r15d
	.loc	1 77 5                  # matrix.c:77:5
.Ltmp49:
	cmpl	%r15d, %ebx
	jne	.LBB1_7
.Ltmp50:
# BB#8:
	movq	8(%rsp), %rbp           # 8-byte Reload
	.align	16, 0x90
.LBB1_9:                                # %for.body52
                                        # =>This Inner Loop Header: Depth=1
	.loc	1 86 5                  # matrix.c:86:5
.Ltmp51:
	movq	(%r14), %rdi
	xorl	%esi, %esi
	callq	pthread_join
	.loc	1 85 8                  # matrix.c:85:8
	addq	$8, %r14
	decl	%ebx
	jne	.LBB1_9
.Ltmp52:
.LBB1_10:                               # %for.end58
	.loc	1 90 3                  # matrix.c:90:3
	movq	%rbp, %rdi
	xorb	%al, %al
	callq	free
	xorl	%eax, %eax
	.loc	1 91 3                  # matrix.c:91:3
	addq	$72, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.LBB1_11:                               # %if.then
.Ltmp53:
	#DEBUG_VALUE: main:argv <- RSI+0
	.loc	1 59 5                  # matrix.c:59:5
	movq	(%rsi), %rsi
.Ltmp54:
	movl	$.L.str, %edi
	xorb	%al, %al
	callq	printf
	movl	$1, %edi
	.loc	1 60 5                  # matrix.c:60:5
	callq	exit
.Ltmp55:
.Ltmp56:
	.size	main, .Ltmp56-main
.Lfunc_end1:
	.file	2 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h"
.Ltmp57:
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
	.text
.Ltext_end:
	.data
.Ldata_end:
	.text
.Lsection_end1:
	.section	.debug_info,"",@progbits
.Linfo_begin1:
	.long	1095                    # Length of Compilation Unit Info
	.short	2                       # DWARF version number
	.long	.Labbrev_begin          # Offset Into Abbrev. Section
	.byte	8                       # Address Size (in bytes)
	.byte	1                       # Abbrev [1] 0xb:0x440 DW_TAG_compile_unit
	.ascii	 "clang version 3.0 (tags/RELEASE_30/final)" # DW_AT_producer
	.byte	0
	.short	12                      # DW_AT_language
	.ascii	 "matrix.c"             # DW_AT_name
	.byte	0
	.quad	0                       # DW_AT_entry_pc
	.long	.Lsection_line          # DW_AT_stmt_list
	.ascii	 "/home/kuitang/CYG2/apps/matrix" # DW_AT_comp_dir
	.byte	0
	.byte	1                       # DW_AT_APPLE_optimized
	.byte	2                       # Abbrev [2] 0x6d:0xa DW_TAG_base_type
	.ascii	 "double"               # DW_AT_name
	.byte	0
	.byte	4                       # DW_AT_encoding
	.byte	8                       # DW_AT_byte_size
	.byte	3                       # Abbrev [3] 0x77:0x3 DW_TAG_base_type
	.byte	4                       # DW_AT_byte_size
	.byte	5                       # DW_AT_encoding
	.byte	4                       # Abbrev [4] 0x7a:0x18 DW_TAG_array_type
	.long	146                     # DW_AT_sibling
	.long	109                     # DW_AT_type
	.byte	5                       # Abbrev [5] 0x83:0x7 DW_TAG_subrange_type
	.long	119                     # DW_AT_type
	.short	999                     # DW_AT_upper_bound
	.byte	5                       # Abbrev [5] 0x8a:0x7 DW_TAG_subrange_type
	.long	119                     # DW_AT_type
	.short	999                     # DW_AT_upper_bound
	.byte	0                       # End Of Children Mark
	.byte	6                       # Abbrev [6] 0x92:0x14 DW_TAG_variable
	.byte	97                      # DW_AT_name
	.byte	0
	.long	122                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.byte	1                       # DW_AT_decl_file
	.byte	12                      # DW_AT_decl_line
	.byte	9                       # DW_AT_location
	.byte	3
	.quad	a
	.byte	6                       # Abbrev [6] 0xa6:0x14 DW_TAG_variable
	.byte	98                      # DW_AT_name
	.byte	0
	.long	122                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.byte	1                       # DW_AT_decl_file
	.byte	13                      # DW_AT_decl_line
	.byte	9                       # DW_AT_location
	.byte	3
	.quad	b
	.byte	6                       # Abbrev [6] 0xba:0x14 DW_TAG_variable
	.byte	99                      # DW_AT_name
	.byte	0
	.long	122                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.byte	1                       # DW_AT_decl_file
	.byte	14                      # DW_AT_decl_line
	.byte	9                       # DW_AT_location
	.byte	3
	.quad	c
	.byte	7                       # Abbrev [7] 0xce:0x75 DW_TAG_subprogram
	.long	323                     # DW_AT_sibling
	.ascii	 "mm"                   # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	23                      # DW_AT_decl_line
	.byte	1                       # DW_AT_prototyped
	.byte	1                       # DW_AT_external
	.byte	1                       # DW_AT_inline
	.byte	8                       # Abbrev [8] 0xdb:0xd DW_TAG_formal_parameter
	.ascii	 "me_no"                # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	23                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	8                       # Abbrev [8] 0xe8:0xe DW_TAG_formal_parameter
	.ascii	 "noproc"               # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	23                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	8                       # Abbrev [8] 0xf6:0x9 DW_TAG_formal_parameter
	.byte	110                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	23                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	8                       # Abbrev [8] 0xff:0x9 DW_TAG_formal_parameter
	.byte	97                      # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	23                      # DW_AT_decl_line
	.long	823                     # DW_AT_type
	.byte	8                       # Abbrev [8] 0x108:0x9 DW_TAG_formal_parameter
	.byte	98                      # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	23                      # DW_AT_decl_line
	.long	823                     # DW_AT_type
	.byte	8                       # Abbrev [8] 0x111:0x9 DW_TAG_formal_parameter
	.byte	99                      # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	23                      # DW_AT_decl_line
	.long	823                     # DW_AT_type
	.byte	9                       # Abbrev [9] 0x11a:0x28 DW_TAG_lexical_block
	.byte	10                      # Abbrev [10] 0x11b:0x9 DW_TAG_variable
	.byte	105                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	24                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x124:0x9 DW_TAG_variable
	.byte	106                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	24                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x12d:0x9 DW_TAG_variable
	.byte	107                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	24                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x136:0xb DW_TAG_variable
	.ascii	 "sum"                  # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	25                      # DW_AT_decl_line
	.long	109                     # DW_AT_type
	.byte	0                       # End Of Children Mark
	.byte	0                       # End Of Children Mark
	.byte	11                      # Abbrev [11] 0x143:0x5d DW_TAG_subprogram
	.long	416                     # DW_AT_sibling
	.ascii	 "worker"               # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	38                      # DW_AT_decl_line
	.byte	1                       # DW_AT_prototyped
	.long	416                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.quad	.Lfunc_begin0           # DW_AT_low_pc
	.quad	.Lfunc_end0             # DW_AT_high_pc
	.byte	1                       # DW_AT_frame_base
	.byte	87
	.byte	1                       # DW_AT_APPLE_omit_frame_ptr
	.byte	12                      # Abbrev [12] 0x16a:0xf DW_TAG_formal_parameter
	.ascii	 "arg"                  # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	38                      # DW_AT_decl_line
	.long	416                     # DW_AT_type
.Lset0 = .Ldebug_loc0-.Lsection_debug_loc # DW_AT_location
	.long	.Lset0
	.byte	13                      # Abbrev [13] 0x179:0x26 DW_TAG_lexical_block
	.quad	.Lfunc_begin0           # DW_AT_low_pc
	.quad	.Ltmp13                 # DW_AT_high_pc
	.byte	10                      # Abbrev [10] 0x18a:0x9 DW_TAG_variable
	.byte	112                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	39                      # DW_AT_decl_line
	.long	938                     # DW_AT_type
	.byte	14                      # Abbrev [14] 0x193:0xb DW_TAG_inlined_subroutine
	.long	206                     # DW_AT_abstract_origin
	.long	.Ldebug_range+0         # DW_AT_ranges
	.byte	1                       # DW_AT_call_file
	.byte	40                      # DW_AT_call_line
	.byte	0                       # End Of Children Mark
	.byte	0                       # End Of Children Mark
	.byte	15                      # Abbrev [15] 0x1a0:0x2 DW_TAG_pointer_type
	.byte	8                       # DW_AT_byte_size
	.byte	11                      # Abbrev [11] 0x1a2:0xf0 DW_TAG_subprogram
	.long	658                     # DW_AT_sibling
	.ascii	 "main"                 # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	45                      # DW_AT_decl_line
	.byte	1                       # DW_AT_prototyped
	.long	658                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.quad	.Lfunc_begin1           # DW_AT_low_pc
	.quad	.Lfunc_end1             # DW_AT_high_pc
	.byte	1                       # DW_AT_frame_base
	.byte	87
	.byte	1                       # DW_AT_APPLE_omit_frame_ptr
	.byte	12                      # Abbrev [12] 0x1c7:0x10 DW_TAG_formal_parameter
	.ascii	 "argc"                 # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	44                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
.Lset1 = .Ldebug_loc3-.Lsection_debug_loc # DW_AT_location
	.long	.Lset1
	.byte	12                      # Abbrev [12] 0x1d7:0x10 DW_TAG_formal_parameter
	.ascii	 "argv"                 # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	44                      # DW_AT_decl_line
	.long	958                     # DW_AT_type
.Lset2 = .Ldebug_loc6-.Lsection_debug_loc # DW_AT_location
	.long	.Lset2
	.byte	13                      # Abbrev [13] 0x1e7:0xaa DW_TAG_lexical_block
	.quad	.Ltmp38                 # DW_AT_low_pc
	.quad	.Ltmp55                 # DW_AT_high_pc
	.byte	16                      # Abbrev [16] 0x1f8:0xe DW_TAG_variable
	.byte	105                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	46                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	4                       # DW_AT_const_value
	.long	0
	.byte	10                      # Abbrev [10] 0x206:0x9 DW_TAG_variable
	.byte	106                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	46                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x20f:0x9 DW_TAG_variable
	.byte	107                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	46                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x218:0x9 DW_TAG_variable
	.byte	110                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	46                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x221:0xe DW_TAG_variable
	.ascii	 "noproc"               # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	46                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x22f:0xd DW_TAG_variable
	.ascii	 "me_no"                # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	46                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x23c:0xb DW_TAG_variable
	.ascii	 "sum"                  # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	47                      # DW_AT_decl_line
	.long	109                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x247:0xa DW_TAG_variable
	.ascii	 "t1"                   # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	47                      # DW_AT_decl_line
	.long	109                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x251:0xa DW_TAG_variable
	.ascii	 "t2"                   # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	47                      # DW_AT_decl_line
	.long	109                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x25b:0xf DW_TAG_variable
	.ascii	 "threads"              # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	48                      # DW_AT_decl_line
	.long	1000                    # DW_AT_type
	.byte	10                      # Abbrev [10] 0x26a:0x1b DW_TAG_variable
	.ascii	 "pthread_custom_attr"  # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	49                      # DW_AT_decl_line
	.long	1078                    # DW_AT_type
	.byte	10                      # Abbrev [10] 0x285:0xb DW_TAG_variable
	.ascii	 "arg"                  # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	50                      # DW_AT_decl_line
	.long	938                     # DW_AT_type
	.byte	0                       # End Of Children Mark
	.byte	0                       # End Of Children Mark
	.byte	2                       # Abbrev [2] 0x292:0x7 DW_TAG_base_type
	.ascii	 "int"                  # DW_AT_name
	.byte	0
	.byte	5                       # DW_AT_encoding
	.byte	4                       # DW_AT_byte_size
	.byte	17                      # Abbrev [17] 0x299:0x37 DW_TAG_subprogram
	.long	720                     # DW_AT_sibling
	.ascii	 "print_matrix"         # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	96                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.byte	8                       # Abbrev [8] 0x2b2:0xb DW_TAG_formal_parameter
	.ascii	 "dim"                  # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	95                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x2bd:0x9 DW_TAG_variable
	.byte	105                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	97                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x2c6:0x9 DW_TAG_variable
	.byte	106                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	97                      # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	0                       # End Of Children Mark
	.byte	17                      # Abbrev [17] 0x2d0:0x56 DW_TAG_subprogram
	.long	806                     # DW_AT_sibling
	.ascii	 "check_matrix"         # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	109                     # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.byte	8                       # Abbrev [8] 0x2e9:0xb DW_TAG_formal_parameter
	.ascii	 "dim"                  # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	108                     # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x2f4:0x9 DW_TAG_variable
	.byte	105                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	110                     # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x2fd:0x9 DW_TAG_variable
	.byte	106                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	110                     # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x306:0x9 DW_TAG_variable
	.byte	107                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	110                     # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x30f:0xd DW_TAG_variable
	.ascii	 "error"                # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	111                     # DW_AT_decl_line
	.long	658                     # DW_AT_type
	.byte	10                      # Abbrev [10] 0x31c:0x9 DW_TAG_variable
	.byte	101                     # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	116                     # DW_AT_decl_line
	.long	109                     # DW_AT_type
	.byte	0                       # End Of Children Mark
	.byte	4                       # Abbrev [4] 0x326:0x11 DW_TAG_array_type
	.long	823                     # DW_AT_sibling
	.long	109                     # DW_AT_type
	.byte	5                       # Abbrev [5] 0x32f:0x7 DW_TAG_subrange_type
	.long	119                     # DW_AT_type
	.short	999                     # DW_AT_upper_bound
	.byte	0                       # End Of Children Mark
	.byte	18                      # Abbrev [18] 0x337:0x6 DW_TAG_pointer_type
	.long	806                     # DW_AT_type
	.byte	8                       # DW_AT_byte_size
	.byte	18                      # Abbrev [18] 0x33d:0x6 DW_TAG_pointer_type
	.long	122                     # DW_AT_type
	.byte	8                       # DW_AT_byte_size
	.byte	19                      # Abbrev [19] 0x343:0x5d DW_TAG_structure_type
	.long	928                     # DW_AT_sibling
	.byte	40                      # DW_AT_byte_size
	.byte	20                      # Abbrev [20] 0x349:0xe DW_TAG_member
	.ascii	 "id"                   # DW_AT_name
	.byte	0
	.long	658                     # DW_AT_type
	.byte	1                       # DW_AT_decl_file
	.byte	17                      # DW_AT_decl_line
	.byte	2                       # DW_AT_data_member_location
	.byte	35
	.byte	0
	.byte	1                       # DW_AT_accessibility
                                        # DW_ACCESS_public
	.byte	20                      # Abbrev [20] 0x357:0x12 DW_TAG_member
	.ascii	 "noproc"               # DW_AT_name
	.byte	0
	.long	658                     # DW_AT_type
	.byte	1                       # DW_AT_decl_file
	.byte	18                      # DW_AT_decl_line
	.byte	2                       # DW_AT_data_member_location
	.byte	35
	.byte	4
	.byte	1                       # DW_AT_accessibility
                                        # DW_ACCESS_public
	.byte	20                      # Abbrev [20] 0x369:0xf DW_TAG_member
	.ascii	 "dim"                  # DW_AT_name
	.byte	0
	.long	658                     # DW_AT_type
	.byte	1                       # DW_AT_decl_file
	.byte	19                      # DW_AT_decl_line
	.byte	2                       # DW_AT_data_member_location
	.byte	35
	.byte	8
	.byte	1                       # DW_AT_accessibility
                                        # DW_ACCESS_public
	.byte	20                      # Abbrev [20] 0x378:0xd DW_TAG_member
	.byte	97                      # DW_AT_name
	.byte	0
	.long	829                     # DW_AT_type
	.byte	1                       # DW_AT_decl_file
	.byte	20                      # DW_AT_decl_line
	.byte	2                       # DW_AT_data_member_location
	.byte	35
	.byte	16
	.byte	1                       # DW_AT_accessibility
                                        # DW_ACCESS_public
	.byte	20                      # Abbrev [20] 0x385:0xd DW_TAG_member
	.byte	98                      # DW_AT_name
	.byte	0
	.long	829                     # DW_AT_type
	.byte	1                       # DW_AT_decl_file
	.byte	20                      # DW_AT_decl_line
	.byte	2                       # DW_AT_data_member_location
	.byte	35
	.byte	24
	.byte	1                       # DW_AT_accessibility
                                        # DW_ACCESS_public
	.byte	20                      # Abbrev [20] 0x392:0xd DW_TAG_member
	.byte	99                      # DW_AT_name
	.byte	0
	.long	829                     # DW_AT_type
	.byte	1                       # DW_AT_decl_file
	.byte	20                      # DW_AT_decl_line
	.byte	2                       # DW_AT_data_member_location
	.byte	35
	.byte	32
	.byte	1                       # DW_AT_accessibility
                                        # DW_ACCESS_public
	.byte	0                       # End Of Children Mark
	.byte	21                      # Abbrev [21] 0x3a0:0xa DW_TAG_typedef
	.long	835                     # DW_AT_type
	.ascii	 "parm"                 # DW_AT_name
	.byte	0
	.byte	18                      # Abbrev [18] 0x3aa:0x6 DW_TAG_pointer_type
	.long	928                     # DW_AT_type
	.byte	8                       # DW_AT_byte_size
	.byte	2                       # Abbrev [2] 0x3b0:0x8 DW_TAG_base_type
	.ascii	 "char"                 # DW_AT_name
	.byte	0
	.byte	6                       # DW_AT_encoding
	.byte	1                       # DW_AT_byte_size
	.byte	18                      # Abbrev [18] 0x3b8:0x6 DW_TAG_pointer_type
	.long	944                     # DW_AT_type
	.byte	8                       # DW_AT_byte_size
	.byte	18                      # Abbrev [18] 0x3be:0x6 DW_TAG_pointer_type
	.long	952                     # DW_AT_type
	.byte	8                       # DW_AT_byte_size
	.byte	2                       # Abbrev [2] 0x3c4:0x15 DW_TAG_base_type
	.ascii	 "long unsigned int"    # DW_AT_name
	.byte	0
	.byte	7                       # DW_AT_encoding
	.byte	8                       # DW_AT_byte_size
	.byte	21                      # Abbrev [21] 0x3d9:0xf DW_TAG_typedef
	.long	964                     # DW_AT_type
	.ascii	 "pthread_t"            # DW_AT_name
	.byte	0
	.byte	18                      # Abbrev [18] 0x3e8:0x6 DW_TAG_pointer_type
	.long	985                     # DW_AT_type
	.byte	8                       # DW_AT_byte_size
	.byte	4                       # Abbrev [4] 0x3ee:0x10 DW_TAG_array_type
	.long	1022                    # DW_AT_sibling
	.long	944                     # DW_AT_type
	.byte	22                      # Abbrev [22] 0x3f7:0x6 DW_TAG_subrange_type
	.long	119                     # DW_AT_type
	.byte	55                      # DW_AT_upper_bound
	.byte	0                       # End Of Children Mark
	.byte	2                       # Abbrev [2] 0x3fe:0xc DW_TAG_base_type
	.ascii	 "long int"             # DW_AT_name
	.byte	0
	.byte	5                       # DW_AT_encoding
	.byte	8                       # DW_AT_byte_size
	.byte	23                      # Abbrev [23] 0x40a:0x2c DW_TAG_union_type
	.long	1078                    # DW_AT_sibling
	.byte	56                      # DW_AT_byte_size
	.byte	20                      # Abbrev [20] 0x410:0x12 DW_TAG_member
	.ascii	 "__size"               # DW_AT_name
	.byte	0
	.long	1006                    # DW_AT_type
	.byte	2                       # DW_AT_decl_file
	.byte	55                      # DW_AT_decl_line
	.byte	2                       # DW_AT_data_member_location
	.byte	35
	.byte	0
	.byte	1                       # DW_AT_accessibility
                                        # DW_ACCESS_public
	.byte	20                      # Abbrev [20] 0x422:0x13 DW_TAG_member
	.ascii	 "__align"              # DW_AT_name
	.byte	0
	.long	1022                    # DW_AT_type
	.byte	2                       # DW_AT_decl_file
	.byte	56                      # DW_AT_decl_line
	.byte	2                       # DW_AT_data_member_location
	.byte	35
	.byte	0
	.byte	1                       # DW_AT_accessibility
                                        # DW_ACCESS_public
	.byte	0                       # End Of Children Mark
	.byte	21                      # Abbrev [21] 0x436:0x14 DW_TAG_typedef
	.long	1034                    # DW_AT_type
	.ascii	 "pthread_attr_t"       # DW_AT_name
	.byte	0
	.byte	0                       # End Of Children Mark
.Linfo_end1:
	.section	.debug_abbrev,"",@progbits
.Labbrev_begin:
	.byte	1                       # Abbreviation Code
	.byte	17                      # DW_TAG_compile_unit
	.byte	1                       # DW_CHILDREN_yes
	.byte	37                      # DW_AT_producer
	.byte	8                       # DW_FORM_string
	.byte	19                      # DW_AT_language
	.byte	5                       # DW_FORM_data2
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	82                      # DW_AT_entry_pc
	.byte	1                       # DW_FORM_addr
	.byte	16                      # DW_AT_stmt_list
	.byte	6                       # DW_FORM_data4
	.byte	27                      # DW_AT_comp_dir
	.byte	8                       # DW_FORM_string
	.ascii	 "\341\177"             # DW_AT_APPLE_optimized
	.byte	12                      # DW_FORM_flag
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	2                       # Abbreviation Code
	.byte	36                      # DW_TAG_base_type
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	62                      # DW_AT_encoding
	.byte	11                      # DW_FORM_data1
	.byte	11                      # DW_AT_byte_size
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	3                       # Abbreviation Code
	.byte	36                      # DW_TAG_base_type
	.byte	0                       # DW_CHILDREN_no
	.byte	11                      # DW_AT_byte_size
	.byte	11                      # DW_FORM_data1
	.byte	62                      # DW_AT_encoding
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	4                       # Abbreviation Code
	.byte	1                       # DW_TAG_array_type
	.byte	1                       # DW_CHILDREN_yes
	.byte	1                       # DW_AT_sibling
	.byte	19                      # DW_FORM_ref4
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	5                       # Abbreviation Code
	.byte	33                      # DW_TAG_subrange_type
	.byte	0                       # DW_CHILDREN_no
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	47                      # DW_AT_upper_bound
	.byte	5                       # DW_FORM_data2
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	6                       # Abbreviation Code
	.byte	52                      # DW_TAG_variable
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	63                      # DW_AT_external
	.byte	12                      # DW_FORM_flag
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	2                       # DW_AT_location
	.byte	10                      # DW_FORM_block1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	7                       # Abbreviation Code
	.byte	46                      # DW_TAG_subprogram
	.byte	1                       # DW_CHILDREN_yes
	.byte	1                       # DW_AT_sibling
	.byte	19                      # DW_FORM_ref4
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	39                      # DW_AT_prototyped
	.byte	12                      # DW_FORM_flag
	.byte	63                      # DW_AT_external
	.byte	12                      # DW_FORM_flag
	.byte	32                      # DW_AT_inline
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	8                       # Abbreviation Code
	.byte	5                       # DW_TAG_formal_parameter
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	9                       # Abbreviation Code
	.byte	11                      # DW_TAG_lexical_block
	.byte	1                       # DW_CHILDREN_yes
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	10                      # Abbreviation Code
	.byte	52                      # DW_TAG_variable
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	11                      # Abbreviation Code
	.byte	46                      # DW_TAG_subprogram
	.byte	1                       # DW_CHILDREN_yes
	.byte	1                       # DW_AT_sibling
	.byte	19                      # DW_FORM_ref4
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	39                      # DW_AT_prototyped
	.byte	12                      # DW_FORM_flag
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	63                      # DW_AT_external
	.byte	12                      # DW_FORM_flag
	.byte	17                      # DW_AT_low_pc
	.byte	1                       # DW_FORM_addr
	.byte	18                      # DW_AT_high_pc
	.byte	1                       # DW_FORM_addr
	.byte	64                      # DW_AT_frame_base
	.byte	10                      # DW_FORM_block1
	.ascii	 "\347\177"             # DW_AT_APPLE_omit_frame_ptr
	.byte	12                      # DW_FORM_flag
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	12                      # Abbreviation Code
	.byte	5                       # DW_TAG_formal_parameter
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	2                       # DW_AT_location
	.byte	6                       # DW_FORM_data4
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	13                      # Abbreviation Code
	.byte	11                      # DW_TAG_lexical_block
	.byte	1                       # DW_CHILDREN_yes
	.byte	17                      # DW_AT_low_pc
	.byte	1                       # DW_FORM_addr
	.byte	18                      # DW_AT_high_pc
	.byte	1                       # DW_FORM_addr
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	14                      # Abbreviation Code
	.byte	29                      # DW_TAG_inlined_subroutine
	.byte	0                       # DW_CHILDREN_no
	.byte	49                      # DW_AT_abstract_origin
	.byte	19                      # DW_FORM_ref4
	.byte	85                      # DW_AT_ranges
	.byte	6                       # DW_FORM_data4
	.byte	88                      # DW_AT_call_file
	.byte	11                      # DW_FORM_data1
	.byte	89                      # DW_AT_call_line
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	15                      # Abbreviation Code
	.byte	15                      # DW_TAG_pointer_type
	.byte	0                       # DW_CHILDREN_no
	.byte	11                      # DW_AT_byte_size
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	16                      # Abbreviation Code
	.byte	52                      # DW_TAG_variable
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	28                      # DW_AT_const_value
	.byte	10                      # DW_FORM_block1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	17                      # Abbreviation Code
	.byte	46                      # DW_TAG_subprogram
	.byte	1                       # DW_CHILDREN_yes
	.byte	1                       # DW_AT_sibling
	.byte	19                      # DW_FORM_ref4
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	63                      # DW_AT_external
	.byte	12                      # DW_FORM_flag
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	18                      # Abbreviation Code
	.byte	15                      # DW_TAG_pointer_type
	.byte	0                       # DW_CHILDREN_no
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	11                      # DW_AT_byte_size
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	19                      # Abbreviation Code
	.byte	19                      # DW_TAG_structure_type
	.byte	1                       # DW_CHILDREN_yes
	.byte	1                       # DW_AT_sibling
	.byte	19                      # DW_FORM_ref4
	.byte	11                      # DW_AT_byte_size
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	20                      # Abbreviation Code
	.byte	13                      # DW_TAG_member
	.byte	0                       # DW_CHILDREN_no
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	58                      # DW_AT_decl_file
	.byte	11                      # DW_FORM_data1
	.byte	59                      # DW_AT_decl_line
	.byte	11                      # DW_FORM_data1
	.byte	56                      # DW_AT_data_member_location
	.byte	10                      # DW_FORM_block1
	.byte	50                      # DW_AT_accessibility
	.byte	12                      # DW_FORM_flag
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	21                      # Abbreviation Code
	.byte	22                      # DW_TAG_typedef
	.byte	0                       # DW_CHILDREN_no
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	3                       # DW_AT_name
	.byte	8                       # DW_FORM_string
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	22                      # Abbreviation Code
	.byte	33                      # DW_TAG_subrange_type
	.byte	0                       # DW_CHILDREN_no
	.byte	73                      # DW_AT_type
	.byte	19                      # DW_FORM_ref4
	.byte	47                      # DW_AT_upper_bound
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	23                      # Abbreviation Code
	.byte	23                      # DW_TAG_union_type
	.byte	1                       # DW_CHILDREN_yes
	.byte	1                       # DW_AT_sibling
	.byte	19                      # DW_FORM_ref4
	.byte	11                      # DW_AT_byte_size
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	0                       # EOM(3)
.Labbrev_end:
	.section	.debug_pubnames,"",@progbits
.Lset3 = .Lpubnames_end1-.Lpubnames_begin1 # Length of Public Names Info
	.long	.Lset3
.Lpubnames_begin1:
	.short	2                       # DWARF Version
	.long	.Linfo_begin1           # Offset of Compilation Unit Info
.Lset4 = .Linfo_end1-.Linfo_begin1      # Compilation Unit Length
	.long	.Lset4
	.long	146                     # DIE offset
	.asciz	 "a"                    # External Name
	.long	166                     # DIE offset
	.asciz	 "b"                    # External Name
	.long	186                     # DIE offset
	.asciz	 "c"                    # External Name
	.long	665                     # DIE offset
	.asciz	 "print_matrix"         # External Name
	.long	418                     # DIE offset
	.asciz	 "main"                 # External Name
	.long	720                     # DIE offset
	.asciz	 "check_matrix"         # External Name
	.long	206                     # DIE offset
	.asciz	 "mm"                   # External Name
	.long	323                     # DIE offset
	.asciz	 "worker"               # External Name
	.long	0                       # End Mark
.Lpubnames_end1:
	.section	.debug_pubtypes,"",@progbits
.Lset5 = .Lpubtypes_end1-.Lpubtypes_begin1 # Length of Public Types Info
	.long	.Lset5
.Lpubtypes_begin1:
	.short	2                       # DWARF Version
	.long	.Linfo_begin1           # Offset of Compilation Unit Info
.Lset6 = .Linfo_end1-.Linfo_begin1      # Compilation Unit Length
	.long	.Lset6
	.long	0                       # End Mark
.Lpubtypes_end1:
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
	.quad	.Lfunc_begin0
	.quad	.Ltmp11
.Lset7 = .Ltmp59-.Ltmp58                # Loc expr size
	.short	.Lset7
.Ltmp58:
	.byte	85                      # DW_OP_reg5
.Ltmp59:
	.quad	0
	.quad	0
.Ldebug_loc3:
	.quad	.Lfunc_begin1
	.quad	.Ltmp43
.Lset8 = .Ltmp61-.Ltmp60                # Loc expr size
	.short	.Lset8
.Ltmp60:
	.byte	85                      # DW_OP_reg5
.Ltmp61:
	.quad	0
	.quad	0
.Ldebug_loc6:
	.quad	.Lfunc_begin1
	.quad	.Ltmp44
.Lset9 = .Ltmp63-.Ltmp62                # Loc expr size
	.short	.Lset9
.Ltmp62:
	.byte	84                      # DW_OP_reg4
.Ltmp63:
	.quad	.Ltmp53
	.quad	.Ltmp54
.Lset10 = .Ltmp65-.Ltmp64               # Loc expr size
	.short	.Lset10
.Ltmp64:
	.byte	84                      # DW_OP_reg4
.Ltmp65:
	.quad	0
	.quad	0
.Ldebug_loc10:
	.section	.debug_aranges,"",@progbits
	.section	.debug_ranges,"",@progbits
	.quad	.Ltmp8
	.quad	.Ltmp9
	.quad	.Ltmp10
	.quad	.Ltmp12
	.quad	0
	.quad	0
	.section	.debug_macinfo,"",@progbits

	.section	".note.GNU-stack","",@progbits
