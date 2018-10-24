.PHONY: all tests test

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
CFLAGS += -pthread

SRC_FILES = Unity/src/unity.c ../app_data.c 
SRC_FILES += ../os_port/linux/os_port_linux.c

INC_DIRS ?= -IUnity/src -I../ -I../os_port -I../os_port/linux

TEST_SRC = $(wildcard *.c)
TEST_BIN=$(addprefix output/, $(TEST_SRC:.c=.bin))

all: clean tests test

output/%.bin: %.c
	@mkdir -p output
	@echo compiling $@ ...
	@$(CC) $(CFLAGS) $(INC_DIRS) $< $(SRC_FILES)  -o $@
	chmod +x $@

tests: $(TEST_BIN)

test: tests
	@for f in $(TEST_BIN); do ./$$f; done

clean:
	rm -rf output
