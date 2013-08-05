#ifndef mysyscall_h__
#define mysyscall_h__

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int myopen (const char *path, int flags);

int myread (int fildes, void *buf, size_t nbyte);

int mywrite (int fildes, void *buf, size_t nbyte);
#endif // mysyscall_h__
