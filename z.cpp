#include <cstdio>

extern "C" int ackermann(int m, int n);

asm(
".global ackermann\n"
"ackermann:\n"
"    pushq %rbp\n"
"    movq %rsp, %rbp\n"
"    subq $16, %rsp\n"
"    movl %edi, -4(%rbp)\n" // m
"    movl %esi, -8(%rbp)\n" // n
"    movl -4(%rbp), %eax\n"
"    movl -8(%rbp), %edx\n"
"    movl %eax, %esi\n"
"    movl %edx, %edx\n"
"    movl $.LC0, %edi\n"
"    movl $0, %eax\n"
"    call printf@PLT\n"
"    movl -4(%rbp), %eax\n"
"    testl %eax, %eax\n"
"    jne .L1\n"
"    movl -8(%rbp), %eax\n"
"    addl $1, %eax\n"
"    jmp .L2\n"
".L1:\n"
"    movl -8(%rbp), %eax\n"
"    testl %eax, %eax\n"
"    jne .L3\n"
"    movl -4(%rbp), %eax\n"
"    subl $1, %eax\n"
"    movl %eax, %edi\n"
"    movl $1, %esi\n"
"    call ackermann\n"
"    jmp .L2\n"
".L3:\n"
"    movl -4(%rbp), %eax\n"
"    movl -8(%rbp), %edx\n"
"    subl $1, %edx\n"
"    movl %eax, %edi\n"
"    movl %edx, %esi\n"
"    call ackermann\n"
"    movl -4(%rbp), %edi\n"
"    movl %eax, %esi\n"
"    call ackermann\n"
".L2:\n"
"    leave\n"
"    ret\n"
);

asm(
".section .rodata\n"
".LC0:\n"
"    .string \"%d %d\\n\"\n"
);

int main() {
    int m = 4, n = 2;
    int result = ackermann(m, n);
    printf("Ackermann(%d, %d) = %d\n", m, n, result);
    return 0;
}
