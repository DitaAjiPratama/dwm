#!/bin/sh

status=$(
awk -F"[][]" '/Left:/ { print $2 }' <(amixer sget Master)
)
echo "" $status "|"
