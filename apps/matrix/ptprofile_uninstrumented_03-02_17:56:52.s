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
	.type	mm,@function
mm:                                     # @mm
.Ltmp5:
	.cfi_startproc
.Lfunc_begin0:
	.loc	1 23 0                  # matrix.c:23:0
# BB#0:                                 # %entry
	.loc	1 30 26 prologue_end    # matrix.c:30:26
	pushq	%rbp
.Ltmp6:
	.cfi_def_cfa_offset 16
	pushq	%r15
.Ltmp7:
	.cfi_def_cfa_offset 24
	pushq	%r14
.Ltmp8:
	.cfi_def_cfa_offset 32
	pushq	%rbx
.Ltmp9:
	.cfi_def_cfa_offset 40
.Ltmp10:
	.cfi_offset %rbx, -40
.Ltmp11:
	.cfi_offset %r14, -32
.Ltmp12:
	.cfi_offset %r15, -24
.Ltmp13:
	.cfi_offset %rbp, -16
	movslq	%edi, %rax
	imulq	$8000, %rax, %r11       # imm = 0x1F40
	addq	%rcx, %r11
	movslq	%esi, %rax
.Ltmp14:
	.loc	1 27 3                  # matrix.c:27:3
	imulq	$8000, %rax, %r10       # imm = 0x1F40
	jmp	.LBB0_1
	.align	16, 0x90
.LBB0_8:                                # %for.end17
                                        #   in Loop: Header=BB0_1 Depth=1
	.loc	1 35 3                  # matrix.c:35:3
.Ltmp15:
	addq	%r10, %r11
	.loc	1 34 5                  # matrix.c:34:5
	addl	%esi, %edi
.Ltmp16:
.LBB0_1:                                # %while.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_3 Depth 2
                                        #       Child Loop BB0_5 Depth 3
	.loc	1 27 3                  # matrix.c:27:3
	cmpl	%edx, %edi
	jge	.LBB0_9
# BB#2:                                 # %for.cond.preheader
                                        #   in Loop: Header=BB0_1 Depth=1
	.loc	1 31 2                  # matrix.c:31:2
.Ltmp17:
	movslq	%edi, %r14
	xorl	%eax, %eax
	movq	%r8, %r15
	jmp	.LBB0_3
	.align	16, 0x90
.LBB0_6:                                # %for.inc
                                        #   in Loop: Header=BB0_5 Depth=3
	movsd	(%rcx), %xmm1
	mulsd	(%rbx), %xmm1
	addsd	%xmm1, %xmm0
	.loc	1 30 26                 # matrix.c:30:26
	addq	$8, %rcx
	incl	%ebp
	addq	$8000, %rbx             # imm = 0x1F40
.LBB0_5:                                # %for.cond2
                                        #   Parent Loop BB0_1 Depth=1
                                        #     Parent Loop BB0_3 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	.loc	1 30 12                 # matrix.c:30:12
	cmpl	%edx, %ebp
	jl	.LBB0_6
.Ltmp18:
# BB#7:                                 # %for.inc15
                                        #   in Loop: Header=BB0_3 Depth=2
	.loc	1 32 7                  # matrix.c:32:7
	imulq	$8000, %r14, %rcx       # imm = 0x1F40
	addq	%r9, %rcx
	movsd	%xmm0, (%rcx,%rax,8)
.Ltmp19:
	.loc	1 28 24                 # matrix.c:28:24
	addq	$8, %r15
	incl	%eax
.LBB0_3:                                # %for.cond
                                        #   Parent Loop BB0_1 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB0_5 Depth 3
	.loc	1 28 10                 # matrix.c:28:10
	cmpl	%edx, %eax
	jge	.LBB0_8
# BB#4:                                 # %for.body
                                        #   in Loop: Header=BB0_3 Depth=2
	.loc	1 31 2                  # matrix.c:31:2
.Ltmp20:
	movslq	%eax, %rax
	xorl	%ebp, %ebp
	pxor	%xmm0, %xmm0
.Ltmp21:
	.loc	1 35 3                  # matrix.c:35:3
	movq	%r11, %rcx
	.loc	1 28 24                 # matrix.c:28:24
