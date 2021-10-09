# Usage:
# mingw32-make       # compile ALL binaries
# mingw32-make clean # remove ALL binaries and objects
#
# Execute the file:
# - .\HereBeDragons (in a cmd)
# - OR Open HereBeDragons.exe
# Source: https://opensource.com/article/18/8/what-how-makefile
#
# Future developments:
# - verify if the Makefile is compatible with input arguments of mingw32-make
#   (see mingw32-make --help)
# - automate the build of the source files (almost the same commands copied for
#   each source file...)

.PHONY = all clean

# Compiler to use
CXX = g++

# Flags
SRCS_FLAGS = -g -Iinclude
LINKERFLAG = -lm



# Compile ALL binaries
all: HereBeDragons.exe

# $@ matches target (%)
# $< matches prerequisites (%.o), where target: prerequisites
HereBeDragons.exe: src\main.cpp
	${CXX} ${SRCS_FLAGS} $< -o $@



# Remove ALL binaries and objects
clean:
	@echo "Cleaning up..."
	del /f *.o *.exe