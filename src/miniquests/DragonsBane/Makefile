# Usage:
# mingw32-make       # compile ALL binaries
# mingw32-make clean # remove ALL binaries and objects
#
# Execute the file:
# - .\DragonsBane (in a cmd)
# - OR Open DragonsBane.exe
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
all: Maze.o Element.o Hero.o Dragon.o Game.o DragonsBane.exe

# $@ matches target (%)
# $< matches prerequisites (%.o), where target: prerequisites
Maze.o: src\dkeep\logic\Maze.cpp
	@echo "Creating object Maze.o.."
	${CXX} ${SRCS_FLAGS} -c $<

Element.o: src\dkeep\logic\Element.cpp
	@echo "Creating object Element.o.."
	${CXX} ${SRCS_FLAGS} -c $<

Hero.o: src\dkeep\logic\Hero.cpp
	@echo "Creating object Hero.o.."
	${CXX} ${SRCS_FLAGS} -c $<

Dragon.o: src\dkeep\logic\Dragon.cpp
	@echo "Creating object Dragon.o.."
	${CXX} ${SRCS_FLAGS} -c $<

Game.o: src\dkeep\logic\Game.cpp
	@echo "Creating object Game.o.."
	${CXX} ${SRCS_FLAGS} -c $<


DragonsBane.exe: src\main.cpp
	${CXX} ${SRCS_FLAGS} $< Maze.o Element.o Hero.o Dragon.o Game.o -o $@



# Remove ALL binaries and objects
clean:
	@echo "Cleaning up..."
	del /f *.o *.exe