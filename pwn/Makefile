.PHONY : all re clean

CC             := /usr/bin/cc
DEBUGFLAGS     := -ggdb3
CFLAGS         := $(DEBUGFLAGS) -fno-stack-protector -no-pie

RM             := /usr/bin/rm

CHALLENGE_SRCS := $(shell find . -name "*.c")
CHALLENGES     := $(CHALLENGE_SRCS:.c=)

all: $(CHALLENGES)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^

re: clean all

clean:
	$(RM) -f $(CHALLENGES)
