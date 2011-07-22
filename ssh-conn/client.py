#!/usr/bin/env python

import os
import sys
import pickle
import time
import select
def send(out, *args):
    os.write(out, pickle.dumps(args, -1))

def recv(inf):
    return pickle.load(inf)

ix, ox = os.pipe()
iy, oy = os.pipe()

pid = os.fork ()
if pid == 0:
        os.close (ox)
        os.dup2 (ix, sys.stdin.fileno())
        os.close (iy)
        os.dup2 (oy, sys.stdout.fileno())
        argv = ['ssh',\
                '-oPreferredAuthentications=password,keyboard-interactive',\
                'junaid@192.168.1.4', '/home/junaid/Downloads/ssh-client-server/gsyncd.py']
        os.execvp (argv[0], argv)

os.close (ix)
os.close (oy)

inf = os.fdopen (iy)
select.select((iy,), (), ())
print recv(inf)
send (ox, "client says hello..")
