#!/usr/bin/python

import errno, os

def mock():
    raise IOError(errno.EAGAIN)#, os.strerror(errno.EAGAIN), 'adf')


try:
    mock()
except IOError as ex:
    print ex.errno
    print dir(ex)
    print ex.strerror
    print ex.filename
    print ex.args
else:
    print 'IOError was not raised'
