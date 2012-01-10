#!/bin/bash

sed -E 's/\([a-z]+\) \([a-z]+\)/\2 \1/' foo.in
