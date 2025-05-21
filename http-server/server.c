#include <asm-generic/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

  int server_fd, new_socket;

  ssize_t valread;
  struct sockaddr_in address;

  int opt = 1;
  socklen_t addrlen = sizeof(address);

  char buffer[1024] = {0};

  char *hello = "HTTP/1.1 200 OK\r\n"
                "Content-Type: text/html\r\n"
                "Content-Length: 23\r\n"
                "\r\n"
                "<h1>Hello, world!</h1>";

  // Cria socket para comunicacao
  // AF_INET: dominio da comunicacao, ipv4 usado para comunicao entre hosts
  // diferentes,
  // SOCK_STREAM: tipo de comunicacao TCP
  // 0 = protocolo
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Seta as opcoes do Socket, permitindo reutilizacao da porta
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;

  // aceita conexoes de qualquer IP
  address.sin_addr.s_addr = INADDR_ANY;
  // converte a porta 8080 para formato de network, que o tcp entende
  address.sin_port = htons(PORT);

  // vincula o socket ao endereco e numero de porta especificados
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {

    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // coloca socket em modo passivo, aguardando o cliente se aproximar do
  // servidor para estabelecer a conexao
  // 3 eh o backlog, que eh o tamanho maximo da fila de conexoes que o socket
  // pode atender
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // cria um novo socket para a conexao com o cliente
  // conexao entre cliente e servidor eh estabelecida, estando prontos para
  // receber os dados
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) <
      0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  // le os dados que o cliente enviou, no caso o cliente envia uma request HTTP
  valread = read(new_socket, buffer, 1024 - 1);
  printf("%s\n", buffer);

  // envia a respota para o cliente
  send(new_socket, hello, strlen(hello), 0);
  printf("Hello message sent \n");

  // fecha a conexao com o cliente depois o socket do servidor
  close(new_socket);
  close(server_fd);

  return 0;
}
