#Copyright (C) 2015 Barajas D. Paul <Paul.Barajas@linux.com>

CC = gcc
CFLAGS = -Wall
LIB = -L
LDFLAGS=
SOURCES = main.c gui_interface.c
DEPS = gui_interface.h
GTK_LIBS=`pkg-config --libs --cflags gtk+-2.0`
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=Vision

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIB) $(DEPS) $(GTK_LIBS)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@  $(LIB) $(DEPS) $(GTK_LIBS)

clean:
	rm $(OBJECTS) $(EXECUTABLE)
