//
// Created by joejoe on 4/27/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    if (port < 1024 || port > 65535) {
        fprintf(stderr, "Port number must be between 1024 and 65535\n");
        exit(1);
    }

    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Initialize server address structure
    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    // Send "switch" message
    if (send(sockfd, "switch", 6, 0) < 0)
        error("ERROR writing to socket");

    // Receive new port number
    bzero(buffer, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0)
        error("ERROR reading from socket");

    // Close initial connection
    close(sockfd);

    // Connect to new port
    int new_port = atoi(buffer);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
    server_addr.sin_port = htons(new_port);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    // Handle user input
    printf("Enter integers (type 'quit' to exit):\n");
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE - 1, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove trailing newline
        if (strcmp(buffer, "quit") == 0)
            break;
        if (send(sockfd, buffer, strlen(buffer), 0) < 0)
            error("ERROR writing to socket");

        // Receive and display minimum
        bzero(buffer, BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE - 1, 0) < 0)
            error("ERROR reading from socket");
        printf("Minimum: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}
