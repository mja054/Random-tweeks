urls = ["http://eventlet.net/doc/patching.html#import-green",
        "http://eventlet.net/doc/examples.html#web-crawler-example",
        "http://eventlet.net/doc/design_patterns.html"]

import eventlet
from eventlet.green import urllib2  

def fetch(url):
  print "opening", url
  body = urllib2.urlopen(url).read()
  print "done with", url
  return url, body

pool = eventlet.GreenPool(200)
for url, body in pool.imap(fetch, urls):
  print "got body from", url, "of length", len(body)
