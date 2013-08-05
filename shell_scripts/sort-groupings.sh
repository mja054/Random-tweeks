#!/bin/bash

while read line
do
    if [ -z "$line" ]
    then
	echo "$line" >> output
	continue
    fi

    header=`echo $line | cut -f1 -d'-'`
    cont=`echo $line | cut -f2 -d'-'`

    x=
    for i in `echo $cont | sed 's/,/\n/g' | sort`
    do 
	if [ -z "$x" ]
	then 
	    x=$i
	else
	    x="$x, $i"
	fi
    done

    jnk=`echo $line | grep ^[A-Z]`
    if [ $? -eq 0 ]
    then
    	echo "$header- $x" >> output
    else
    	echo "  $header - $x" >> output
    fi
done < input
