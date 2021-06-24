#!/bin/sh
a=""
b=""

status=$(cat /sys/class/power_supply/BAT0/status)
if [ $status = "Charging" ]; then
    a=""
elif [ $status = "Discharging" ]; then
    a=""
else
    a=" "
fi

cap=$(cat /sys/class/power_supply/BAT0/capacity)
if [ $cap -ge 0 ] && [ $cap -le 20 ]; then
    b=""
elif [ $cap -ge 21 ] && [ $cap -le 40 ]; then
    b=""
elif [ $cap -ge 41 ] && [ $cap -le 60 ]; then
    b=""
elif [ $cap -ge 61 ] && [ $cap -le 90 ]; then
    b=""
elif [ $cap -ge 91 ] && [ $cap -le 100 ]; then
    b=""
else
    b=""
fi

if [$cap -ge 0] && [$cap -le 100]; then
	echo $a $b $status $cap "|"
else
	echo " |"
fi
