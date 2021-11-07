#!/bin/bash

conn=$(xrandr -q | grep ' connected' | head -n 1 | cut -d ' ' -f1)
a=$(xrandr --verbose --current | grep ^$conn -A5 | tail -n1)
curb="${a##* }"

[ "$curb" == "0.90" ] && xrandr --output $conn --brightness 1.0
[ "$curb" == "0.80" ] && xrandr --output $conn --brightness 0.9
[ "$curb" == "0.70" ] && xrandr --output $conn --brightness 0.8
[ "$curb" == "0.60" ] && xrandr --output $conn --brightness 0.7
[ "$curb" == "0.50" ] && xrandr --output $conn --brightness 0.6
[ "$curb" == "0.40" ] && xrandr --output $conn --brightness 0.5
[ "$curb" == "0.30" ] && xrandr --output $conn --brightness 0.4
[ "$curb" == "0.20" ] && xrandr --output $conn --brightness 0.3
[ "$curb" == "0.10" ] && xrandr --output $conn --brightness 0.2

echo $curb
