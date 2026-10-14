CC      := gcc
CFLAGS  := -std=c11 -Wall -Wextra -Wpedantic -g
SRC     := $(wildcard [0-9][0-9]_*.c)
BIN     := $(patsubst %.c,build/%,$(SRC))

.PHONY: all run clean

all: $(BIN)

build/%: %.c | build
	$(CC) $(CFLAGS) $< -o $@

build:
	mkdir -p build

# Run one program:  make run P=03
run: all
	@./build/$(P)_*

clean:
	rm -rf build
