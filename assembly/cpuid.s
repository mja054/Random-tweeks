                .data

s0:
                .asciz  "Largest basic function number supported: %i\n"
s1:
                .asciz  "Vendor ID: %.12s\n"

                .text

                .align  32
                .global  _start
_start:
                pushq   %rbp
                pushq   %rbx
                movq    %rsp,%rbp
                subq    $16,%rsp

                xorl    %eax,%eax
                cpuid

                movl    %ebx,0(%rsp)
                movl    %edx,4(%rsp)
                movl    %ecx,8(%rsp)

                movq    $s0,%rdi
                movl    %eax,%esi
                xorb    %al,%al
                call    printf

                movq    $s1,%rdi
                movq    %rsp,%rsi
                xorb    %al,%al
                call    printf

                movq    %rbp,%rsp
                popq    %rbx
                popq    %rbp
                movl    $1,%eax
                int     $0x80
