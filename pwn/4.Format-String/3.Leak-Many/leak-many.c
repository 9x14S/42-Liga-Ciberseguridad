#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct pwnme {
  int  guess_int_1;
  int  guess_int_2;
  char guess_str[9];
  char username[64];
};

int seed = 0;

void fill_random(char *buffer, size_t size)
{
  for (size_t i = 0; i < size;)
  {
    char candidate = rand() % 128;
    if (isalnum(candidate))
      buffer[i++] = candidate;
  }
}

int setup(struct pwnme *vuln)
{
  setbuf(stdout, NULL);
  setbuf(stdin, NULL);
  bzero(vuln, sizeof(struct pwnme));

  int urandom_fd = open("/dev/urandom", O_RDONLY);
  if (urandom_fd < 0)
    return 1;
  ssize_t fail_1 = read(urandom_fd, &vuln->guess_int_1, sizeof(vuln->guess_int_1));
  ssize_t fail_2 = read(urandom_fd, &vuln->guess_int_2, sizeof(vuln->guess_int_2));
  ssize_t fail_3 = read(urandom_fd, &seed, sizeof(seed));
  close(urandom_fd);
  if (fail_1 < 0 || fail_2 < 0 || fail_3 < 0)
    return 1;
  srand(seed);
  fill_random(vuln->guess_str, sizeof(vuln->guess_str) - 1);
  return 0;
}

int check_guess(char *ordinal, int num)
{
  int user_guess = 0;
  printf("Guess the %s number: ", ordinal);
  // You can input the number in unsigned format too
  scanf("%d", &user_guess);
  getchar();
  printf("The number is %d, you guessed %d\n", num, user_guess);
  return user_guess != num;
}

int check_guess_str(struct pwnme *vuln)
{
  char string_guess[9];
  printf("Guess the password: ");
  fgets(string_guess, sizeof(string_guess), stdin);
  printf("The correct string is %s, you guessed %s\n", vuln->guess_str, string_guess);
  return strcmp(vuln->guess_str, string_guess);
}

int main(void) {
  // Setup
  struct pwnme vuln;
  if (setup(&vuln))
    return puts("Something went wrong!"), 1;

  // Challenge
  printf("Username: ");
  fgets(vuln.username, sizeof(vuln.username), stdin);

  printf("Hello! ");
  printf(vuln.username);
  putchar('\n');

  if (check_guess("first", vuln.guess_int_1))
    return puts("Wrong guess!"), 1;
  if (check_guess("second", vuln.guess_int_2))
    return puts("Wrong guess!"), 1;
  if (check_guess_str(&vuln))
  {
    puts("Wrong guess!");
    puts("You failed the challenge!!");
    return 1;
  }
  return puts("Wow! Much win!"), 0;
}
