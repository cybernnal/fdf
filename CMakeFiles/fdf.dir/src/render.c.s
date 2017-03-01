	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	_render
	.align	4, 0x90
_render:                                ## @render
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	%rdi, -8(%rbp)
	cmpl	$0, _render.w+88(%rip)
	jne	LBB0_2
## BB#1:
	leaq	_render.w(%rip), %rdi
	callq	_init_window
	movl	$1, _render.w+88(%rip)
LBB0_2:
	xorl	%esi, %esi
	movl	$8740000, %eax          ## imm = 0x855CA0
	movl	%eax, %edx
	movq	_render.w+80(%rip), %rcx
	movq	%rcx, %rdi
	callq	_memset
LBB0_3:                                 ## =>This Inner Loop Header: Depth=1
	leaq	_render.w(%rip), %rax
	addq	$8, %rax
	movq	%rax, %rdi
	callq	_SDL_PollEvent
	cmpl	$0, %eax
	je	LBB0_5
## BB#4:                                ##   in Loop: Header=BB0_3 Depth=1
	leaq	_render.w(%rip), %rax
	addq	$8, %rax
	movq	-8(%rbp), %rdi
	movq	_render.w+56(%rip), %rcx
	movq	%rsp, %rdx
	movq	%rcx, 48(%rdx)
	movq	_render.w+48(%rip), %rcx
	movq	%rcx, 40(%rdx)
	movq	_render.w+40(%rip), %rcx
	movq	%rcx, 32(%rdx)
	movq	_render.w+32(%rip), %rcx
	movq	%rcx, 24(%rdx)
	movq	_render.w+24(%rip), %rcx
	movq	%rcx, 16(%rdx)
	movq	_render.w+16(%rip), %rcx
	movq	%rcx, 8(%rdx)
	movq	_render.w+8(%rip), %rcx
	movq	%rcx, (%rdx)
	movq	%rax, -16(%rbp)         ## 8-byte Spill
	callq	_key_handler
	jmp	LBB0_3
LBB0_5:
	leaq	_render.w(%rip), %rdi
	movq	-8(%rbp), %rsi
	callq	_render_map
	xorl	%eax, %eax
	movl	%eax, %esi
	movl	$7600, %ecx             ## imm = 0x1DB0
	movq	_render.w+72(%rip), %rdi
	movq	_render.w+80(%rip), %rdx
	callq	_SDL_UpdateTexture
	xorl	%ecx, %ecx
	movl	%ecx, %edx
	movq	_render.w+64(%rip), %rdi
	movq	_render.w+72(%rip), %rsi
	movq	%rdx, -24(%rbp)         ## 8-byte Spill
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	callq	_SDL_RenderCopy
	movq	_render.w+64(%rip), %rdi
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	callq	_SDL_RenderPresent
	movl	$1, %eax
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal4,4byte_literals
	.align	2
LCPI1_0:
	.long	1092616192              ## float 10
LCPI1_1:
	.long	1036831949              ## float 0.100000001
	.section	__TEXT,__literal8,8byte_literals
	.align	3
LCPI1_2:
	.quad	4576918229304087675     ## double 0.01
LCPI1_3:
	.quad	4587366580439587226     ## double 0.050000000000000003
	.section	__TEXT,__text,regular,pure_instructions
	.align	4, 0x90
