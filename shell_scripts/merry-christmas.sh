#!/bin/bash

#lights_off
#
#          *==<
#           /\
#          /  \
#         / @  \
#        /      \
#       / @    @ \
#           ||
#
#Team CodeChef wishes you all 
#
#      A MERRY CHRISTMAS
#            AND
#      A HAPPY NEW YEAR!
#

#lights_on
#
#          *==<
#           /\
#          / *\
#         / @  \
#        / *  * \
#       / @  * @ \
#           ||
#
#Team CodeChef wishes you all
#
#      A MERRY CHRISTMAS
#            AND
#      A HAPPY NEW YEAR!
#
frows=16;
stime=1;
which tput >/dev/null || alias tput="clear";

display(){
    tput cup 0 0;
    grep -A$frows \#"$1" "$0" | tail -n$frows | sed 's/#/\ /';
}

animation(){
     display lights_off && sleep $stime;
     display lights_on && sleep $stime
}

clear;
yes | while read i;
do animation;
done;
