#!/bin/sh
set -ex

# Syntax: expr   op1   operator   op2
# Where, op1 and op2 are any Integer Number (Number without decimal point) and
# "space is required between number and operator".
# operator can be
# + Addition
# - Subtraction
# / Division
# % Modular, to find remainder For e.g. 20 / 3 = 6 , to find remainder 20 % 3 = 2,
# % (Remember its integer calculation)
# \* Multiplication

x=10
y=20

z=`expr $x + $y`

z=`expr $y / $x`
