.PHONY : all re clean compile

CC             := /usr/bin/cc
DEBUGFLAGS     := -ggdb3
CFLAGS         := $(DEBUGFLAGS) -fno-stack-protector -no-pie
BINARIES_DIR   := ../binaries

RM             := /usr/bin/rm

CHALLENGE_SRCS := $(shell find . -name "*.c")
CHALLENGES     := $(CHALLENGE_SRCS:.c=)

all: $(CHALLENGES)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^

re: clean all

clean:
	$(RM) -f $(CHALLENGES)
	$(RM) -rf $(BINARIES_DIR)

compile: all
	@mkdir --parent $(BINARIES_DIR)
	mv $(CHALLENGES) $(BINARIES_DIR)
