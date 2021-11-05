#!/bin/sh
status=$(
awk -F"[][]" '/Left:/ { print $2 }' <(amixer sget Master)
)
conn=$(xrandr -q | grep ' connected' | head -n 1 | cut -d ' ' -f1)
a=$(xrandr --verbose --current | grep ^$conn -A5 | tail -n1)
curb="${a##* }"
echo "" $curb "|"
