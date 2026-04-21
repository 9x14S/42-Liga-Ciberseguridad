.PHONY : all re clean

CC             := /usr/bin/cc
DEBUGFLAGS     := -ggdb3
CFLAGS         := $(DEBUGFLAGS) -fno-stack-protector -fno-PIE -fno-PIC

CHALLENGE_SRCS := $(shell find . -name "*.c")
CHALLENGES     := $(CHALLENGE_SRCS:.c=)

all: $(CHALLENGES)

%: %.c
	$(CC) $(CFLAGS) -o $@ $^

re: fclean all

clean:
	$(RM) -f $(CHALLENGES)