.Ltmp22:
	movq	%r15, %rbx
	jmp	.LBB0_5
.Ltmp23:
.LBB0_9:                                # %while.end
	.loc	1 36 1                  # matrix.c:36:1
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
.Ltmp24:
.Ltmp25:
	.size	mm, .Ltmp25-mm
.Lfunc_end0:
.Ltmp26:
	.cfi_endproc
.Leh_func_end0:

	.align	16, 0x90
	.type	worker,@function
worker:                                 # @worker
.Ltmp28:
	.cfi_startproc
.Lfunc_begin1:
	.loc	1 38 0                  # matrix.c:38:0
# BB#0:                                 # %entry
	.loc	1 40 3 prologue_end     # matrix.c:40:3
	pushq	%rax
.Ltmp29:
	.cfi_def_cfa_offset 16
	movq	32(%rdi), %r9
	movq	24(%rdi), %r8
	movq	16(%rdi), %rcx
	movl	8(%rdi), %edx
	movl	(%rdi), %eax
	movl	4(%rdi), %esi
	movl	%eax, %edi
	callq	mm
	xorl	%eax, %eax
	.loc	1 41 3                  # matrix.c:41:3
	popq	%rdx
	ret
.Ltmp30:
.Ltmp31:
	.size	worker, .Ltmp31-worker
.Lfunc_end1:
.Ltmp32:
	.cfi_endproc
.Leh_func_end1:

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
.Ltmp40:
	.cfi_startproc
.Lfunc_begin2:
	.loc	1 45 0                  # matrix.c:45:0
# BB#0:                                 # %entry
	pushq	%rbp
.Ltmp41:
	.cfi_def_cfa_offset 16
	pushq	%r15
.Ltmp42:
	.cfi_def_cfa_offset 24
	pushq	%r14
.Ltmp43:
	.cfi_def_cfa_offset 32
	pushq	%r13
.Ltmp44:
	.cfi_def_cfa_offset 40
	pushq	%r12
.Ltmp45:
	.cfi_def_cfa_offset 48
	pushq	%rbx
.Ltmp46:
	.cfi_def_cfa_offset 56
	subq	$72, %rsp
.Ltmp47:
	.cfi_def_cfa_offset 128
.Ltmp48:
	.cfi_offset %rbx, -56
.Ltmp49:
	.cfi_offset %r12, -48
.Ltmp50:
	.cfi_offset %r13, -40
.Ltmp51:
	.cfi_offset %r14, -32
.Ltmp52:
	.cfi_offset %r15, -24
.Ltmp53:
	.cfi_offset %rbp, -16
	xorl	%r8d, %r8d
	xorl	%ebp, %ebp
	xorl	%edx, %edx
	jmp	.LBB2_1
	.align	16, 0x90
.LBB2_3:                                # %for.inc
                                        #   in Loop: Header=BB2_2 Depth=2
	.loc	1 54 2 prologue_end     # matrix.c:54:2
.Ltmp54:
	leal	(%rdx,%rax), %ebx
	cvtsi2sd	%ebx, %xmm0
	movsd	%xmm0, a(%rcx)
	.loc	1 55 2                  # matrix.c:55:2
	movsd	%xmm0, b(%rcx)
.Ltmp55:
	.loc	1 53 27                 # matrix.c:53:27
	incl	%eax
	addq	$8, %rcx
.LBB2_2:                                # %for.cond1
                                        #   Parent Loop BB2_1 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	.loc	1 53 10                 # matrix.c:53:10
	cmpl	$999, %eax              # imm = 0x3E7
	jle	.LBB2_3
.Ltmp56:
# BB#4:                                 # %for.inc12
                                        #   in Loop: Header=BB2_1 Depth=1
	.loc	1 52 25                 # matrix.c:52:25
	addq	$8000, %rbp             # imm = 0x1F40
	incl	%edx
.LBB2_1:                                # %for.cond
                                        # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_2 Depth 2
	.loc	1 52 8                  # matrix.c:52:8
	cmpl	$999, %edx              # imm = 0x3E7
	.loc	1 52 25                 # matrix.c:52:25
	movq	%rbp, %rcx
	movl	%r8d, %eax
	jle	.LBB2_2
