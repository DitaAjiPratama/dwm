$(bash ./wallpaper.sh)
$(bash ./display.sh)

while true; do
	xsetroot -name " $(bash ./brightness.sh) $(bash ./volume.sh) $(sh ./battery.sh)$(sh ./time.sh)  Aji DAP "
	sleep 1
done

