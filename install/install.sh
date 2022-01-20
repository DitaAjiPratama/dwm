sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get dist-upgrade -y
sudo apt-get autoremove -y

sudo apt-get install -y git xorg libx11-dev libxft-dev libxinerama-dev xdm suckless-tools dmenu
sudo apt-get install -y feh rofi kitty thunar scrot calcurse htop pavucontrol

git clone https://github.com/DitaAjiPratama/dwm.git ~/.dwm

cd ~/.dwm
sudo make clean install

echo "exec -dwm" > ~/.xsession
