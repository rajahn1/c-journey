#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080

int main() {
  printf("hello world");
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
}

void error(char *msg) {
  perror(msg);
  exit(1);
};
