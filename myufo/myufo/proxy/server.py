from webob import Request, Response

def print_callstack():
    try:
        for i in range(20):
            print sys._getframe(i).f_code.co_filename + ': ' +\
                sys._getframe(i).f_code.co_name + '\n'
    except ValueError:
        print '------------------------'

class Application():
    def __init__(self, conf):
        print 'In __init__'
        pass

    def GET(self, req):
        print 'In GET()'
        res = Response(request=req)
        res.status = '200 OK'
        res.headerlist = [('Content-type', 'text/html')]
        res.body = 'Hi, this is awesome.\n'
        return res

    def __call__(self, env, start_response):
        req = Request(env)
        if req.method == 'GET':
            return self.GET(req)(env, start_response)
        else:
            res = Response(request=req)
            res.status = '503'
            res.body = 'No permission to write.\n'
            return res(env, start_response)

def app_factory(global_conf, **local_conf):
    """paste.deploy app factory for creating WSGI proxy apps."""
    conf = global_conf.copy()
    conf.update(local_conf)
    return Application(conf)
