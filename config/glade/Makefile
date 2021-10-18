# Usage:
# mingw32-make					# build
# mingw32-make run			# run
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
SRCS_FLAGS = -g -std=c++11
GTK_FLAGS = -IC:/msys64/mingw64/bin/../include/gtkmm-3.0 -IC:/msys64/mingw64/bin/../lib/gtkmm-3.0/include -IC:/msys64/mingw64/bin/../include/giomm-2.4 -IC:/msys64/mingw64/bin/../lib/giomm-2.4/include -IC:/msys64/mingw64/bin/../include -IC:/msys64/mingw64/bin/../include/glib-2.0 -IC:/msys64/mingw64/bin/../lib/glib-2.0/include -mms-bitfields -IC:/msys64/mingw64/bin/../include/glibmm-2.4 -IC:/msys64/mingw64/bin/../lib/glibmm-2.4/include -IC:/msys64/mingw64/bin/../include/sigc++-2.0 -IC:/msys64/mingw64/bin/../lib/sigc++-2.0/include -IC:/msys64/mingw64/bin/../include/gtk-3.0 -IC:/msys64/mingw64/bin/../include/pango-1.0 -IC:/msys64/mingw64/bin/../include/harfbuzz -IC:/msys64/mingw64/bin/../include/freetype2 -IC:/msys64/mingw64/bin/../include/libpng16 -mms-bitfields -IC:/msys64/mingw64/bin/../include/fribidi -IC:/msys64/mingw64/bin/../include/cairo -IC:/msys64/mingw64/bin/../include/lzo -IC:/msys64/mingw64/bin/../include/pixman-1 -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -IC:/msys64/mingw64/bin/../include/gdk-pixbuf-2.0 -mms-bitfields -mms-bitfields -mms-bitfields -IC:/msys64/mingw64/bin/../include/atk-1.0 -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -IC:/msys64/mingw64/bin/../include/cairomm-1.0 -IC:/msys64/mingw64/bin/../lib/cairomm-1.0/include -IC:/msys64/mingw64/bin/../include/pangomm-1.4 -IC:/msys64/mingw64/bin/../lib/pangomm-1.4/include -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -IC:/msys64/mingw64/bin/../include/atkmm-1.6 -IC:/msys64/mingw64/bin/../lib/atkmm-1.6/include -IC:/msys64/mingw64/bin/../include/gdkmm-3.0 -IC:/msys64/mingw64/bin/../lib/gdkmm-3.0/include -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -mms-bitfields -pthread -mms-bitfields -LC:/msys64/mingw64/bin/../lib -lgtkmm-3.0 -latkmm-1.6 -lgdkmm-3.0 -lgiomm-2.4 -lgtk-3 -lgdk-3 -lz -lgdi32 -limm32 -lshell32 -lole32 -Wl,-luuid -lwinmm -ldwmapi -lsetupapi -lcfgmgr32 -lpangowin32-1.0 -latk-1.0 -lcairo-gobject -lgio-2.0 -lpangomm-1.4 -lglibmm-2.4 -lcairomm-1.0 -lsigc-2.0 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -lcairo -lgdk_pixbuf-2.0 -lgobject-2.0 -lglib-2.0 -lintl



###########################################################
ifeq ($(WINMODE),1)  # native windows:
###########################################################

all: Main.exe

run: Main.exe
	.\$<

Main.exe: main.cpp
	${CXX} ${SRCS_FLAGS} $< -o $@ ${GTK_FLAGS}

clean:
	@echo "Cleaning up..."
	del /f *.o *.exe

###########################################################
else #Unix like
###########################################################

all: Main

run: Main
	./$<

Main: main.cpp
	${CXX} ${SRCS_FLAGS} ${GTK_FLAGS} $< -o $@

clean:
	@echo "Cleaning up..."
	rm -f *.o Main

###########################################################
endif
###########################################################
