#!/bin/sh
#status=$(
#pactl list sinks | grep '^[[:space:]]Volume:' | \
#    head -n $(( $SINK + 1 )) | tail -n 1 | sed -e 's,.* \([0-9][0-9]*\)%.*,\1,'
#)
status=$(
awk -F"[][]" '/Left:/ { print $2 }' <(amixer sget Master)
)
echo "" $status "|"