_key_handler:                           ## @key_handler
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	16(%rbp), %rax
	movq	%rdi, -8(%rbp)
	cmpl	$768, (%rax)            ## imm = 0x300
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	jne	LBB1_44
## BB#1:
	movss	LCPI1_0(%rip), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movl	$50, %eax
	movl	$1, %ecx
	movss	LCPI1_1(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm1, -12(%rbp)
	movq	-8(%rbp), %rdx
	movss	84(%rdx), %xmm1         ## xmm1 = mem[0],zero,zero,zero
	ucomiss	%xmm0, %xmm1
	cmoval	%ecx, %eax
	movl	%eax, -16(%rbp)
	movq	-24(%rbp), %rdx         ## 8-byte Reload
	cmpl	$27, 20(%rdx)
	jne	LBB1_3
## BB#2:
	leaq	L_.str(%rip), %rdi
	movq	-8(%rbp), %rax
	cvtss2sd	84(%rax), %xmm0
	movq	-8(%rbp), %rax
	movl	68(%rax), %esi
	movq	-8(%rbp), %rax
	movl	72(%rax), %edx
	movb	$1, %al
	callq	_printf
	xorl	%edi, %edi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	callq	_exit
LBB1_3:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$122, 20(%rax)
	jne	LBB1_5
## BB#4:
	movss	-12(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-8(%rbp), %rax
	addss	84(%rax), %xmm0
	movss	%xmm0, 84(%rax)
LBB1_5:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$97, 20(%rax)
	jne	LBB1_9
## BB#6:
	xorps	%xmm0, %xmm0
	movq	-8(%rbp), %rax
	movss	84(%rax), %xmm1         ## xmm1 = mem[0],zero,zero,zero
	subss	-12(%rbp), %xmm1
	ucomiss	%xmm0, %xmm1
	jbe	LBB1_8
## BB#7:
	movss	-12(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-8(%rbp), %rax
	movss	84(%rax), %xmm1         ## xmm1 = mem[0],zero,zero,zero
	subss	%xmm0, %xmm1
	movss	%xmm1, 84(%rax)
LBB1_8:
	jmp	LBB1_9
LBB1_9:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$1073741904, 20(%rax)   ## imm = 0x40000050
	jne	LBB1_11
## BB#10:
	movl	-16(%rbp), %eax
	movq	-8(%rbp), %rcx
	addl	68(%rcx), %eax
	movl	%eax, 68(%rcx)
LBB1_11:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$1073741903, 20(%rax)   ## imm = 0x4000004F
	jne	LBB1_13
## BB#12:
	movl	-16(%rbp), %eax
	movq	-8(%rbp), %rcx
	movl	68(%rcx), %edx
	subl	%eax, %edx
	movl	%edx, 68(%rcx)
LBB1_13:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$1073741905, 20(%rax)   ## imm = 0x40000051
	jne	LBB1_15
## BB#14:
	movl	-16(%rbp), %eax
	movq	-8(%rbp), %rcx
	movl	72(%rcx), %edx
	subl	%eax, %edx
	movl	%edx, 72(%rcx)
LBB1_15:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$1073741906, 20(%rax)   ## imm = 0x40000052
	jne	LBB1_17
## BB#16:
	movl	-16(%rbp), %eax
	movq	-8(%rbp), %rcx
	addl	72(%rcx), %eax
	movl	%eax, 72(%rcx)
LBB1_17:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$110, 20(%rax)
	jne	LBB1_19
## BB#18:
	movq	-8(%rbp), %rax
	movss	80(%rax), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	movq	-8(%rbp), %rax
	movss	76(%rax), %xmm1         ## xmm1 = mem[0],zero,zero,zero
	subss	%xmm0, %xmm1
	movss	%xmm1, 76(%rax)
LBB1_19:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$109, 20(%rax)
	jne	LBB1_21
## BB#20:
	movq	-8(%rbp), %rax
	movss	80(%rax), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	movq	-8(%rbp), %rax
	addss	76(%rax), %xmm0
	movss	%xmm0, 76(%rax)
LBB1_21:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$106, 20(%rax)
	jne	LBB1_23
## BB#22:
	movsd	LCPI1_2(%rip), %xmm0    ## xmm0 = mem[0],zero
	movq	-8(%rbp), %rax
	cvtss2sd	80(%rax), %xmm1
	subsd	%xmm0, %xmm1
	cvtsd2ss	%xmm1, %xmm0
	movss	%xmm0, 80(%rax)
LBB1_23:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$107, 20(%rax)
	jne	LBB1_25
## BB#24:
	movsd	LCPI1_2(%rip), %xmm0    ## xmm0 = mem[0],zero
	movq	-8(%rbp), %rax
	cvtss2sd	80(%rax), %xmm1
	addsd	%xmm0, %xmm1
	cvtsd2ss	%xmm1, %xmm0
	movss	%xmm0, 80(%rax)
LBB1_25:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$112, 20(%rax)
	jne	LBB1_27
## BB#26:
	movq	-8(%rbp), %rax
	cmpl	$0, 92(%rax)
	setne	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movq	-8(%rbp), %rax
	movl	%edx, 92(%rax)
LBB1_27:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$118, 20(%rax)
	jne	LBB1_29
## BB#28:
	movq	-8(%rbp), %rax
	movsd	112(%rax), %xmm0        ## xmm0 = mem[0],zero
	movq	-8(%rbp), %rax
	movsd	104(%rax), %xmm1        ## xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 104(%rax)
LBB1_29:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$98, 20(%rax)
	jne	LBB1_31
## BB#30:
	movq	-8(%rbp), %rax
	movsd	112(%rax), %xmm0        ## xmm0 = mem[0],zero
	movq	-8(%rbp), %rax
	addsd	104(%rax), %xmm0
	movsd	%xmm0, 104(%rax)
LBB1_31:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$103, 20(%rax)
	jne	LBB1_33
## BB#32:
	movsd	LCPI1_2(%rip), %xmm0    ## xmm0 = mem[0],zero
	movq	-8(%rbp), %rax
	movsd	112(%rax), %xmm1        ## xmm1 = mem[0],zero
	subsd	%xmm0, %xmm1
	movsd	%xmm1, 112(%rax)
LBB1_33:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$104, 20(%rax)
	jne	LBB1_35
## BB#34:
	movsd	LCPI1_2(%rip), %xmm0    ## xmm0 = mem[0],zero
	movq	-8(%rbp), %rax
	addsd	112(%rax), %xmm0
	movsd	%xmm0, 112(%rax)
LBB1_35:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$111, 20(%rax)
	jne	LBB1_37
## BB#36:
	movq	-8(%rbp), %rax
	cmpl	$0, 96(%rax)
	setne	%cl
	xorb	$-1, %cl
	andb	$1, %cl
	movzbl	%cl, %edx
	movq	-8(%rbp), %rax
	movl	%edx, 96(%rax)
LBB1_37:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$113, 20(%rax)
	jne	LBB1_39
## BB#38:
	movl	$3, %eax
	movq	-8(%rbp), %rcx
	movl	120(%rcx), %edx
	addl	$1, %edx
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	movl	%edx, %eax
	cltd
	movl	-32(%rbp), %esi         ## 4-byte Reload
	idivl	%esi
	movq	-8(%rbp), %rcx
	movl	%edx, 120(%rcx)
LBB1_39:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$119, 20(%rax)
	jne	LBB1_41
## BB#40:
	movsd	LCPI1_3(%rip), %xmm0    ## xmm0 = mem[0],zero
	movq	-8(%rbp), %rax
	cvtss2sd	124(%rax), %xmm1
	addsd	%xmm0, %xmm1
	cvtsd2ss	%xmm1, %xmm0
	movss	%xmm0, 124(%rax)
LBB1_41:
	movq	-24(%rbp), %rax         ## 8-byte Reload
	cmpl	$101, 20(%rax)
	jne	LBB1_43
## BB#42:
	movsd	LCPI1_3(%rip), %xmm0    ## xmm0 = mem[0],zero
	movq	-8(%rbp), %rax
	cvtss2sd	124(%rax), %xmm1
	subsd	%xmm0, %xmm1
	cvtsd2ss	%xmm1, %xmm0
	movss	%xmm0, 124(%rax)
LBB1_43:
	jmp	LBB1_44
LBB1_44:
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.align	4, 0x90
_render_map:                            ## @render_map
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movl	$48, %eax
	movl	%eax, %ecx
	leaq	-64(%rbp), %rdx
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, %rdi
	movq	%rcx, %rsi
	callq	_ft_bzero
	movq	-16(%rbp), %rcx
	movss	80(%rcx), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rcx
	addss	76(%rcx), %xmm0
	movss	%xmm0, 76(%rcx)
	movq	-16(%rbp), %rcx
	cmpl	$1, 96(%rcx)
	jne	LBB2_2
## BB#1:
	movq	-16(%rbp), %rax
	movsd	112(%rax), %xmm0        ## xmm0 = mem[0],zero
	movq	-16(%rbp), %rax
	addsd	104(%rax), %xmm0
	movsd	%xmm0, 104(%rax)
LBB2_2:
	movq	-16(%rbp), %rax
	movl	$0, 28(%rax)
LBB2_3:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB2_5 Depth 2
	movq	-16(%rbp), %rax
	movl	28(%rax), %ecx
	movq	-16(%rbp), %rax
	movl	36(%rax), %edx
	subl	$1, %edx
	cmpl	%edx, %ecx
	jge	LBB2_11
## BB#4:                                ##   in Loop: Header=BB2_3 Depth=1
	movq	-16(%rbp), %rax
	movl	$0, 24(%rax)
LBB2_5:                                 ##   Parent Loop BB2_3 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movq	-16(%rbp), %rax
	movl	24(%rax), %ecx
	movq	-16(%rbp), %rax
	movl	40(%rax), %edx
	subl	$1, %edx
	cmpl	%edx, %ecx
	jge	LBB2_10
## BB#6:                                ##   in Loop: Header=BB2_5 Depth=2
	movq	-16(%rbp), %rax
	cmpl	$0, 28(%rax)
	jg	LBB2_8
## BB#7:                                ##   in Loop: Header=BB2_5 Depth=2
	movq	-16(%rbp), %rax
	cmpl	$0, 24(%rax)
	jle	LBB2_9
LBB2_8:                                 ##   in Loop: Header=BB2_5 Depth=2
	movq	-16(%rbp), %rax
	movslq	24(%rax), %rax
	movq	-16(%rbp), %rcx
	movslq	28(%rcx), %rcx
	movq	-16(%rbp), %rdx
	movq	8(%rdx), %rdx
	movq	(%rdx,%rcx,8), %rcx
	movss	(%rcx,%rax,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	movss	%xmm0, 136(%rax)
LBB2_9:                                 ##   in Loop: Header=BB2_5 Depth=2
	leaq	-64(%rbp), %rdi
	movq	-16(%rbp), %rax
	movslq	24(%rax), %rax
	movq	-16(%rbp), %rcx
	movslq	28(%rcx), %rcx
	movq	-16(%rbp), %rdx
	movq	8(%rdx), %rdx
	movq	(%rdx,%rcx,8), %rcx
	movss	(%rcx,%rax,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	movss	%xmm0, 140(%rax)
	movq	-16(%rbp), %rax
	movslq	24(%rax), %rax
	movq	-16(%rbp), %rcx
	movslq	28(%rcx), %rcx
	movq	-16(%rbp), %rdx
	movq	8(%rdx), %rdx
	movq	(%rdx,%rcx,8), %rcx
	cvttss2si	(%rcx,%rax,4), %esi
	movl	%esi, -60(%rbp)
	movq	-16(%rbp), %rax
	movl	24(%rax), %esi
	addl	$1, %esi
	movslq	%esi, %rax
	movq	-16(%rbp), %rcx
	movslq	28(%rcx), %rcx
	movq	-16(%rbp), %rdx
	movq	8(%rdx), %rdx
	movq	(%rdx,%rcx,8), %rcx
	cvttss2si	(%rcx,%rax,4), %esi
	movl	%esi, -52(%rbp)
	movq	-16(%rbp), %rax
	movslq	24(%rax), %rax
	movq	-16(%rbp), %rcx
	movl	28(%rcx), %esi
	addl	$1, %esi
	movslq	%esi, %rcx
	movq	-16(%rbp), %rdx
	movq	8(%rdx), %rdx
	movq	(%rdx,%rcx,8), %rcx
	cvttss2si	(%rcx,%rax,4), %esi
	movl	%esi, -56(%rbp)
	movq	-16(%rbp), %rsi
	callq	_matrix
	movss	-44(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	68(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %edi
	movss	-40(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	72(%rax), %xmm1
	addss	%xmm1, %xmm0
	cvtsi2ssl	-60(%rbp), %xmm1
	movq	-16(%rbp), %rax
	mulss	124(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %esi
	movss	-36(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	68(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %edx
	movss	-32(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	72(%rax), %xmm1
	addss	%xmm1, %xmm0
	cvtsi2ssl	-52(%rbp), %xmm1
	movq	-16(%rbp), %rax
	mulss	124(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %ecx
	movq	-8(%rbp), %r8
	movq	-16(%rbp), %r9
	callq	_line
	movss	-44(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	68(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %edi
	movss	-40(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	72(%rax), %xmm1
	addss	%xmm1, %xmm0
	cvtsi2ssl	-60(%rbp), %xmm1
	movq	-16(%rbp), %rax
	mulss	124(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %esi
	movss	-28(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	68(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %edx
	movss	-24(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	72(%rax), %xmm1
	addss	%xmm1, %xmm0
	cvtsi2ssl	-56(%rbp), %xmm1
	movq	-16(%rbp), %rax
	mulss	124(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %ecx
	movq	-8(%rbp), %r8
	movq	-16(%rbp), %r9
	callq	_line
	movq	-16(%rbp), %rax
	movl	24(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, 24(%rax)
	jmp	LBB2_5
LBB2_10:                                ##   in Loop: Header=BB2_3 Depth=1
	leaq	-64(%rbp), %rdi
	movq	-16(%rbp), %rax
	movslq	24(%rax), %rax
	movq	-16(%rbp), %rcx
	movslq	28(%rcx), %rcx
	movq	-16(%rbp), %rdx
	movq	8(%rdx), %rdx
	movq	(%rdx,%rcx,8), %rcx
	cvttss2si	(%rcx,%rax,4), %esi
	movl	%esi, -60(%rbp)
	movq	-16(%rbp), %rax
	movslq	24(%rax), %rax
	movq	-16(%rbp), %rcx
	movl	28(%rcx), %esi
	addl	$1, %esi
	movslq	%esi, %rcx
	movq	-16(%rbp), %rdx
	movq	8(%rdx), %rdx
	movq	(%rdx,%rcx,8), %rcx
	cvttss2si	(%rcx,%rax,4), %esi
	movl	%esi, -56(%rbp)
	movq	-16(%rbp), %rsi
	callq	_matrix
	movss	-44(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	68(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %edi
	movss	-40(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	72(%rax), %xmm1
	addss	%xmm1, %xmm0
	cvtsi2ssl	-60(%rbp), %xmm1
	movq	-16(%rbp), %rax
	mulss	124(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %esi
	movss	-28(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	68(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %edx
	movss	-24(%rbp), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	cvtsi2ssl	72(%rax), %xmm1
	addss	%xmm1, %xmm0
	cvtsi2ssl	-56(%rbp), %xmm1
	movq	-16(%rbp), %rax
	mulss	124(%rax), %xmm1
	addss	%xmm1, %xmm0
	mulss	-48(%rbp), %xmm0
	cvttss2si	%xmm0, %ecx
	movq	-8(%rbp), %r8
	movq	-16(%rbp), %r9
	callq	_line
	movq	-16(%rbp), %rax
	movl	28(%rax), %ecx
	addl	$1, %ecx
	movl	%ecx, 28(%rax)
	jmp	LBB2_3
LBB2_11:
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.align	4, 0x90
_matrix:                                ## @matrix
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp9:
	.cfi_def_cfa_offset 16
Ltmp10:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp11:
	.cfi_def_cfa_register %rbp
	subq	$96, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rsi
	cvtsi2ssl	24(%rsi), %xmm0
	movq	-8(%rbp), %rsi
	movss	44(%rsi), %xmm1         ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -20(%rbp)        ## 4-byte Spill
	movaps	%xmm1, %xmm0
	callq	_mem_co
	movss	-20(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movq	-16(%rbp), %rsi
	cvtsi2ssl	28(%rsi), %xmm0
	movq	-8(%rbp), %rsi
	cvtss2sd	44(%rsi), %xmm2
	movq	-16(%rbp), %rsi
	addsd	104(%rsi), %xmm2
	cvtsd2ss	%xmm2, %xmm2
	movss	%xmm0, -24(%rbp)        ## 4-byte Spill
	movaps	%xmm2, %xmm0
	movss	%xmm1, -28(%rbp)        ## 4-byte Spill
	callq	_mem_co
	movss	-24(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movss	-28(%rbp), %xmm0        ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	addss	%xmm1, %xmm0
	movq	-8(%rbp), %rsi
	movss	%xmm0, 20(%rsi)
	movq	-16(%rbp), %rsi
	cvtsi2ssl	24(%rsi), %xmm0
	movq	-8(%rbp), %rsi
	movss	44(%rsi), %xmm1         ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -32(%rbp)        ## 4-byte Spill
	movaps	%xmm1, %xmm0
	callq	_mem_si
	movss	-32(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movq	-16(%rbp), %rsi
	cvtsi2ssl	28(%rsi), %xmm0
	movq	-8(%rbp), %rsi
	cvtss2sd	44(%rsi), %xmm2
	movq	-16(%rbp), %rsi
	addsd	104(%rsi), %xmm2
	cvtsd2ss	%xmm2, %xmm2
	movss	%xmm0, -36(%rbp)        ## 4-byte Spill
	movaps	%xmm2, %xmm0
	movss	%xmm1, -40(%rbp)        ## 4-byte Spill
	callq	_mem_si
	movss	-36(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movss	-40(%rbp), %xmm0        ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	addss	%xmm1, %xmm0
	movq	-8(%rbp), %rsi
	movss	%xmm0, 24(%rsi)
	movq	-16(%rbp), %rsi
	movl	24(%rsi), %eax
	addl	$1, %eax
	cvtsi2ssl	%eax, %xmm0
	movq	-8(%rbp), %rsi
	movss	44(%rsi), %xmm1         ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -44(%rbp)        ## 4-byte Spill
	movaps	%xmm1, %xmm0
	callq	_mem_co
	movss	-44(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movq	-16(%rbp), %rsi
	cvtsi2ssl	28(%rsi), %xmm0
	movq	-8(%rbp), %rsi
	cvtss2sd	44(%rsi), %xmm2
	movq	-16(%rbp), %rsi
	addsd	104(%rsi), %xmm2
	cvtsd2ss	%xmm2, %xmm2
	movss	%xmm0, -48(%rbp)        ## 4-byte Spill
	movaps	%xmm2, %xmm0
	movss	%xmm1, -52(%rbp)        ## 4-byte Spill
	callq	_mem_co
	movss	-48(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movss	-52(%rbp), %xmm0        ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	addss	%xmm1, %xmm0
	movq	-8(%rbp), %rsi
	movss	%xmm0, 28(%rsi)
	movq	-16(%rbp), %rsi
	movl	24(%rsi), %eax
	addl	$1, %eax
	cvtsi2ssl	%eax, %xmm0
	movq	-8(%rbp), %rsi
	movss	44(%rsi), %xmm1         ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -56(%rbp)        ## 4-byte Spill
	movaps	%xmm1, %xmm0
	callq	_mem_si
	movss	-56(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movq	-16(%rbp), %rsi
	cvtsi2ssl	28(%rsi), %xmm0
	movq	-8(%rbp), %rsi
	cvtss2sd	44(%rsi), %xmm2
	movq	-16(%rbp), %rsi
	addsd	104(%rsi), %xmm2
	cvtsd2ss	%xmm2, %xmm2
	movss	%xmm0, -60(%rbp)        ## 4-byte Spill
	movaps	%xmm2, %xmm0
	movss	%xmm1, -64(%rbp)        ## 4-byte Spill
	callq	_mem_si
	movss	-60(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movss	-64(%rbp), %xmm0        ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	addss	%xmm1, %xmm0
	movq	-8(%rbp), %rsi
	movss	%xmm0, 32(%rsi)
	movq	-16(%rbp), %rsi
	cvtsi2ssl	24(%rsi), %xmm0
	movq	-8(%rbp), %rsi
	movss	44(%rsi), %xmm1         ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -68(%rbp)        ## 4-byte Spill
	movaps	%xmm1, %xmm0
	callq	_mem_co
	movss	-68(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movq	-16(%rbp), %rsi
	movl	28(%rsi), %eax
	addl	$1, %eax
	cvtsi2ssl	%eax, %xmm0
	movq	-8(%rbp), %rsi
	cvtss2sd	44(%rsi), %xmm2
	movq	-16(%rbp), %rsi
	addsd	104(%rsi), %xmm2
	cvtsd2ss	%xmm2, %xmm2
	movss	%xmm0, -72(%rbp)        ## 4-byte Spill
	movaps	%xmm2, %xmm0
	movss	%xmm1, -76(%rbp)        ## 4-byte Spill
	callq	_mem_co
	movss	-72(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movss	-76(%rbp), %xmm0        ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	addss	%xmm1, %xmm0
	movq	-8(%rbp), %rsi
	movss	%xmm0, 36(%rsi)
	movq	-16(%rbp), %rsi
	cvtsi2ssl	24(%rsi), %xmm0
	movq	-8(%rbp), %rsi
	movss	44(%rsi), %xmm1         ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -80(%rbp)        ## 4-byte Spill
	movaps	%xmm1, %xmm0
	callq	_mem_si
	movss	-80(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movq	-16(%rbp), %rsi
	movl	28(%rsi), %eax
	addl	$1, %eax
	cvtsi2ssl	%eax, %xmm0
	movq	-8(%rbp), %rsi
	cvtss2sd	44(%rsi), %xmm2
	movq	-16(%rbp), %rsi
	addsd	104(%rsi), %xmm2
	cvtsd2ss	%xmm2, %xmm2
	movss	%xmm0, -84(%rbp)        ## 4-byte Spill
	movaps	%xmm2, %xmm0
	movss	%xmm1, -88(%rbp)        ## 4-byte Spill
	callq	_mem_si
	movss	-84(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	mulss	%xmm0, %xmm1
	movss	-88(%rbp), %xmm0        ## 4-byte Reload
                                        ## xmm0 = mem[0],zero,zero,zero
	addss	%xmm1, %xmm0
	movq	-8(%rbp), %rsi
	movss	%xmm0, 40(%rsi)
	addq	$96, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.align	4, 0x90
_line:                                  ## @line
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp12:
	.cfi_def_cfa_offset 16
Ltmp13:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp14:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movl	%ecx, -16(%rbp)
	movq	%r8, -24(%rbp)
	movq	%r9, -32(%rbp)
	cmpq	$0, _line.t_color(%rip)
	jne	LBB4_2
## BB#1:
	leaq	_line.t_color(%rip), %rdi
	callq	_ft_tab_ft_init
LBB4_2:
	cmpl	$1150, -8(%rbp)         ## imm = 0x47E
	jg	LBB4_10
## BB#3:
	cmpl	$1900, -4(%rbp)         ## imm = 0x76C
	jg	LBB4_10
## BB#4:
	cmpl	$0, -4(%rbp)
	jl	LBB4_10
## BB#5:
	cmpl	$0, -8(%rbp)
	jl	LBB4_10
## BB#6:
	cmpl	$1150, -16(%rbp)        ## imm = 0x47E
	jg	LBB4_10
## BB#7:
	cmpl	$1900, -12(%rbp)        ## imm = 0x76C
	jg	LBB4_10
## BB#8:
	cmpl	$0, -12(%rbp)
	jl	LBB4_10
## BB#9:
	cmpl	$0, -16(%rbp)
	jge	LBB4_11
LBB4_10:
	jmp	LBB4_23
LBB4_11:
	leaq	_line.t_color(%rip), %rax
	movq	-32(%rbp), %rcx
	movslq	120(%rcx), %rcx
	movq	(%rax,%rcx,8), %rax
	movq	-32(%rbp), %rdi
	callq	*%rax
	movl	%eax, -60(%rbp)
	movl	-12(%rbp), %eax
	subl	-4(%rbp), %eax
	movl	%eax, %edi
	callq	_abs
	movl	$4294967295, %edi       ## imm = 0xFFFFFFFF
	movl	$1, %edx
	movl	%eax, -36(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-12(%rbp), %eax
	cmovll	%edx, %edi
	movl	%edi, -40(%rbp)
	movl	-16(%rbp), %eax
	subl	-8(%rbp), %eax
	movl	%eax, %edi
	callq	_abs
	movl	$4294967295, %edx       ## imm = 0xFFFFFFFF
	movl	$1, %edi
	movl	%eax, -44(%rbp)
	movl	-8(%rbp), %eax
	cmpl	-16(%rbp), %eax
	cmovll	%edi, %edx
	movl	%edx, -48(%rbp)
	movl	-36(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jle	LBB4_13
## BB#12:
	movl	-36(%rbp), %eax
	movl	%eax, -64(%rbp)         ## 4-byte Spill
	jmp	LBB4_14
LBB4_13:
	xorl	%eax, %eax
	subl	-44(%rbp), %eax
	movl	%eax, -64(%rbp)         ## 4-byte Spill
LBB4_14:
	movl	-64(%rbp), %eax         ## 4-byte Reload
	movl	$2, %ecx
	cltd
	idivl	%ecx
	movl	%eax, -52(%rbp)
LBB4_15:                                ## =>This Inner Loop Header: Depth=1
	movl	-4(%rbp), %edi
	movl	-8(%rbp), %esi
	movl	-60(%rbp), %edx
	movq	-24(%rbp), %rcx
	callq	_draw_pixel
	movl	-4(%rbp), %edx
	cmpl	-12(%rbp), %edx
	jne	LBB4_18
## BB#16:                               ##   in Loop: Header=BB4_15 Depth=1
	movl	-8(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jne	LBB4_18
## BB#17:
	jmp	LBB4_23
LBB4_18:                                ##   in Loop: Header=BB4_15 Depth=1
	xorl	%eax, %eax
	movl	-52(%rbp), %ecx
	movl	%ecx, -56(%rbp)
	movl	-56(%rbp), %ecx
	subl	-36(%rbp), %eax
	cmpl	%eax, %ecx
	jle	LBB4_20
## BB#19:                               ##   in Loop: Header=BB4_15 Depth=1
	movl	-44(%rbp), %eax
	movl	-52(%rbp), %ecx
	subl	%eax, %ecx
	movl	%ecx, -52(%rbp)
	movl	-40(%rbp), %eax
	addl	-4(%rbp), %eax
	movl	%eax, -4(%rbp)
LBB4_20:                                ##   in Loop: Header=BB4_15 Depth=1
	movl	-56(%rbp), %eax
	cmpl	-44(%rbp), %eax
	jge	LBB4_22
## BB#21:                               ##   in Loop: Header=BB4_15 Depth=1
	movl	-36(%rbp), %eax
	addl	-52(%rbp), %eax
	movl	%eax, -52(%rbp)
	movl	-48(%rbp), %eax
	addl	-8(%rbp), %eax
	movl	%eax, -8(%rbp)
LBB4_22:                                ##   in Loop: Header=BB4_15 Depth=1
	jmp	LBB4_15
LBB4_23:
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal4,4byte_literals
	.align	2
LCPI5_0:
	.long	1120403456              ## float 100
	.section	__TEXT,__text,regular,pure_instructions
	.align	4, 0x90
_mem_co:                                ## @mem_co
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp15:
	.cfi_def_cfa_offset 16
Ltmp16:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp17:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movss	LCPI5_0(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -8(%rbp)
	mulss	-8(%rbp), %xmm1
	cvttss2si	%xmm1, %eax
	movl	%eax, -12(%rbp)
	cmpl	$1024, -12(%rbp)        ## imm = 0x400
	jge	LBB5_2
## BB#1:
	cmpl	$0, -12(%rbp)
	jge	LBB5_3
LBB5_2:
	movss	-8(%rbp), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	callq	_cosf
	movss	%xmm0, -4(%rbp)
	jmp	LBB5_6
LBB5_3:
	xorps	%xmm0, %xmm0
	leaq	_mem_co.lookup(%rip), %rax
	movslq	-12(%rbp), %rcx
	movss	(%rax,%rcx,4), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	ucomiss	%xmm0, %xmm1
	jne	LBB5_4
	jp	LBB5_4
	jmp	LBB5_5
LBB5_4:
	leaq	_mem_co.lookup(%rip), %rax
	movslq	-12(%rbp), %rcx
	movss	(%rax,%rcx,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -4(%rbp)
	jmp	LBB5_6
LBB5_5:
	leaq	_mem_co.lookup(%rip), %rax
	movss	-8(%rbp), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	callq	_cosf
	movslq	-12(%rbp), %rax
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	movss	%xmm0, (%rcx,%rax,4)
	movslq	-12(%rbp), %rax
	movss	(%rcx,%rax,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -4(%rbp)
LBB5_6:
	movss	-4(%rbp), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal4,4byte_literals
	.align	2
LCPI6_0:
	.long	1120403456              ## float 100
	.section	__TEXT,__text,regular,pure_instructions
	.align	4, 0x90
_mem_si:                                ## @mem_si
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp18:
	.cfi_def_cfa_offset 16
Ltmp19:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp20:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movss	LCPI6_0(%rip), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	movss	%xmm0, -8(%rbp)
	mulss	-8(%rbp), %xmm1
	cvttss2si	%xmm1, %eax
	movl	%eax, -12(%rbp)
	cmpl	$1024, -12(%rbp)        ## imm = 0x400
	jge	LBB6_2
## BB#1:
	cmpl	$0, -12(%rbp)
	jge	LBB6_3
LBB6_2:
	movss	-8(%rbp), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	callq	_sinf
	movss	%xmm0, -4(%rbp)
	jmp	LBB6_6
LBB6_3:
	xorps	%xmm0, %xmm0
	leaq	_mem_si.lookup(%rip), %rax
	movslq	-12(%rbp), %rcx
	movss	(%rax,%rcx,4), %xmm1    ## xmm1 = mem[0],zero,zero,zero
	ucomiss	%xmm0, %xmm1
	jne	LBB6_4
	jp	LBB6_4
	jmp	LBB6_5
LBB6_4:
	leaq	_mem_si.lookup(%rip), %rax
	movslq	-12(%rbp), %rcx
	movss	(%rax,%rcx,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -4(%rbp)
	jmp	LBB6_6
LBB6_5:
	leaq	_mem_si.lookup(%rip), %rax
	movss	-8(%rbp), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	movq	%rax, -24(%rbp)         ## 8-byte Spill
	callq	_sinf
	movslq	-12(%rbp), %rax
	movq	-24(%rbp), %rcx         ## 8-byte Reload
	movss	%xmm0, (%rcx,%rax,4)
	movslq	-12(%rbp), %rax
	movss	(%rcx,%rax,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movss	%xmm0, -4(%rbp)
LBB6_6:
	movss	-4(%rbp), %xmm0         ## xmm0 = mem[0],zero,zero,zero
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.align	4, 0x90
_ft_tab_ft_init:                        ## @ft_tab_ft_init
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp21:
	.cfi_def_cfa_offset 16
Ltmp22:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp23:
	.cfi_def_cfa_register %rbp
	leaq	_map_color(%rip), %rax
	leaq	_terra_color(%rip), %rcx
	leaq	_ign_color(%rip), %rdx
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	movq	%rdx, (%rdi)
	movq	-8(%rbp), %rdx
	movq	%rcx, 8(%rdx)
	movq	-8(%rbp), %rcx
	movq	%rax, 16(%rcx)
	popq	%rbp
	retq
	.cfi_endproc

	.align	4, 0x90
_draw_pixel:                            ## @draw_pixel
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp24:
	.cfi_def_cfa_offset 16
Ltmp25:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp26:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	%edx, -12(%rbp)
	movq	%rcx, -24(%rbp)
	cmpl	$1150, -8(%rbp)         ## imm = 0x47E
	jg	LBB8_4
## BB#1:
	cmpl	$1900, -4(%rbp)         ## imm = 0x76C
	jg	LBB8_4
## BB#2:
	cmpl	$0, -4(%rbp)
	jl	LBB8_4
## BB#3:
	cmpl	$0, -8(%rbp)
	jge	LBB8_5
LBB8_4:
	jmp	LBB8_6
LBB8_5:
	movl	-12(%rbp), %eax
	imull	$1900, -8(%rbp), %ecx   ## imm = 0x76C
	addl	-4(%rbp), %ecx
	movslq	%ecx, %rdx
	movq	-24(%rbp), %rsi
	movq	80(%rsi), %rsi
	movl	%eax, (%rsi,%rdx,4)
LBB8_6:
	popq	%rbp
	retq
	.cfi_endproc

	.align	4, 0x90
_ign_color:                             ## @ign_color
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp27:
	.cfi_def_cfa_offset 16
Ltmp28:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp29:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movq	%rdi, -16(%rbp)
	movq	-16(%rbp), %rdi
	cvttss2si	140(%rdi), %eax
	movl	%eax, -20(%rbp)
	cmpl	$250, -20(%rbp)
	jl	LBB9_2
## BB#1:
	movl	$16119026, -4(%rbp)     ## imm = 0xF5F4F2
	jmp	LBB9_15
LBB9_2:
	cmpl	$225, -20(%rbp)
	jl	LBB9_4
## BB#3:
	movl	$14737112, -4(%rbp)     ## imm = 0xE0DED8
	jmp	LBB9_15
LBB9_4:
	cmpl	$200, -20(%rbp)
	jl	LBB9_6
## BB#5:
	movl	$13288376, -4(%rbp)     ## imm = 0xCAC3B8
	jmp	LBB9_15
LBB9_6:
	cmpl	$175, -20(%rbp)
	jl	LBB9_8
## BB#7:
	movl	$12234394, -4(%rbp)     ## imm = 0xBAAE9A
	jmp	LBB9_15
LBB9_8:
	cmpl	$150, -20(%rbp)
	jl	LBB9_10
## BB#9:
	movl	$11311740, -4(%rbp)     ## imm = 0xAC9A7C
	jmp	LBB9_15
LBB9_10:
	cmpl	$125, -20(%rbp)
	jl	LBB9_12
## BB#11:
	movl	$11175763, -4(%rbp)     ## imm = 0xAA8753
	jmp	LBB9_15
LBB9_12:
	cmpl	$100, -20(%rbp)
	jl	LBB9_14
## BB#13:
	movl	$12163162, -4(%rbp)     ## imm = 0xB9985A
	jmp	LBB9_15
LBB9_14:
	movl	-20(%rbp), %edi
	movq	-16(%rbp), %rsi
	callq	_ign_color_normeh
	movl	%eax, -4(%rbp)
LBB9_15:
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.align	4, 0x90
_terra_color:                           ## @terra_color
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp30:
	.cfi_def_cfa_offset 16
Ltmp31:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp32:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	xorps	%xmm0, %xmm0
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	ucomiss	140(%rdi), %xmm0
	jae	LBB10_2
## BB#1:
	xorps	%xmm0, %xmm0
	movq	-8(%rbp), %rax
	ucomiss	136(%rax), %xmm0
	jb	LBB10_3
LBB10_2:
	movq	-8(%rbp), %rax
	movss	128(%rax), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-8(%rbp), %rax
	subss	140(%rax), %xmm0
	cvttss2si	%xmm0, %ecx
	movl	%ecx, -16(%rbp)
	jmp	LBB10_4
LBB10_3:
	movq	-8(%rbp), %rax
	movss	140(%rax), %xmm0        ## xmm0 = mem[0],zero,zero,zero
	movq	-8(%rbp), %rax
	cvttss2si	128(%rax), %edi
	movss	%xmm0, -20(%rbp)        ## 4-byte Spill
	callq	_abs
	cvtsi2ssl	%eax, %xmm0
	movss	-20(%rbp), %xmm1        ## 4-byte Reload
                                        ## xmm1 = mem[0],zero,zero,zero
	addss	%xmm0, %xmm1
	cvttss2si	%xmm1, %eax
	movl	%eax, -16(%rbp)
LBB10_4:
	cmpl	$0, -16(%rbp)
	jne	LBB10_6
## BB#5:
	movl	$1, %eax
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	jmp	LBB10_7
LBB10_6:
	movl	-16(%rbp), %edi
	callq	_abs
	movl	%eax, -24(%rbp)         ## 4-byte Spill
LBB10_7:
	movl	-24(%rbp), %eax         ## 4-byte Reload
	movl	%eax, -16(%rbp)
	movq	-8(%rbp), %rcx
	cvttss2si	128(%rcx), %edi
	callq	_abs
	cvtsi2ssl	%eax, %xmm0
	movq	-8(%rbp), %rcx
	addss	132(%rcx), %xmm0
	cvttss2si	%xmm0, %eax
	movl	%eax, -12(%rbp)
	imull	$255, -16(%rbp), %eax
	cltd
	idivl	-12(%rbp)
	shll	$16, %eax
	imull	$255, -16(%rbp), %edi
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	movl	%edi, %eax
	cltd
	idivl	-12(%rbp)
	shll	$8, %eax
	movl	-28(%rbp), %edi         ## 4-byte Reload
	addl	%eax, %edi
	imull	$255, -16(%rbp), %eax
	cltd
	idivl	-12(%rbp)
	addl	%eax, %edi
	movl	%edi, %eax
	addq	$32, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.align	4, 0x90
_map_color:                             ## @map_color
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp33:
	.cfi_def_cfa_offset 16
Ltmp34:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp35:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	$16367674, -12(%rbp)    ## imm = 0xF9C03A
	movl	$9582598, -16(%rbp)     ## imm = 0x923806
	movq	-8(%rbp), %rdi
	movslq	24(%rdi), %rax
	movslq	28(%rdi), %rcx
	movq	8(%rdi), %rdx
	movq	(%rdx,%rcx,8), %rcx
	movss	(%rcx,%rax,4), %xmm0    ## xmm0 = mem[0],zero,zero,zero
	movss	128(%rdi), %xmm1        ## xmm1 = mem[0],zero,zero,zero
	subss	%xmm1, %xmm0
	movl	-12(%rbp), %esi
	movl	$9582598, %r8d          ## imm = 0x923806
	subl	%esi, %r8d
	movl	%r8d, %eax
	cvtsi2ssq	%rax, %xmm1
	mulss	%xmm1, %xmm0
	movq	-8(%rbp), %rax
	movss	132(%rax), %xmm1        ## xmm1 = mem[0],zero,zero,zero
	movq	-8(%rbp), %rax
	subss	128(%rax), %xmm1
	divss	%xmm1, %xmm0
	cvttss2si	%xmm0, %esi
	addl	-12(%rbp), %esi
	movl	%esi, %eax
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal4,4byte_literals
	.align	2
LCPI12_0:
	.long	3240099840              ## float -10
	.section	__TEXT,__text,regular,pure_instructions
	.align	4, 0x90
_ign_color_normeh:                      ## @ign_color_normeh
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp36:
	.cfi_def_cfa_offset 16
Ltmp37:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp38:
	.cfi_def_cfa_register %rbp
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpl	$75, -8(%rbp)
	jl	LBB12_2
## BB#1:
	movl	$12822379, -4(%rbp)     ## imm = 0xC3A76B
	jmp	LBB12_20
LBB12_2:
	cmpl	$50, -8(%rbp)
	jl	LBB12_4
## BB#3:
	movl	$14603939, -4(%rbp)     ## imm = 0xDED6A3
	jmp	LBB12_20
LBB12_4:
	cmpl	$25, -8(%rbp)
	jl	LBB12_6
## BB#5:
	movl	$12438678, -4(%rbp)     ## imm = 0xBDCC96
	jmp	LBB12_20
LBB12_6:
	cmpl	$20, -8(%rbp)
	jl	LBB12_8
## BB#7:
	movl	$11060879, -4(%rbp)     ## imm = 0xA8C68F
	jmp	LBB12_20
LBB12_8:
	cmpl	$10, -8(%rbp)
	jl	LBB12_10
## BB#9:
	movl	$9748363, -4(%rbp)      ## imm = 0x94BF8B
	jmp	LBB12_20
LBB12_10:
	cmpl	$0, -8(%rbp)
	jle	LBB12_12
## BB#11:
	movl	$11325605, -4(%rbp)     ## imm = 0xACD0A5
	jmp	LBB12_20
LBB12_12:
	movss	LCPI12_0(%rip), %xmm0   ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	movss	140(%rax), %xmm1        ## xmm1 = mem[0],zero,zero,zero
	ucomiss	%xmm0, %xmm1
	jae	LBB12_14
## BB#13:
	movss	LCPI12_0(%rip), %xmm0   ## xmm0 = mem[0],zero,zero,zero
	movq	-16(%rbp), %rax
	movss	136(%rax), %xmm1        ## xmm1 = mem[0],zero,zero,zero
	ucomiss	%xmm0, %xmm1
	jb	LBB12_15
LBB12_14:
	movl	$14217982, -4(%rbp)     ## imm = 0xD8F2FE
	jmp	LBB12_20
LBB12_15:
	cmpl	$-50, -8(%rbp)
	jle	LBB12_17
## BB#16:
	movl	$12182527, -4(%rbp)     ## imm = 0xB9E3FF
	jmp	LBB12_20
LBB12_17:
	cmpl	$-75, -8(%rbp)
	jle	LBB12_19
## BB#18:
	movl	$9882096, -4(%rbp)      ## imm = 0x96C9F0
	jmp	LBB12_20
LBB12_19:
	movl	$7449560, -4(%rbp)      ## imm = 0x71ABD8
LBB12_20:
	movl	-4(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc

.zerofill __DATA,__bss,_render.w,96,3   ## @render.w
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"ratio final : %f, wx: %d, wy: %d \n"

.zerofill __DATA,__bss,_mem_co.lookup,4096,4 ## @mem_co.lookup
.zerofill __DATA,__bss,_mem_si.lookup,4096,4 ## @mem_si.lookup
.zerofill __DATA,__bss,_line.t_color,24,4 ## @line.t_color

.subsections_via_symbols
