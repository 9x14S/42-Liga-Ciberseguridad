#define _GNU_SOURCE_

#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 0x10

int setup_var1 = 0;
int setup_var2 = 0;
int setup_var3 = 0;

void win(void)
{
  if (setup_var1 == 42 && setup_var2 == 1337 && setup_var3 == 0xdeadbeef)
    puts("You win!!!");
  else
    puts("You fail!!!");
  return;
}

void gadgets(void)
{
  asm volatile(
    "pop %rax; ret;"
    "pop %rdi; ret;"
    "incw 0(%rdi); ret;"
    "mov %eax,0(%rdi); ret;"
  );
}

void vuln(void)
{
  char buffer[BUFFER_SIZE];
  read(0, buffer, 0xa0);
}

int main(void)
{
  setbuf(stdout, NULL);
  vuln();
  win();
  return 0;
}
