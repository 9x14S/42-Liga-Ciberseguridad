#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

struct pwnme {
  int guess_this;
  int user_guess;
  char username[64];
};

int main(void) {
  setbuf(stdout, NULL);
  struct pwnme vuln = {
      .guess_this = 0,
      .user_guess = 0,
      .username = 0,
  };

  int urandom_fd = open("/dev/urandom", O_RDONLY);
  if (urandom_fd < 0 || 0 > read(urandom_fd, &vuln.guess_this, sizeof(int))) {
    close(urandom_fd);
    return 1;
  }
  close(urandom_fd);

  printf("Username: ");
  fgets(vuln.username, sizeof(vuln.username), stdin);

  printf("Hello! ");
  printf(vuln.username);

  printf("\nWhat's your guess?: ");
  scanf("%d", &vuln.user_guess);

  printf("The correct number is %d, you guessed %d\n", vuln.guess_this, vuln.user_guess);
  if (vuln.guess_this == vuln.user_guess)
    puts("Wow! Much win!");
  else
    puts("Nuclear fail!!!");
  return 0;
}
