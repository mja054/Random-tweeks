#include "mysyscall.h"

int
myopen (const char *path, int flags)
{
        return open (path, flags);
}

int
myread (int fildes, void *buf, size_t nbyte)
{
        return read (fildes, buf, nbyte);
}

int
mywrite (int fildes, void *buf, size_t nbyte)
{
        return write (fildes, buf, nbyte);
}
