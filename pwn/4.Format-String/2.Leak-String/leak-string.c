#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

struct pwnme {
  char guess_this[9];
  char user_guess[9];
  char username[64];
};

void fill_random(char *buffer, size_t size)
{
  for (size_t i = 0; i < size;)
  {
    char candidate = rand() % 128;
    if (isalnum(candidate))
      buffer[i++] = candidate;
  }
}

int main(void) {
  setbuf(stdout, NULL);
  struct pwnme vuln;
  bzero(&vuln, sizeof(struct pwnme));
  srand(time(NULL));

  fill_random(vuln.guess_this, sizeof(vuln.guess_this) - 1);
  printf("Username: ");
  fgets(vuln.username, sizeof(vuln.username), stdin);

  printf("Hello! ");
  printf(vuln.username);

  printf("\nWhat's your guess?: ");
  fgets(vuln.user_guess, sizeof(vuln.user_guess), stdin);

  printf("The correct string is %s, you guessed %s\n", vuln.guess_this, vuln.user_guess);
  if (strcmp(vuln.guess_this, vuln.user_guess) == 0)
    puts("Wow! Much win!");
  else
    puts("Nuclear fail!!!");
  return 0;
}
