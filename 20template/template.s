	.file	"template.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN6BufferISsEC2Ev,"axG",@progbits,_ZN6BufferISsEC5Ev,comdat
	.align 2
	.weak	_ZN6BufferISsEC2Ev
	.type	_ZN6BufferISsEC2Ev, @function
_ZN6BufferISsEC2Ev:
.LFB969:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA969
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$24, %rsp
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rbx
	.cfi_offset 3, -40
	.cfi_offset 12, -32
	.cfi_offset 13, -24
	movq	%rbx, %r13
	movl	$19, %r12d
	jmp	.L2
.L3:
	movq	%r13, %rdi
.LEHB0:
	call	_ZNSsC1Ev
.LEHE0:
	addq	$8, %r13
	subq	$1, %r12
.L2:
	cmpq	$-1, %r12
	setne	%al
	testb	%al, %al
	jne	.L3
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L7:
	.cfi_restore_state
	movq	%rax, %r13
	testq	%rbx, %rbx
	je	.L5
	movl	$19, %eax
	subq	%r12, %rax
	salq	$3, %rax
	leaq	(%rbx,%rax), %r12
.L6:
	cmpq	%rbx, %r12
	je	.L5
	subq	$8, %r12
	movq	%r12, %rdi
	call	_ZNSsD1Ev
	jmp	.L6
.L5:
	movq	%r13, %rax
	movq	%rax, %rdi
.LEHB1:
	call	_Unwind_Resume
.LEHE1:
	.cfi_endproc
.LFE969:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA969:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE969-.LLSDACSB969
.LLSDACSB969:
	.uleb128 .LEHB0-.LFB969
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L7-.LFB969
	.uleb128 0
	.uleb128 .LEHB1-.LFB969
	.uleb128 .LEHE1-.LEHB1
	.uleb128 0
	.uleb128 0
.LLSDACSE969:
	.section	.text._ZN6BufferISsEC2Ev,"axG",@progbits,_ZN6BufferISsEC5Ev,comdat
	.size	_ZN6BufferISsEC2Ev, .-_ZN6BufferISsEC2Ev
	.section	.text._ZN6BufferISsED2Ev,"axG",@progbits,_ZN6BufferISsED5Ev,comdat
	.align 2
	.weak	_ZN6BufferISsED2Ev
	.type	_ZN6BufferISsED2Ev, @function
_ZN6BufferISsED2Ev:
.LFB972:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	testq	%rax, %rax
	je	.L8
	.cfi_offset 3, -24
	movq	-24(%rbp), %rax
	leaq	160(%rax), %rbx
.L10:
	movq	-24(%rbp), %rax
	cmpq	%rax, %rbx
	je	.L8
	subq	$8, %rbx
	movq	%rbx, %rdi
	call	_ZNSsD1Ev
	jmp	.L10
.L8:
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE972:
	.size	_ZN6BufferISsED2Ev, .-_ZN6BufferISsED2Ev
	.section	.rodata
.LC0:
	.string	"abc"
	.text
	.globl	main
	.type	main, @function
