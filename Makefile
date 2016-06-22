.PHONY: all

all: compile link run


INCLUDE_DIR = Include
LIB_DIR = Lib

# Compiler
CC = gcc
CSTANDARD = c99
INCLUDES = -I$(INCLUDE_DIR)
LIBS = -L$(LIB_DIR)
override CFLAGS += -std=$(CSTANDARD) -Wall -Werror $(INCLUDES) $(LIBS)

# Final executable
OUTPUT = main

EXE = App/main.c

HEADERS = \
	$(INCLUDE_DIR)/All.h \
	$(INCLUDE_DIR)/types.h \
	$(INCLUDE_DIR)/functions.h \
	$(INCLUDE_DIR)/Object.h \
	$(INCLUDE_DIR)/String.h \
	$(INCLUDE_DIR)/List.h \
	$(INCLUDE_DIR)/LinkedList.h

OBJECTS = \
	$(LIB_DIR)/functions.o \
	$(LIB_DIR)/Object.o \
	$(LIB_DIR)/String.o \
	$(LIB_DIR)/LinkedList.o

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

valgrind:
	valgrind --leak-check=yes ./$(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT)

test: EXE = App/test.c
test: clean debug valgrind

