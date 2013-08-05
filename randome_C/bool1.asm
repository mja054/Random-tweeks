	.file	"bool1.c"
	.intel_syntax noprefix
	.section	.rodata
.LC0:
	.string	"p is true"
.LC1:
	.string	"p is not true"
.LC2:
	.string	"p is false"
.LC3:
	.string	"p is not false"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	push	rbp
.LCFI0:
	mov	rbp, rsp
.LCFI1:
	sub	rsp, 32
	mov	DWORD PTR [rbp-20], edi
	mov	QWORD PTR [rbp-32], rsi
	movzx	eax, BYTE PTR [rbp-1]
	test	al, al
	je	.L2
	mov	edi, OFFSET FLAT:.LC0
	call	puts
	jmp	.L3
.L2:
	mov	edi, OFFSET FLAT:.LC1
	call	puts
.L3:
	movzx	eax, BYTE PTR [rbp-1]
	xor	eax, 1
	test	al, al
	je	.L4
	mov	edi, OFFSET FLAT:.LC2
	call	puts
	jmp	.L5
.L4:
	mov	edi, OFFSET FLAT:.LC3
	call	puts
.L5:
	mov	eax, 0
	leave
.LCFI2:
	ret
.LFE0:
	.size	main, .-main
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0
	.byte	0x3
	.string	"zR"
	.uleb128 0x1
	.sleb128 -8
	.uleb128 0x10
	.uleb128 0x1
	.byte	0x3
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB0
	.long	.LFE0-.LFB0
	.uleb128 0
	.byte	0x4
	.long	.LCFI0-.LFB0
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.byte	0x4
	.long	.LCFI2-.LCFI1
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.align 8
.LEFDE1:
	.ident	"GCC: (GNU) 4.7.0 20120507 (Red Hat 4.7.0-5)"
	.section	.note.GNU-stack,"",@progbits
