# How do I make dwm appear on my display manager?

As root create a file like this:

    $ cat /usr/share/xsessions/dwm.desktop
    [Desktop Entry]
    Encoding=UTF-8
    Name=dwm
    Comment=Dynamic window manager
    Exec=dwm
    Icon=dwm
    Type=XSession

with these permissions

    $ ls -l /usr/share/xsessions/dwm.desktop
    -rw-r--r-- 1 root root 108 Jun 27 17:24 /usr/share/xsessions/dwm.desktop
