#include <stdio.h>
#include <stdlib.h>

void win(void) {
  puts("Waos!!! You win!");
  exit(0);
}

int main(void) {
  void *system_addr = (void *)(&system);
  void *user_addr = NULL;

  printf("puts @ %p\n\n", &puts);

  printf("Input address of `system`: ");
  scanf("%p", &user_addr);

  if (user_addr == system_addr)
    win();
  return 1;
}
