feh --bg-scale ~/.dwm/wallpaper/8913281_p0.jpg

while true; do
	xsetroot -name " $(bash ./brightness.sh) $(bash ./volume.sh) $(sh ./battery.sh) $(sh ./time.sh)  "
	#xsetroot -name " $(sh ./volume.sh) $(sh ./time.sh)  "
	sleep 1
done

