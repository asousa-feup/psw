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

###########################################################
ifeq ($(WINMODE),1)  # native windows:
###########################################################
# Compile ALL binaries
all: HereBeDragons.exe

run: HereBeDragons.exe
	.\$<

# $@ matches target (%)
# $< matches prerequisites (%.o), where target: prerequisites
HereBeDragons.exe: src\main.cpp
	${CXX} ${SRCS_FLAGS} $< -o $@

# Remove ALL binaries and objects
clean:
	@echo "Cleaning up..."
	del /f *.o *.exe

###########################################################
else #Unix like
###########################################################

all: HereBeDragons

run: HereBeDragons
	./$<

HereBeDragons: src/main.cpp
	${CXX} ${SRCS_FLAGS} $< -o $@

clean:
	@echo "Cleaning up..."
	rm -f *.o HereBeDragons

###########################################################
endif
###########################################################
