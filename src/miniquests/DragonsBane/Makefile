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

#Windows detector - find rm in PATH
ifeq ($(wildcard $(addsuffix /rm,$(subst :, ,$(PATH)))),)
	WINMODE=1
else
	WINMODE=0
endif

.PHONY = all clean

# Compiler to use
CXX = g++

# Flags
SRCS_FLAGS = -g -Iinclude
LINKERFLAG = -lm


OBJS := Maze.o Element.o MoveableElement.o Hero.o Dragon.o Game.o

###########################################################
ifeq ($(WINMODE),1)  # native windows:
###########################################################

all:  DragonsBane.exe

run: DragonsBane.exe
	.\$<

DragonsBane.exe: src\main.cpp $(OBJS)
	${CXX} ${SRCS_FLAGS} $< $(OBJS) -o $@

%.o: src\dkeep\logic\%.cpp
	@echo "Creating object $@.."
	${CXX} ${SRCS_FLAGS} -c $^

# Remove ALL binaries and objects
clean:
	@echo "Cleaning up..."
	del /f *.o *.exe

###########################################################
else #Unix like
###########################################################

#Flag required to compile with Apple clang version
SRCS_FLAGS += -std=c++11

all:  DragonsBane

run: DragonsBane
	./$<

DragonsBane: src/main.cpp $(OBJS)
	${CXX} ${SRCS_FLAGS} $< $(OBJS) -o $@

%.o: src/dkeep/logic/%.cpp
	@echo "Creating object $@.."
	${CXX} ${SRCS_FLAGS} -c $^

clean:
	@echo "Cleaning up..."
	rm -f *.o DragonsBane

###########################################################
endif
###########################################################
