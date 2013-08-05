#include <stdio.h>
#include <string.h>

#define add(x, y) do {                          \
                n = x + y;                      \
        } while(0)

void
pinto ()
{
        printf ("we are pinto\n");
}

int
main ()
{
        int n = 1;
        int y = 10;
        char *str = "This is a test program";

        n = strlen (str);

        pinto ();

        add(1, 2);

        printf ("n = %d\n", n);

        printf ("y = %d\n", y);

        printf ("y = %d\n", y);

        n = n + y;

        printf ("n = %d\n", n);

        return 0;
}
