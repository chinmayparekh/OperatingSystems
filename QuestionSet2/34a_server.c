//  Program number 34
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to create a concurrent server.
// a. use fork
// b. use pthread_create
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 5555
int main(int argc, char const *argv[])
{
	int server_fd, nsd, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char *hello = "Hi";

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) // domain(host-local or remote),type(Tcp/udp),protocol(network layer)
		== 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 8080
	if (setsockopt(server_fd, SOL_SOCKET,
				   SO_REUSEADDR, &opt,
				   sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Forcefully attaching socket to the port
	if (bind(server_fd, (struct sockaddr *)&address,
			 sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if ((nsd = accept(server_fd, (struct sockaddr *)&address,
						  (socklen_t *)&addrlen)) < 0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}

		if (!fork())
		{
			char buf[100];
			close(server_fd);
			read(nsd, buf, sizeof(buf));
			printf("%s\n", buf);
			send(nsd, hello, strlen(hello), 0);
			printf("Hello message sent\n");
			exit(0);
		}
		else
			close(nsd);
	}

	return 0;
}