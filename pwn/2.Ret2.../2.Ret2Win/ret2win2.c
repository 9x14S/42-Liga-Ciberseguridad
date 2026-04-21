#include <stdio.h>
#include <stdlib.h>

int flag1 = 0, flag2 = 0, flag3 = 0;

void fail(void) { puts("Well, you failed!!"); }

void win(void) {
  if (!flag1 || !flag2 || !flag3) {
    fail();
    _Exit(1);
  }
  puts("You win!!!!");
  _Exit(0);
}

void setflag1(void) { flag1 = 1; }

void setflag2(void) { flag2 = 1; }

void setflag3(void) { flag3 = 1; }

int main(void) {
  setbuf(stdout, NULL);
  char username[16];
  atexit(&fail);

  printf("Input username: ");
  scanf("%[^\n]s", username);
  printf("Let's see how this goes, %s!\n", username);
  return 1;
}
