# mingw32-make—p‚ÌMakefile
TARGET    = ygs2kTCP.dll
OBJ       = ygs2kTCP.o
CFLAGS    = -finput-charset=cp932 -fexec-charset=cp932 -Wall -g0 -O3
LIB       = -mwindows -lws2_32
CC        = gcc
CPP       = g++
RM        = del
STRIP     = strip

# PHONY
.PHONY: all clean

all: $(TARGET)

clean:
	-$(RM) $(OBJ) $(TARGET)

# Rules
$(TARGET): $(OBJ)
	$(CC) -shared -o $@ -Wl, $(OBJ) $(LIB)
	$(STRIP) -s $@

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.cpp.o:
	$(CPP) $(CFLAGS) -o $@ -c $<
