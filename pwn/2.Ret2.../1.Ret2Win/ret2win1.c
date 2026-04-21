#include <stdio.h>
#include <stdlib.h>

void win(void) {
  puts("You win!!!!");
  _Exit(0);
}

void fail(void) { puts("Well, you failed!!"); }

int main(void) {
  setbuf(stdout, NULL);
  char username[16];
  atexit(&fail);

  printf("Input username: ");
  scanf("%[^\n]s", username);
  printf("Let's see how this goes, %s!\n", username);
  return 1;
}
