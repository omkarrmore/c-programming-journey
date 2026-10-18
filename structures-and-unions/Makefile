CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -std=gnu11
SRCS    := $(wildcard */*.c)
BINS    := $(patsubst %.c,bin/%,$(SRCS))

all: $(BINS)

bin/%: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $<

run: all
	@for b in $(BINS); do echo "=== $$b"; ./$$b; echo; done

clean:
	rm -rf bin

.PHONY: all run clean
