from wsgiref.simple_server import make_server, demo_app
from demo import Simple_App

class AuthenticationMiddleware:
    """A modified version of an original example at:
    http://isapi-wsgi.python-hosting.com/wiki/WSGI-Gateway-or-Glue
    """

    def __init__(self, app, allowed_addresses):
        """
        @param app: the WSGI app we will that comes after us
        @param allowed_addresses: list of remote addresses from which to allow
                                  access
        """
        self.app = app
        self.allowed_addresses = allowed_addresses

    def __call__(self, environ, start_response):
        """The standard WSGI interface"""
        addr = environ.get('REMOTE_ADDR','UNKNOWN') 

        if addr in self.allowed_addresses: # pass through to the next app
            return self.app(environ, start_response)
        else: # put up a response denied
            start_response(
                '403 Forbidden', [('Content-type', 'text/html')])
            return ['You are forbidden to view this resource']

addresses = [ '127.0.0.1' ]
simple_app_with_auth = AuthenticationMiddleware(Simple_App, addresses)

if __name__ == '__main__': 

    httpd = make_server('', 8000, simple_app_with_auth)
    print "Serving HTTP on port 8000..."

    # Respond to requests until process is killed
    httpd.serve_forever()
