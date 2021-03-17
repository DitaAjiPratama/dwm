feh --bg-scale ~/.dwm/wallpaper/8913281_p0.jpg

while true; do
  xsetroot -name "  $(sh ./volume.sh) | $(sh ./battery.sh) | $(date +'%F %R') |  "
done

