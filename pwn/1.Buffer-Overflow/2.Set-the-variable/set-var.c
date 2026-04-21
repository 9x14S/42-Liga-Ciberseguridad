#include <stdio.h>

#define USERNAME_MAX 16

struct pwnme {
  char username[USERNAME_MAX];
  volatile int changeme;
};

void win(void) { puts("You win!"); }

void hello(char *name) { printf("Hello %s!\n", name); }

int main(void) {
  setbuf(stdout, NULL);

  struct pwnme pwn = (struct pwnme){
      .changeme = 0,
      .username = 0,
  };

  scanf("%[^\n]s", pwn.username);
  hello(pwn.username);
  if (pwn.changeme == (int)0x42424242) {
    win();
    return 0;
  }
  puts("You fail!");
  return 1;
}
