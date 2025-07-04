#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

int main(int argc, char const *argv[]) {
  int status, valread, client_fd;
  struct sockaddr_in serv_addr;
  char *hello = "Hello from client";
  char buffer[1024] = {0};

  // cria socket para comunicam com o servidor
  if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\n Socket creation error \n");
    return -1;
  }

  // AF_INET = IPV4
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // converte os enderecos ipv6 e ipv4 de texto para binario
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported \n");
    return -1;
  }

  // conecta com o servidor passando o socket do cliente e o endereco do
  // servidor, nesse caso 8080 e IPV4
  if ((status = connect(client_fd, (struct sockaddr *)&serv_addr,
                        sizeof(serv_addr))) < 0) {
    printf("\nConnection Failed \n");
    return -1;
  }

  // manda mensagem para o servidor, do socket do cliente
  send(client_fd, hello, strlen(hello), 0);
  printf("Hello message sent\n");

  // le a mensagem;
  valread = read(client_fd, buffer, 1024 - 1);
  printf("%s\n", buffer);

  // fecha a conexao
  close(client_fd);
  return 0;
}
