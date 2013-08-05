import pprint
import os, urllib2, tempfile

ez = {}

tmpeggs = tempfile.mkdtemp()

print 'tmpeggs=%s' %tmpeggs

exec urllib2.urlopen('http://peak.telecommunity.com/dist/ez_setup.py').read() in ez

print dir(ez['use_setuptools'])

ez['use_setuptools'](to_dir=tmpeggs, download_delay=0)
