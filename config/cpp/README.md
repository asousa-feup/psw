# cpp

Configuration of a C/C++ development environment in Windows. This configuration
is meant for the text editor Visual Studio Code - VS Code
(source: https://code.visualstudio.com/docs/languages/cpp).

## Install the C/C++ extension

1. Open VS Code
2. Select the Extensions view on the Activity bar (left-side ribbon) or use the
   keyboard shortcut (`Ctrl+Shift+X`) or use the menu (View > Extensions)
3. Search for `'C++'`
4. Install the following extensions:
   - C/C++ by Microsoft
   - C/C++ Extension Pack by Microsoft (optional)

## Install a compiler (MinGW-x64)

1. Go to [MSYS2](https://www.msys2.org/)
2. Download the installer `msys2-x86_64....exe`
3. Run the installer
4. Enter your desired Installation Folder (**Note:** ASCII-only, no accents, no
   spaces)
5. Run MSYS2 64bit and update the package database and base packages:

```sh
# Open MSYS2 MSYS
pacman -Syu
# Open MSYS2 MSYS from the start menu
pacman -Su
```

6. Install some tools and the mingw-w64 GCC to start compiling:

```sh
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
# Enter 2 times for default option 'all' and then Y
```

## Configure the MinGW compiler

Add the path of your MinGW-w64 `bin` folder to the Windows `PATH` environment
variable by using the following steps:

1. Windows search bar `'settings'`
2. Search `'Edit environment variables for your account'`
3. Choose the `Path` variable and the select Edit
4. Select New and add the MinGW-w64 destination folder path, with `\mingw64\bin`
   appended. The path depends on which version of MinGW-w64 you have installed
   it. If you use the settings above to install MinGW-64, then add this to the
   path: `C:\msys64\mingw64\bin`
5. Select OK to save the updated `PATH`. You need to reopen any consele for the
   new `PATH` location to be available

## Check if your MinGW installation is correctly installed

Open a New command prompt (e.g., in VS Code, Terminal > New Terminal - make sure
that it is a command prompt and not a bash terminal):

```sh
$ g++ --version
g++ (Rev5, Built by MSYS2 project) 10.3.0
Copyright (C) 2020 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

$ gdb --version
GNU gdb (GDB) 10.2
Copyright (C) 2021 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
```

## Check if your MinGW installation is installed and configured correctly in VS Code

1. Open the HelloWorld example
2. Build HelloWorld
   - Terminal > Run Build Task
   - C/C++: g++.exe build active file
   - Check if a `helloworld.exe` file was created
3. Run HelloWorld
   - Open Command Prompt (Terminal > New Terminal)
   - Type `.\helloworld` and press enter
   - Output expected:

```sh
Hello World
Welcome to Software Design (PSW) 2021/2022

```

## Configuring CMake Tools (optional, but preferred)

Source: https://vector-of-bool.github.io/docs/vscode-cmake-tools/settings.html

1. Open VS Code Settings (File > Preferences > Settings)
2. Extensions > CMake Tools configuration
3. Set the path of your MinGW installation:
   - `C:\mingw-w64\mingw64\bin`
