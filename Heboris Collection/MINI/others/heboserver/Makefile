# mingw32-make Makefile (EXE Console)
# Setting
TARGET = heboserver.exe
OBJ    = heboserver.o
CFLAGS = -finput-charset=cp932 -fexec-charset=cp932 -Wall -g0 -O3
LIB    = -mwindows -mconsole -lws2_32
CC     = gcc
CPP    = g++
RM     = del
STRIP  = strip

# PHONY Targets
.PHONY: all clean

all: $(TARGET)

clean:
	-$(RM) $(OBJ) $(TARGET)

# Main rules
$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $@
	$(STRIP) -s $@

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

.cpp.o:
	$(CPP) $(CFLAGS) -o $@ -c $<
