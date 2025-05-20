#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
int main() {
  // socket connection
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  // connect
  connect();

  // Send/Receive
  send();
  recv();

  // Close the connection
}

void error(char *msg) {
  perror(msg);
  exit(1);
}
