from webob import Request, Response
import os

def print_callstack():
    try:
        for i in range(20):
            print sys._getframe(i).f_code.co_filename + ': ' +\
                sys._getframe(i).f_code.co_name + '\n'
    except ValueError:
        print '------------------------'

class Diskfile(object):
    def __init__(self, path):
        if not os.path.exists(os.path.join('/tmp', path.strip('/'))):
            self.error = True
        else:
            self.error = False
            self.fp = file(os.path.join('/tmp', path.strip('/')), 'r+')

    def __iter__(self):
        while True:
            chunk = self.fp.read(4096)
            if chunk:
                yield chunk
            else:
                break

class Application():
    def __init__(self, conf):
        print 'In __init__'
        pass

    def GET(self, req):
        print 'In GET()'
        resp_headers = {'user-name': 'junaid',
                        'Content-type': 'text/html'}
        file = Diskfile(req.path_info)
        print 'path_info: ', req.path_info
        if file.error:
            res = Response(request=req, headers=resp_headers)
            res.status = '503 File not found'
        else:
            res = Response(request=req, headers=resp_headers, app_iter=file)
            res.status = '200 OK'
            res.headerlist = [('Content-type', 'application/octet-stream')]
        return res

    def __call__(self, env, start_response):
        print 'env: ', env
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
