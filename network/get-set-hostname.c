#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int
main()
{
        char a[255], *b = "redhat";
        int ret;

        if (gethostname (a, sizeof (a)) != 0) {
                fprintf (stderr, "sethostname failed\n");
                return -1;
        }
        printf ("hostname: %s\n", a);

        ret = sethostname (b, 6);
        if (ret != 0) {
                fprintf (stderr, "sethostname failed, %s\n", strerror (errno));
                return -1;
        }

        if (gethostname (a, sizeof (a)) != 0) {
                fprintf (stderr, "sethostname failed\n");
                return -1;
        }
        printf ("hostname: %s\n", a);

        return 0;
}
