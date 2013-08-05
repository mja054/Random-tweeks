#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>

int
main()
{
        struct timeval tv = {0,};

        if (gettimeofday (&tv, NULL)) {
                fprintf (stderr, "gettimeofday failed, %s\n", strerror (errno));
                return -1;
        }

        printf ("tv_sec= %lu\n", tv.tv_sec);

        printf ("time = %s\n", asctime (localtime (&tv.tv_sec)));

        return 0;
}
