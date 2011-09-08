class Simple_App:
    def __init__(self, environ, start_response):
        self.environ = environ
        self.start = start_response

    def __iter__(self):
        status = '200 OK'
        response_headers = [('Content-type', 'text/plain')]
        self.start(status, response_headers)
        yield 'My Hello world\n'


from wsgiref.simple_server import make_server, demo_app

httpd = make_server ('', 8000, Simple_App)

print 'serving https on port 8000...'

httpd.serve_forever()
