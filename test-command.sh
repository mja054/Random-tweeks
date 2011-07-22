#!/bin/bash

# test command or [ expr ] is used to see if an expression is true,
# and if it is true it return zero(0), otherwise returns nonzero for false.
# Syntax:
# test expression OR [ expression ]

# test or [ expr ] works with
# 1.Integer ( Number without decimal point)
# 2.File types
# 3.Character strings

# For Mathematics, use following operator in Shell Script
# -eq     is equal to                 5 == 6  if test 5 -eq 6 if [ 5 -eq 6 ]
# -ne     is not equal to             5 != 6  if test 5 -ne 6 if [ 5 -ne 6 ]
# -lt     is less than                5 < 6   if test 5 -lt 6 if [ 5 -lt 6 ]
# -le     is less than or equal to    5 <= 6  if test 5 -le 6 if [ 5 -le 6 ]
# -gt     is greater than             5 > 6   if test 5 -gt 6 if [ 5 -gt 6 ]
# -ge     is greater than or equal to 5 >= 6  if test 5 -ge 6 if [ 5 -ge 6 ]

# For string Comparisons use
# string1 = string2       string1 is equal to string2
# string1 != string2      string1 is NOT equal to string2
# string1                 string1 is NOT NULL or not defined
# -n string1              string1 is NOT NULL and does exist
# -z string1              string1 is NULL and does exist

#Shell also test for file and directory types
# -s file         Non empty file
# -f file         Is File exist or normal file and not a directory
# -d dir          Is Directory exist and not a file
# -w file         Is writeable file
# -r file         Is read-only file
# -x file         Is file is executable

# Logical operators are used to combine two or more condition at a time
# ! expression                    Logical NOT
# expression1  -a  expression2    Logical AND
# expression1  -o  expression2    Logical OR
