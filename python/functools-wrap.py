# http://stackoverflow.com/questions/308999/what-does-functools-wraps-do

#!/usr/bin/python
import functools

def logged(func):
    @functools.wraps(func)
    def with_loggin(*args, **kwargs):
        print func.__name__
        return func(*args, **kwargs)
    return with_loggin

@logged
def f(x):
    return x*x

print f.__name__
