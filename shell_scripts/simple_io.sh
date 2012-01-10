#!/bin/bash
# set -xe
# "NULL variable is variable which has no value at the time of definition"

vech=   # NULL variable
bech="" # NULL variable

###################################################

# Syntax:
# read variable1, variable2,...variableN

# read fname

# echo "Hello $fname, lets be friend"

##################################################

# Command line Processing
# "$#" holds number of arguments specified on command line.
# "$*" or "$@" refer to all arguments passed to script.
# $0, $1, $2...

# print all the command line arguments
# to understand the difference between $* and $@
# input: $0 "hello world" myscript

echo '$#:'$#
for i in $*
do
        echo $i
done

for i in "$@"
do
        echo $i
done
