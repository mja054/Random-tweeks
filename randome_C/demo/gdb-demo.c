#include <stdio.h>
#include "mysyscall.h"

int
main ()
{
        int fd, cnt;
        char buf[12];

        fd = myopen ("/tmp/demo/1.txt", O_CREAT | O_RDWR);
        if (fd == -1) {
                perror ("open: ");
                return -1;
        }

        cnt = myread (fd, buf, 10);
        if (cnt > 0) {
                mywrite (STDIN_FILENO, buf, cnt);
        } else {
                perror ("write: ");
        }

        printf ("\nexiting...\n");

        sleep (1);

        return 0;
}
