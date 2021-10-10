# Usage:
# mingw32-make					# build DragonsBane.exe
# mingw32-make run			# run DragonsBane.exe
# mingw32-make clean		# remove ALL binaries and objects

#Windows detector - find rm in PATH
ifeq ($(wildcard $(addsuffix /rm,$(subst :, ,$(PATH)))),)
	WINMODE=1
else
	WINMODE=0
endif

.PHONY = all run clean

# Compiler to use
CXX = g++

# Flags
SRCS_FLAGS = -g -std=c++11 -Iinclude


OBJS := Maze.o Element.o MoveableElement.o Hero.o Dragon.o Game.o

###########################################################
ifeq ($(WINMODE),1)  # native windows:
###########################################################

all: DragonsBane.exe

run: DragonsBane.exe
	.\$<

DragonsBane.exe: src\main.cpp $(OBJS)
	${CXX} ${SRCS_FLAGS} $< $(OBJS) -o $@

%.o: src\dkeep\logic\%.cpp
	@echo "Creating object $@.."
	${CXX} ${SRCS_FLAGS} -c $^

clean:
	@echo "Cleaning up..."
	del /f *.o *.exe

###########################################################
else #Unix like
###########################################################

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
