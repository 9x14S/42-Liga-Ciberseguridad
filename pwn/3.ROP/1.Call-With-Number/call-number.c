#define _GNU_SOURCE_

#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 0x10
#define READ_SIZE   0x40

void win(int number)
{
  if (number != 42)
    puts("You fail!!!");
  else
    puts("You win!!!");
  return;
}

void helper(void)
{
  asm volatile("pop %rdi;ret;");
}

void vuln(void)
{
  char buffer[BUFFER_SIZE];
  read(0, buffer, READ_SIZE);
}

int main(void)
{
  setbuf(stdout, NULL);
  vuln();
  win(0);
  return 0;
}