.Ltmp57:
# BB#5:                                 # %for.end14
	.loc	1 58 3                  # matrix.c:58:3
	cmpl	$2, %edi
	jne	.LBB2_12
# BB#6:                                 # %if.end
	.loc	1 62 7                  # matrix.c:62:7
	movq	8(%rsi), %rdi
	xorb	%al, %al
	callq	atoi
	.loc	1 71 27                 # matrix.c:71:27
	movslq	%eax, %rbp
	leaq	(,%rbp,8), %rbx
	movq	%rbx, %rdi
	callq	malloc
	movq	%rax, %r12
	leaq	16(%rsp), %r15
	.loc	1 72 3                  # matrix.c:72:3
	movq	%r15, %rdi
	callq	pthread_attr_init
	.loc	1 73 15                 # matrix.c:73:15
	leaq	(%rbx,%rbx,4), %rdi
	callq	malloc
	movq	%rax, 8(%rsp)           # 8-byte Spill
	xorl	%r14d, %r14d
	.loc	1 75 22                 # matrix.c:75:22
.Ltmp58:
	movq	%r12, %r13
	movq	%rax, %rbx
	jmp	.LBB2_7
.Ltmp59:
.LBB2_12:                               # %if.then
	.loc	1 59 5                  # matrix.c:59:5
	movq	(%rsi), %rsi
	movl	$.L.str, %edi
	xorb	%al, %al
	callq	printf
	movl	$1, %edi
	.loc	1 60 5                  # matrix.c:60:5
	callq	exit
.Ltmp60:
	.align	16, 0x90
.LBB2_13:                               # %for.inc46
                                        #   in Loop: Header=BB2_7 Depth=1
	.loc	1 76 5                  # matrix.c:76:5
	movl	%r14d, (%rbx)
	.loc	1 77 5                  # matrix.c:77:5
	movl	%ebp, 4(%rbx)
	.loc	1 78 5                  # matrix.c:78:5
	movl	$1000, 8(%rbx)          # imm = 0x3E8
	.loc	1 79 5                  # matrix.c:79:5
	movq	$a, 16(%rbx)
	.loc	1 80 5                  # matrix.c:80:5
	movq	$b, 24(%rbx)
	.loc	1 81 5                  # matrix.c:81:5
	movq	$c, 32(%rbx)
	.loc	1 82 5                  # matrix.c:82:5
	movq	%r13, %rdi
	movq	%r15, %rsi
	movl	$worker, %edx
	movq	%rbx, %rcx
	callq	pthread_create
.Ltmp61:
	.loc	1 75 22                 # matrix.c:75:22
	addq	$8, %r13
	incl	%r14d
	addq	$40, %rbx
.LBB2_7:                                # %for.cond26
                                        # =>This Inner Loop Header: Depth=1
	.loc	1 75 8                  # matrix.c:75:8
	cmpl	%ebp, %r14d
	jl	.LBB2_13
.Ltmp62:
# BB#8:
	xorl	%ebx, %ebx
	jmp	.LBB2_9
	.align	16, 0x90
.LBB2_10:                               # %for.inc56
                                        #   in Loop: Header=BB2_9 Depth=1
	.loc	1 86 5                  # matrix.c:86:5
.Ltmp63:
	movq	(%r12,%rbx,8), %rdi
	xorl	%esi, %esi
	callq	pthread_join
	.loc	1 85 22                 # matrix.c:85:22
	incq	%rbx
.Ltmp64:
.LBB2_9:                                # %for.cond49
                                        # =>This Inner Loop Header: Depth=1
	cmpl	%ebp, %ebx
	jl	.LBB2_10
# BB#11:                                # %for.end58
	.loc	1 90 3                  # matrix.c:90:3
	movq	8(%rsp), %rdi           # 8-byte Reload
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
.Ltmp65:
.Ltmp66:
	.size	main, .Ltmp66-main
.Lfunc_end2:
.Ltmp67:
	.cfi_endproc
