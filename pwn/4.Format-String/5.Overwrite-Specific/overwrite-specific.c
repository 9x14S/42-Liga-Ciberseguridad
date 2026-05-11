#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

#define COMPARE_VALUE 0x00420024

struct pwnme {
  int overwrite_this;
  int *first_short;
  int *second_short;
  char username[256];
};

int main(void) {
  setbuf(stdout, NULL);
  struct pwnme vuln = {
      .overwrite_this = 0,
      .first_short  = &vuln.overwrite_this,
      .second_short = (int *)(((void *)&vuln.overwrite_this) + 2),
      .username = 0,
  };

  printf("vuln.overwrite_this = %d\n", vuln.overwrite_this);
  printf("Format string: ");
  fgets(vuln.username, sizeof(vuln.username), stdin);

  printf("Passing to printf: ");
  printf(vuln.username);
  printf("vuln.overwrite_this = %x\n", (vuln.overwrite_this));

  if (vuln.overwrite_this == COMPARE_VALUE)
    puts("Wow! Much win!");
  else
    puts("Turbo fail!!!");
  return 0;
}
