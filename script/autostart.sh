feh --bg-fill ~/Pictures/Wallpapers/saber-alter-two-handed-sword-blonde-dress-armor-fate-grand-order-transformation-29836-3840x2160.jpeg

xrandr --output HDMI-2 --auto --left-of DP-1

while true; do
	xsetroot -name " $(bash ./brightness.sh) $(bash ./volume.sh) $(sh ./battery.sh)$(sh ./time.sh)  "
	#xsetroot -name " $(sh ./volume.sh) $(sh ./time.sh)  "
	sleep 1
done

