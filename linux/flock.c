#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#define permission S_IRUSR|S_IWUSR
#define print_err(sys_call) do {                                \
                fprintf (stderr, #sys_call " failed, %s\n",    \
                         strerror (errno));                     \
                return -1;                                      \
        }  while (0)


/* struct flock { */
/*         short l_type; */
/*         off_t l_start; */
/*         short l_whence; // SEEK_SET, */
/*                         // SEEK_CUR, */
/*                         // SEEK_END */
/*         off_t l_len; */
/*         pid_t l_pid; */
/* }; */

int
main ()
{
        int fd, ret;
        struct flock lock;

        lock.l_type = F_WRLCK;
        lock.l_start = 0;
        lock.l_whence = SEEK_SET;
        lock.l_len = 0;

        fd = open ("/tmp/a", O_WRONLY | O_CREAT); //, permission);
        if (fd < 0)
                print_err ("open");

        ret = fcntl (fd, F_SETLK, &lock);
        if (ret < 0)
                print_err ("fcntl");

        printf ("successfully held the lock\n");

        sleep (100);

        return 0;
}