.Leh_func_end2:

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
	.long	348                     # Length of Compilation Unit Info
	.short	2                       # DWARF version number
	.long	.Labbrev_begin          # Offset Into Abbrev. Section
	.byte	8                       # Address Size (in bytes)
	.byte	1                       # Abbrev [1] 0xb:0x155 DW_TAG_compile_unit
	.ascii	 "clang version 3.0 (tags/RELEASE_30/final)" # DW_AT_producer
	.byte	0
	.short	12                      # DW_AT_language
	.ascii	 "matrix.c"             # DW_AT_name
	.byte	0
	.quad	0                       # DW_AT_entry_pc
	.long	.Lsection_line          # DW_AT_stmt_list
	.ascii	 "/home/kuitang/CYG2/apps/matrix" # DW_AT_comp_dir
	.byte	0
	.byte	2                       # Abbrev [2] 0x6c:0xa DW_TAG_base_type
	.ascii	 "double"               # DW_AT_name
	.byte	0
	.byte	4                       # DW_AT_encoding
	.byte	8                       # DW_AT_byte_size
	.byte	3                       # Abbrev [3] 0x76:0x3 DW_TAG_base_type
	.byte	4                       # DW_AT_byte_size
	.byte	5                       # DW_AT_encoding
	.byte	4                       # Abbrev [4] 0x79:0x18 DW_TAG_array_type
	.long	145                     # DW_AT_sibling
	.long	108                     # DW_AT_type
	.byte	5                       # Abbrev [5] 0x82:0x7 DW_TAG_subrange_type
	.long	118                     # DW_AT_type
	.short	999                     # DW_AT_upper_bound
	.byte	5                       # Abbrev [5] 0x89:0x7 DW_TAG_subrange_type
	.long	118                     # DW_AT_type
	.short	999                     # DW_AT_upper_bound
	.byte	0                       # End Of Children Mark
	.byte	6                       # Abbrev [6] 0x91:0x14 DW_TAG_variable
	.byte	97                      # DW_AT_name
	.byte	0
	.long	121                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.byte	1                       # DW_AT_decl_file
	.byte	12                      # DW_AT_decl_line
	.byte	9                       # DW_AT_location
	.byte	3
	.quad	a
	.byte	6                       # Abbrev [6] 0xa5:0x14 DW_TAG_variable
	.byte	98                      # DW_AT_name
	.byte	0
	.long	121                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.byte	1                       # DW_AT_decl_file
	.byte	13                      # DW_AT_decl_line
	.byte	9                       # DW_AT_location
	.byte	3
	.quad	b
	.byte	6                       # Abbrev [6] 0xb9:0x14 DW_TAG_variable
	.byte	99                      # DW_AT_name
	.byte	0
	.long	121                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.byte	1                       # DW_AT_decl_file
	.byte	14                      # DW_AT_decl_line
	.byte	9                       # DW_AT_location
	.byte	3
	.quad	c
	.byte	7                       # Abbrev [7] 0xcd:0x1b DW_TAG_subprogram
	.ascii	 "mm"                   # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	23                      # DW_AT_decl_line
	.byte	1                       # DW_AT_prototyped
	.byte	1                       # DW_AT_external
	.quad	.Lfunc_begin0           # DW_AT_low_pc
	.quad	.Lfunc_end0             # DW_AT_high_pc
	.byte	1                       # DW_AT_frame_base
	.byte	87
	.byte	1                       # DW_AT_APPLE_omit_frame_ptr
	.byte	8                       # Abbrev [8] 0xe8:0x23 DW_TAG_subprogram
	.ascii	 "worker"               # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	38                      # DW_AT_decl_line
	.byte	1                       # DW_AT_prototyped
	.long	267                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.quad	.Lfunc_begin1           # DW_AT_low_pc
	.quad	.Lfunc_end1             # DW_AT_high_pc
	.byte	1                       # DW_AT_frame_base
	.byte	87
	.byte	1                       # DW_AT_APPLE_omit_frame_ptr
	.byte	9                       # Abbrev [9] 0x10b:0x2 DW_TAG_pointer_type
	.byte	8                       # DW_AT_byte_size
	.byte	8                       # Abbrev [8] 0x10d:0x21 DW_TAG_subprogram
	.ascii	 "main"                 # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	45                      # DW_AT_decl_line
	.byte	1                       # DW_AT_prototyped
	.long	302                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.quad	.Lfunc_begin2           # DW_AT_low_pc
	.quad	.Lfunc_end2             # DW_AT_high_pc
	.byte	1                       # DW_AT_frame_base
	.byte	87
	.byte	1                       # DW_AT_APPLE_omit_frame_ptr
	.byte	2                       # Abbrev [2] 0x12e:0x7 DW_TAG_base_type
	.ascii	 "int"                  # DW_AT_name
	.byte	0
	.byte	5                       # DW_AT_encoding
	.byte	4                       # DW_AT_byte_size
	.byte	10                      # Abbrev [10] 0x135:0x15 DW_TAG_subprogram
	.ascii	 "print_matrix"         # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	96                      # DW_AT_decl_line
	.long	302                     # DW_AT_type
	.byte	1                       # DW_AT_external
	.byte	10                      # Abbrev [10] 0x14a:0x15 DW_TAG_subprogram
	.ascii	 "check_matrix"         # DW_AT_name
	.byte	0
	.byte	1                       # DW_AT_decl_file
	.byte	109                     # DW_AT_decl_line
	.long	302                     # DW_AT_type
	.byte	1                       # DW_AT_external
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
	.byte	0                       # DW_CHILDREN_no
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
	.byte	8                       # Abbreviation Code
	.byte	46                      # DW_TAG_subprogram
	.byte	0                       # DW_CHILDREN_no
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
	.byte	9                       # Abbreviation Code
	.byte	15                      # DW_TAG_pointer_type
	.byte	0                       # DW_CHILDREN_no
	.byte	11                      # DW_AT_byte_size
	.byte	11                      # DW_FORM_data1
	.byte	0                       # EOM(1)
	.byte	0                       # EOM(2)
	.byte	10                      # Abbreviation Code
	.byte	46                      # DW_TAG_subprogram
	.byte	0                       # DW_CHILDREN_no
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
	.byte	0                       # EOM(3)
