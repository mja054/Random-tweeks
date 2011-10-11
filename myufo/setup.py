#!/usr/bin/python

from setuptools import setup, find_packages
import os

setup(
        name='myufo',
        version='0.0.1',
        description='UFO-Clone',
        author='Junaid',
        author_email='junaid@gluster.com',
        packages=find_packages(exclude=['bin']),
        classifiers=[
            "Development Status :: 3 - Alpha",
            "Topic :: Utilities",
            "License :: MIT",
        ],
        scripts=[
            'bin/myufo-init',
            'bin/myufo-start',
            'bin/myufo-proxy-server'
        ],
    entry_points={
        'paste.app_factory': [
            'proxy=myufo.proxy.server:app_factory',
            ],
        },
)
