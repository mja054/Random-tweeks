#!/bin/bash
set -x

if [ $# -ne 1 ]
then
    echo "usage: $0 <c++ filename>"
    exit 0
fi

cp template.cpp $1
