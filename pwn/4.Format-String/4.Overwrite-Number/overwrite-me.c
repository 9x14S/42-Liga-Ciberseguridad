#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

struct pwnme {
  int overwrite_this;
  int *helper;
  char username[64];
};

int main(void) {
  setbuf(stdout, NULL);
  struct pwnme vuln = {
      .overwrite_this = 0,
      .helper = &vuln.overwrite_this,
      .username = 0,
  };

  printf("vuln.overwrite_this = %d\n", vuln.overwrite_this);
  printf("Format string: ");
  fgets(vuln.username, sizeof(vuln.username), stdin);

  printf("Passing to printf: ");
  printf(vuln.username);
  printf("vuln.overwrite_this = %d\n", vuln.overwrite_this);

  if (vuln.overwrite_this)
    puts("Wow! Much win!");
  else
    puts("Turbo fail!!!");
  return 0;
}
