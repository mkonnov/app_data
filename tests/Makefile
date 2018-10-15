.PHONY: all 

UNITY_SRC = unity/src/unity.c

CC = gcc

CFLAGS=-std=c11
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition


SRC_FILES = $(UNITY_SRC) ../app_data.c $(wildcard *.c)
INC_DIRS ?= -Iunity/src -I../

all: clean test

test:
	$(CC) $(CFLAGS) $(INC_DIRS) $(SRC_FILES) -o test.bin

clean:
	rm -f test.bin
