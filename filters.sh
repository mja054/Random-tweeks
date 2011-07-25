#!/bin/bash

# Metacharacters defined as:
# "If patterns are identified using special characters then such special characters are know as metacharacters".

# expressions defined as:
# "Combination of pattern and metacharacters is know as expressions (regular expressions)."
# Regular expressions are used by different Linux utilities like
#   * grep
#   * awk
#   * sed

# join {file1} {file2}
# paste {file1} {file2}

# Translateing range of characters using "tr" utility
# $ tr "h2" "3x" < sname
# each occurrence of character 'h' is replace with '3' and '2' with 'x'.
# h -> 3
# 2 -> x

# $ tr "[a-z]" "[A-Z]"

# SED
# sed {expression} {file}
# $ sed '/tea/s//milk/g' teaormilk

# "uniq"-Removing duplicate lines using uniq utility

# "awk" utility is powerful data manipulation/scripting programming language (In
# fact based on the C programming Language). Use awk to handle complex task such
# as calculation, database handling, report creation etc.
# Syntax:
#       awk -f {awk program file} filename
#       awk program contains:
#       patern {
#               action 1
#               action 2
#               action N
#       }
#       Metacharacter   Meaning
#       . (Dot)         Match any character
#       *               Match zero or more character
#       ^               Match beginning of line
#       $               Match end of line
#       \               Escape character following
#       [ ]             List
#       { }             Match range of instance
#       +               Match one more preceding
#       ?               Match zero or one preceding
#       |               Separate choices to match
