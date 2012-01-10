import eventlet

def handle(fd):
    print 'client connected'
    while True:
        x = fd.readline()
        if not x:
            break
        fd.write(x)
        fd.flush()
        print 'echoed', x
    print 'cleint disconnected'

# Get a Server side Socket listening on localhost:6000
server = eventlet.listen(('0.0.0.0', 6000))

# Create a GreenThread Pool
pool = eventlet.GreenPool()

while True:
    try:
        # Accept connection
        new_socket, address = server.accept()
        print "accepted ", address

        # eventlet.spawn(func, *args, **kw)
        # This launches a greenthread to call func.
        # Spawning off multiple greenthreads gets work done in parallel. 
        pool.spawn_n(handle, new_socket.makefile('rw'))
    except (SystemExit, KeyboardInterrupt):
        break 

