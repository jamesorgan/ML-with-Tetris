# mingw32-make Makefile (EXE)
# Setting
TARGET  = heboplugin.exe
OBJ     = heboplugin.o
RES     = resource.res
RC      = resource.rc
CFLAGS  = -finput-charset=cp932 -fexec-charset=cp932 -Wall -g0 -O3
LIB     = -lshlwapi -mwindows
WFLAGS  = --language=0411 -O coff
CC      = gcc
CPP     = g++
RM      = del
STRIP   = strip
WINDRES = windres

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