main:
.LFB967:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA967
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$296, %rsp
	movl	$1000, -36(%rbp)
	leaq	-36(%rbp), %rdx
	leaq	-128(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	.cfi_offset 3, -24
	call	_ZN6BufferIiE6insertERKi
	leaq	-304(%rbp), %rax
	movq	%rax, %rdi
.LEHB2:
	call	_ZN6BufferISsEC1Ev
.LEHE2:
	leaq	-17(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev
	leaq	-17(%rbp), %rdx
	leaq	-32(%rbp), %rax
	movl	$.LC0, %esi
	movq	%rax, %rdi
.LEHB3:
	call	_ZNSsC1EPKcRKSaIcE
.LEHE3:
	leaq	-32(%rbp), %rdx
	leaq	-304(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB4:
	call	_ZN6BufferISsE6insertERKSs
.LEHE4:
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
.LEHB5:
	call	_ZNSsD1Ev
.LEHE5:
	leaq	-17(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev
	movl	$0, %ebx
	leaq	-304(%rbp), %rax
	movq	%rax, %rdi
.LEHB6:
	call	_ZN6BufferISsED1Ev
.LEHE6:
	movl	%ebx, %eax
	addq	$296, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L15:
	.cfi_restore_state
	movq	%rax, %rbx
	leaq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSsD1Ev
	jmp	.L13
.L14:
	movq	%rax, %rbx
.L13:
	leaq	-17(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev
	leaq	-304(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6BufferISsED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB7:
	call	_Unwind_Resume
.LEHE7:
	.cfi_endproc
.LFE967:
	.section	.gcc_except_table
.LLSDA967:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE967-.LLSDACSB967
.LLSDACSB967:
	.uleb128 .LEHB2-.LFB967
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB3-.LFB967
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L14-.LFB967
	.uleb128 0
	.uleb128 .LEHB4-.LFB967
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L15-.LFB967
	.uleb128 0
	.uleb128 .LEHB5-.LFB967
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L14-.LFB967
	.uleb128 0
	.uleb128 .LEHB6-.LFB967
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB7-.LFB967
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
.LLSDACSE967:
	.text
	.size	main, .-main
	.section	.text._ZN6BufferIiE6insertERKi,"axG",@progbits,_ZN6BufferIiE6insertERKi,comdat
	.align 2
	.weak	_ZN6BufferIiE6insertERKi
	.type	_ZN6BufferIiE6insertERKi, @function
_ZN6BufferIiE6insertERKi:
.LFB974:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	80(%rax), %eax
	movq	-16(%rbp), %rdx
	movl	(%rdx), %esi
	movq	-8(%rbp), %rdx
	movslq	%eax, %rcx
	movl	%esi, (%rdx,%rcx,4)
	leal	1(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 80(%rax)
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE974:
	.size	_ZN6BufferIiE6insertERKi, .-_ZN6BufferIiE6insertERKi
	.section	.text._ZN6BufferISsE6insertERKSs,"axG",@progbits,_ZN6BufferISsE6insertERKSs,comdat
	.align 2
	.weak	_ZN6BufferISsE6insertERKSs
	.type	_ZN6BufferISsE6insertERKSs, @function
_ZN6BufferISsE6insertERKSs:
.LFB990:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	160(%rax), %eax
	movslq	%eax, %rdx
	salq	$3, %rdx
	addq	-8(%rbp), %rdx
	leal	1(%rax), %ecx
	movq	-8(%rbp), %rax
	movl	%ecx, 160(%rax)
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSsaSERKSs
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE990:
	.size	_ZN6BufferISsE6insertERKSs, .-_ZN6BufferISsE6insertERKSs
	.text
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1014:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L18
	cmpl	$65535, -8(%rbp)
	jne	.L18
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$_ZNSt8ios_base4InitD1Ev, %eax
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movq	%rax, %rdi
	call	__cxa_atexit
.L18:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1014:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1015:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1015:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.ctors,"aw",@progbits
	.align 8
	.quad	_GLOBAL__sub_I_main
	.section	.rodata
	.align 8
	.type	_ZZL18__gthread_active_pvE20__gthread_active_ptr, @object
	.size	_ZZL18__gthread_active_pvE20__gthread_active_ptr, 8
_ZZL18__gthread_active_pvE20__gthread_active_ptr:
	.quad	_ZL22__gthrw_pthread_cancelm
	.weakref	_ZL20__gthrw_pthread_oncePiPFvvE,pthread_once
	.weakref	_ZL27__gthrw_pthread_getspecificj,pthread_getspecific
	.weakref	_ZL27__gthrw_pthread_setspecificjPKv,pthread_setspecific
	.weakref	_ZL22__gthrw_pthread_createPmPK14pthread_attr_tPFPvS3_ES3_,pthread_create
	.weakref	_ZL20__gthrw_pthread_joinmPPv,pthread_join
	.weakref	_ZL21__gthrw_pthread_equalmm,pthread_equal
	.weakref	_ZL20__gthrw_pthread_selfv,pthread_self
	.weakref	_ZL22__gthrw_pthread_detachm,pthread_detach
	.weakref	_ZL22__gthrw_pthread_cancelm,pthread_cancel
	.weakref	_ZL19__gthrw_sched_yieldv,sched_yield
	.weakref	_ZL26__gthrw_pthread_mutex_lockP15pthread_mutex_t,pthread_mutex_lock
	.weakref	_ZL29__gthrw_pthread_mutex_trylockP15pthread_mutex_t,pthread_mutex_trylock
	.weakref	_ZL31__gthrw_pthread_mutex_timedlockP15pthread_mutex_tPK8timespec,pthread_mutex_timedlock
	.weakref	_ZL28__gthrw_pthread_mutex_unlockP15pthread_mutex_t,pthread_mutex_unlock
	.weakref	_ZL26__gthrw_pthread_mutex_initP15pthread_mutex_tPK19pthread_mutexattr_t,pthread_mutex_init
	.weakref	_ZL29__gthrw_pthread_mutex_destroyP15pthread_mutex_t,pthread_mutex_destroy
	.weakref	_ZL30__gthrw_pthread_cond_broadcastP14pthread_cond_t,pthread_cond_broadcast
	.weakref	_ZL27__gthrw_pthread_cond_signalP14pthread_cond_t,pthread_cond_signal
	.weakref	_ZL25__gthrw_pthread_cond_waitP14pthread_cond_tP15pthread_mutex_t,pthread_cond_wait
	.weakref	_ZL30__gthrw_pthread_cond_timedwaitP14pthread_cond_tP15pthread_mutex_tPK8timespec,pthread_cond_timedwait
	.weakref	_ZL28__gthrw_pthread_cond_destroyP14pthread_cond_t,pthread_cond_destroy
	.weakref	_ZL26__gthrw_pthread_key_createPjPFvPvE,pthread_key_create
	.weakref	_ZL26__gthrw_pthread_key_deletej,pthread_key_delete
	.weakref	_ZL30__gthrw_pthread_mutexattr_initP19pthread_mutexattr_t,pthread_mutexattr_init
	.weakref	_ZL33__gthrw_pthread_mutexattr_settypeP19pthread_mutexattr_ti,pthread_mutexattr_settype
	.weakref	_ZL33__gthrw_pthread_mutexattr_destroyP19pthread_mutexattr_t,pthread_mutexattr_destroy
	.weak	_ZN6BufferISsEC1Ev
	.set	_ZN6BufferISsEC1Ev,_ZN6BufferISsEC2Ev
	.weak	_ZN6BufferISsED1Ev
	.set	_ZN6BufferISsED1Ev,_ZN6BufferISsED2Ev
	.ident	"GCC: (GNU) 4.6.0 20110530 (Red Hat 4.6.0-9)"
	.section	.note.GNU-stack,"",@progbits
