# mingw32-make Makefile (EXE GUI Application)
# Setting
TARGET  = heboserver_tray.exe
OBJ     = heboserver_tray.o
RES     = resource.res
RC      = resource.rc
CFLAGS  = -finput-charset=cp932 -fexec-charset=cp932 -Wall -g0 -O3
LIB     = -mwindows -lws2_32
WFLAGS  = --language=0411 -O coff
CC      = gcc
CPP     = g++
WINDRES = windres
RM      = del
STRIP   = strip

# PHONY Targets
.PHONY: all clean

all: $(TARGET)

clean:
	-$(RM) $(OBJ) $(RES) $(TARGET)

# Main rules
$(TARGET): $(OBJ) $(RES)
	$(CC) $(OBJ) $(RES) $(LIB) -o $@
	$(STRIP) -s $@

$(RES):
	$(WINDRES) $(WFLAGS) -o $(RES) $(RC)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.cpp.o:
	$(CPP) $(CFLAGS) -o $@ -c $<
