#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int
print_fd_flags (int fd)
{
        int ret;

        ret = fcntl (fd, F_GETFD);
        if (ret < 0) {
                fprintf (stderr, "fcntl failed, %s\n", strerror (errno));
                return -1;
        }

        printf ("fcntl fd flags = %d\n", ret);
        return ret;
}

int
set_fd_flags (int fd, int flags)
{
        int ret;

        ret = fcntl (fd, F_SETFD, flags);
        if (ret < 0) {
                fprintf (stderr, "fcntl failed, %s\n", strerror (errno));
                return -1;
        }
        return 0;
}

int
print_fd_status (int fd)
{
        int ret;

        ret = fcntl (fd, F_GETFL);
        if (ret < 0) {
                fprintf (stderr, "fcntl failed, %s\n", strerror (errno));
                return -1;
        }
        printf ("fcntl fd status = %d\n", ret);
        return 0;
}

int
set_fd_status  (int fd, int flags)
{
        int ret;

        ret = fcntl (fd, F_SETFL, flags);
        if (ret < 0) {
                fprintf (stderr, "fcntl failed, %s\n", strerror (errno));
                return -1;
        }
        return 0;
}

int
main ()
{
        int fd, ret;

        fd = open ("/tmp/a", O_WRONLY | O_CREAT);
        if (fd == -1) {
                fprintf (stderr, "open failed, %s\n", strerror (errno));
                return -1;
        }

        (void) print_fd_flags (fd);

        if (set_fd_flags (fd, FD_CLOEXEC) < 0)
                return -1;

        (void) print_fd_flags (fd);
        (void) set_fd_flags (fd, 0);

        (void) print_fd_status (fd);

        if (set_fd_status (fd, O_APPEND) < 0)
                return -1;
        /* set_fd_status (fd, O_APPEND); */
        /* set_fd_status (fd, O_NONBLOCK); */
        (void) print_fd_status (fd);

        return 0;
}