.Labbrev_end:
	.section	.debug_pubnames,"",@progbits
.Lset0 = .Lpubnames_end1-.Lpubnames_begin1 # Length of Public Names Info
	.long	.Lset0
.Lpubnames_begin1:
	.short	2                       # DWARF Version
	.long	.Linfo_begin1           # Offset of Compilation Unit Info
.Lset1 = .Linfo_end1-.Linfo_begin1      # Compilation Unit Length
	.long	.Lset1
	.long	145                     # DIE offset
	.asciz	 "a"                    # External Name
	.long	165                     # DIE offset
	.asciz	 "b"                    # External Name
	.long	185                     # DIE offset
	.asciz	 "c"                    # External Name
	.long	309                     # DIE offset
	.asciz	 "print_matrix"         # External Name
	.long	269                     # DIE offset
	.asciz	 "main"                 # External Name
	.long	330                     # DIE offset
	.asciz	 "check_matrix"         # External Name
	.long	205                     # DIE offset
	.asciz	 "mm"                   # External Name
	.long	232                     # DIE offset
	.asciz	 "worker"               # External Name
	.long	0                       # End Mark
.Lpubnames_end1:
	.section	.debug_pubtypes,"",@progbits
.Lset2 = .Lpubtypes_end1-.Lpubtypes_begin1 # Length of Public Types Info
	.long	.Lset2
.Lpubtypes_begin1:
	.short	2                       # DWARF Version
	.long	.Linfo_begin1           # Offset of Compilation Unit Info
.Lset3 = .Linfo_end1-.Linfo_begin1      # Compilation Unit Length
	.long	.Lset3
	.long	0                       # End Mark
.Lpubtypes_end1:
	.section	.debug_aranges,"",@progbits
	.section	.debug_ranges,"",@progbits
	.section	.debug_macinfo,"",@progbits

	.section	".note.GNU-stack","",@progbits
