#!/bin/bash

# for Loop
# Syntax:
#  for { variable name } in { list }
#  do
#           execute one for each item in the list until the list is
#           not finished (And repeat all statement between do and done)
#  done

# while loop
# Syntax:
#   while [ condition ]
#   do
#         command1
#         command2
#         command3
#         ..
#         ....
#    done

# Case Statement
# The case statement is good alternative to Multilevel if-then-else-fi statement.
# It enables you to match several values against one variable. Its easier to read
# and write.
# Syntax:
#   case  $variable-name  in
#        pattern1)   command
#                        ...
#                        ..
#                        command;;
#        pattern2)   command
#                        ...
#                        ..
#                        command;;
#        patternN)   command
#                        ...
#                        ..
#                        command;;
#        *)             command
#                        ...
#                        ..
#                        command;;
#   esac

# Example-1
# for i in {1..10}
# do
#     echo $i
# done

# Example-2
# for (( i = 1; i <= 9; i++ )) ### Outer for loop ###
# do
#    for (( j = 1 ; j <= 9; j++ )) ### Inner for loop ###
#    do
#         tot=`expr $i + $j`
#         tmp=`expr $tot % 2`
#         if [ $tmp -eq 0 ]; then
#             echo -e -n "\033[47m "
#         else
#             echo -e -n "\033[40m "
#         fi
#   done
#  echo -e -n "\033[40m" #### set back background colour to black
#  echo "" #### print the new line ###
# done
