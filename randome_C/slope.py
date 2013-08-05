#!/usr/bin/python

str_range = int(raw_input())
end_range = int(raw_input())

# swapping the numbers to make sure str_range is always
# smaller than end_range
if str_range > end_range:
    str_range, end_range = end_range, str_range

sl = 0

while str_range <= end_range:
    num = str(str_range)
    if str_range < 0:
        num = num[1:]

    start = 0
    end = 3

    s = num[start : end]
    while len(s) == 3:
        if s[1] > s[0] and s[1] > s[2]:
            sl = sl + 1
        elif s[1] < s[0] and s[1] < s[2]:
            sl = sl + 1
        start = start + 1
        end   = end   + 1
        s     = num[start : end]

    print "%d: %d" %(str_range, sl)
    str_range = str_range + 1

print sl
