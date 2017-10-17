#!/bin/sh
# run as root before the login dialog appears
if  [ ! -f /var/run/eta-coser.pid ] ; then
    if [ ! -e /bin/live-boot ] && [ ! -e /bin/live-config ] ; then
        if [ -f /boot/efi/EFI/microsoft/BOOT/bootmgfw.efi ] || grep -q "Windows" /boot/grub/grub.cfg ; then
            touch /var/run/eta-coser.pid
            sleep 7
            /usr/bin/eta-coser
        fi
    fi
else
    echo "etacoser.pid found"
fi
