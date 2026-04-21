#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define USERNAME_MAX 16

struct pwnme {
  volatile int uservalue;
  char username[USERNAME_MAX];
};

void win(int whatever) {
  (void)whatever;
  char *congrats = "You win!\n";
  write(1, congrats, strlen(congrats));
  exit(0);
}

int main(void) {
  setbuf(stdout, NULL);
  // Ctrl+C isn't considered crashing the program here
  signal(SIGSEGV, &win);
  signal(SIGFPE, &win);
  signal(SIGTRAP, &win);
  signal(SIGQUIT, &win);
  signal(SIGALRM, &win);

  struct pwnme pwn = (struct pwnme){
      .uservalue = 1,
  };

  printf("Input a number: ");
  scanf("%d", &pwn.uservalue);
  printf("Input your name: ");
  scanf("%s", pwn.username);
  // There's many ways you can crash this program...
  if ((int)(42 / pwn.uservalue)) {
    puts("You fail!");
    return 1;
  }
  puts("You fail!");
  return 1;
}
