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


SRC_FILES = $(UNITY_SRC) ../app_data.c 
INC_DIRS ?= -Iunity/src -I../

TEST_SRC = $(wildcard *.c)
TEST_BIN = $(TEST_SRC:.c=.bin)

all: clean test

$(TEST_BIN): $(TEST_SRC)
	$(CC) $(CFLAGS) $(INC_DIRS) $(SRC_FILES) $< -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

clean:
	rm -f $(TEST_BIN)
