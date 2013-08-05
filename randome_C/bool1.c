// gcc bool1.c -g0 -O0 -fno-dwarf2-cfi-asm  -W -Wall -Wextra -pedantic -Werror -masm=intel -S -o bool1.asm

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
        volatile bool p;

        if ( p )
                puts("p is true");
        else
                puts("p is not true");

        if ( ! p )
                puts("p is false");
        else
                puts("p is not false");

        return 0;
}
