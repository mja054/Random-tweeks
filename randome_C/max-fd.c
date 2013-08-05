#include <stdio.h>
#include <fcntl.h>

int
main ()
{
        int i = 1;
        int fd = 0;
        char path_name[1024], err[1024];

        while (1) {
                sprintf (path_name, "/tmp/html/files/fd%d", i);
                fd = open (path_name, O_CREAT | O_WRONLY);
                if (fd == -1) {
                        fflush (NULL);
                        sprintf (err, "open %d:", i);
                        perror (err);
                        return 0;
                }
                printf ("%d ", i);
                i++;
        }

        return 0;
}
