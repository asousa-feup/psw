# glade

## Get started

### MinGW

See other tutorials to install and configure MinGW in Windows.

### Install Glade

1. Open MSYS2 MSYS
2. Execute the following commands

```sh
# Install GTK3 and its dependencies
pacman -S mingw-w64-x86_64-gtk3
pacman -S mingw-w64-x86_64-gtkmm3
pacman -S pkg-config
# Install Glade
pacman -S mingw-w64-x86_64-glade
```

3. (optional) Follow the steps described in https://www.gtk.org/docs/installations/windows#building-and-distributing-your-application
   if you want to use a Windows 10 theme in Glade
4. Open Glade (Start Menu > Search `glade` > Select execute `glade` command)

## Design interfaces

Source:

- https://www.youtube.com/watch?v=g-KDOH_uqPk&ab_channel=KevinO%27Kane
