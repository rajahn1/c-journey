Creating a Server-Side Process

The server is created using the following steps:
1. Socket Creation

This step involves the creation of the socket using the socket() function.

Parameters:

    sockfd: socket descriptor, an integer (like a file handle)
    domain: integer, specifies communication domain. We use AF_ LOCAL as defined in the POSIX standard for communication between processes on the same host. For communicating between processes on different hosts connected by IPV4, we use AF_INET and AF_I NET 6 for processes connected by IPV6.
    type: communication type
    SOCK_STREAM: TCP(reliable, connection-oriented)
    SOCK_DGRAM: UDP(unreliable, connectionless)
    protocol: Protocol value for Internet Protocol(IP), which is 0. This is the same number that appears on the protocol field in the IP header of a packet.(man protocols for more details)

sockfd = socket(domain, type, protocol)

2. Setsockopt

This helps in manipulating options for the socket referred by the file descriptor sockfd. This is completely optional, but it helps in reuse of address and port. Prevents error such as: “address already in use”.

setsockopt(sockfd, level, optname, optval, socklen_t optlen);

3. Bind

After the creation of the socket, the bind() function binds the socket to the address and port number specified in addr(custom data structure). In the example code, we bind the server to the localhost, hence we use INADDR_ANY to specify the IP address.

bind(sockfd, sockaddr *addr, socklen_t addrlen);

Parameters:

    sockfd: socket file descriptor created using the socket() function.
    addr: pointer to a struct sockaddr that contains the IP address and port number to bind the socket.
    addrlen: length of the addr structure.

4. Listen

In this step the server uses the listen() function that puts the server socket in a passive mode, where it waits for the client to approach the server to make a connection. The backlog, defines the maximum length to which the queue of pending connections for sockfd may grow. If a connection request arrives when the queue is full, the client may receive an error with an indication of ECONNREFUSED.

listen(sockfd, backlog);

Parameters:

    sockfd: socket file descriptor created using the socket() function.
    backlog: number representing the size of the queue holding the pending connections while the server is waiting to accept a connection.

5. Accept

In this step the server extracts the first connection request from the queue of pending connections for the listening socket, sockfd, creates a new connected socket using the accept() function, and returns a new file descriptor referring to that socket. At this point, the connection is established between client and server, and they are ready to transfer data.

new_socket= accept(sockfd, sockaddr *addr, socklen_t *addrlen);

Parameters:

    sockfd: socket file descriptor returned by socket() and bind().
    addr: pointer to a struct sockaddr that will be hold the client's IP address and port number.
    addrlen: pointer to a variable that specifies the length of the address structure.

6. Send/Recieve

In this step the server can send or receive data from the client .

Send(): to send data to the client
1

send(sockfd, *buf, len, flags);

Parameters:

    sockfd: socket file descriptor returned by the socket() function.
    buf: pointer to the buffer containing the data to be sent.
    len: number of bytes of data to be sent.
    flags: integer specifying various options for how the data is sent, typically 0 is used for default behavior.

Receive() : to recieve the data from the client.
1

recv( sockfd, *buf, len, flags);

Parameters:

    sockfd: socket file descriptor returned by the socket() function.
    buf: pointer to the buffer containing the data to be stored.
    len: number of bytes of data to be sent.
    flags: integer specifying various options for how the data is sent, typically 0 is used for default behavior.

6. Close

After the exchange of information is complete, the server closes the socket using the close() function and releases the system resources.
