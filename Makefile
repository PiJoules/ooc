.PHONY: all

all: compile link


INCLUDE_DIR = Include
LIB_DIR = Lib

# Compiler
CC = gcc
CSTANDARD = c99
INCLUDES = -I$(INCLUDE_DIR)
LIBS = -L$(LIB_DIR)
override CFLAGS += -std=$(CSTANDARD) -Wall $(INCLUDES) $(LIBS)

# Final executable
OUTPUT = main

EXE = App/main.c

HEADERS = \
	$(INCLUDE_DIR)/Set.h \
	$(INCLUDE_DIR)/new.h \
	$(INCLUDE_DIR)/Object.h

OBJECTS = \
	$(LIB_DIR)/BagSet.o
	#$(LIB_DIR)/Set.o

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(LIB_DIR)/*.o
	rm -f $(OUTPUT)

compile: $(OBJECTS)

link: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(EXE) $(OBJECTS)

debug: CFLAGS += -DDEBUG
debug: all

