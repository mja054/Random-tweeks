#!/usr/bin/python

import pickle, os, sys, select

fp=open ('/tmp/out', 'w+')
fd = file.fileno (fp)

os.write (sys.stdout.fileno(), pickle.dumps (['server says hi'], -1))

select.select ((sys.stdin.fileno(),), (), ())

inf = os.fdopen (sys.stdin.fileno())

os.write (fd, str(pickle.load(sys.stdin)))
