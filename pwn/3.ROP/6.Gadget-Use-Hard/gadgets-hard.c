#define _GNU_SOURCE_

#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 0x10

int setup_var1 = 0;
int setup_var2 = 0;
int setup_var3 = 0;

void win(void)
{
  if (setup_var1 == 1 && setup_var2 == 0xff000000 && setup_var3 == 0x5a5a)
    puts("You win!!!");
  else
    puts("You fail!!!");
  return;
}

void gadgets(void)
{
  asm volatile(
    "xor %rax, %rax; ret;"
    "sal $1, %rax; ret;"
    "inc %rax; ret;"
    "pop %rdi; ret;"
    "incw 0(%rdi); ret;"
    "mov %eax,0(%rdi); ret;"
  );
}

void vuln(void)
{
  char buffer[BUFFER_SIZE];
  // Be smart about it, you have limited stack space
  // (unless you can figure a way to get more, heheheheh...)
  read(0, buffer, 0x300);
}

int main(void)
{
  setbuf(stdout, NULL);
  vuln();
  win();
  return 0;
}
