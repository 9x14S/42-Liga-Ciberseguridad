#define _GNU_SOURCE_

#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define LBUFFER_SIZE 0x10
#define GBUFFER_SIZE 0x40

char global_buffer[GBUFFER_SIZE];

void win(char *string)
{
  if (NULL == string || strcmp(string, "pwned") != 0)
    puts("You fail!!!");
  else
    puts("You win!!!");
  return;
}

void helper(void)
{
  asm volatile("pop %rdi; ret;");
}

void vuln(void)
{
  char local_buffer[LBUFFER_SIZE];
  ssize_t read_amount = read(0, global_buffer, GBUFFER_SIZE);
  memcpy(local_buffer, global_buffer, read_amount);
}

int main(void)
{
  setbuf(stdout, NULL);
  vuln();
  win("I fail..");
  return 0;
}
