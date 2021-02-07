feh --bg-scale ~/dwm/wallpaper/8913281_p0.jpg

while true; do
        xsetroot -name " $(sh ./autostart/battery.sh) |  $(date +'%F %R') "
    sleep 1
done

