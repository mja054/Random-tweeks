#!/bin/bash

cd /tmp
mkdir rpm-download
cd rpm-download

for i in `cat $1 | grep rpm  | sed 's/.*href=\"\(.*rpm\)\">.*/\1/'`
do
    echo $i
#    wget -c $i
done
