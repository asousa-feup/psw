# HereBeDragons

This mini-quest portrays the classical situation of "The Maze and The Dragon".
The mini-quest is implemented in C++ and was compiled in VS Code. See the
[`guide`](doc/lprog_mini-quest-1_here-be-dragons.pdf) for more information about
the mini-quest.

Only the common part of the mini-quest is implemented in C++, just as in the
Java version ([video](https://www.youtube.com/watch?v=8EgeWkYzCkg)). The YouTube
video for the latter is also valid for C++ in terms of logic and program
structure.

## Get started

### Compile and run the program

The first option is using the build and running tasks in VS Code. You must
follow the following steps:

1. Open the file `main.cpp`
2. Terminal > Add Configuration: `C++ (GDB/LLDB)`
3. Run program
   - Run wo/debugging: Run > Run Without Debugging
   - Run w/debugging: Run > Start Debugging

**Note 1:** the files `.vscode/launch.json` and `.vscode/tasks.json` can be
modified to not generating the main.exe inside the `src` folde. Check the ones
already present in this project.

**Note 2:** the method shown in the configuration of C++ did not seemed to worked
for this example. The followinf DLL were not found:

- `libgcc_s_seg-1.dll`
- `libstdc++-6.dll`

Another method is using the extension CMake Tools (included in the C/C++
Extension Pack). This method sould be the preferred one given the similary of
building C/C++ project in other platforms
(source: https://code.visualstudio.com/docs/cpp/CMake-linux):

1. Open the Command Pallet (`Ctrl+Shift+P`)
2. !!!`NOT WORKING`!!!

**Note:** make sure the binaries of your MinGW installation are added to the
`PATH` variable (when typing `g++ --version` or `gcc --version` in a Command
Prompt, it should appear the respective installation versions).
