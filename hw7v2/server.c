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
#include <time.h>
#include <limits.h>

#define MAX_PENDING 5
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int initial_port = atoi(argv[1]);

    if (initial_port < 1024 || initial_port > 65535) {
        fprintf(stderr, "Port number must be between 1024 and 65535\n");
        exit(1);
    }

    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Initialize server address structure
    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(initial_port);

    // Bind socket to port
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR on binding");

    // Listen for connections
    listen(sockfd, MAX_PENDING);

    while (1) {
        // Accept connection
        client_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (newsockfd < 0)
            error("ERROR on accept");

        // Handle client's "switch" message
        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);
        if (recv(newsockfd, buffer, BUFFER_SIZE - 1, 0) < 0)
            error("ERROR reading from socket");
        if (strcmp(buffer, "switch") != 0) {
            close(newsockfd);
            continue;
        }

        // Send new port number
        srand(time(NULL));
        int new_port = rand() % (65535 - 1024 + 1) + 1024;
        bzero(buffer, BUFFER_SIZE);
        snprintf(buffer, BUFFER_SIZE, "%d", new_port);
        if (send(newsockfd, buffer, strlen(buffer), 0) < 0)
            error("ERROR writing to socket");

        // Close initial connection
        close(newsockfd);

        // Listen on new port
        close(sockfd); // Close old socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create new socket
        if (sockfd < 0)
            error("ERROR opening socket");
        server_addr.sin_port = htons(new_port); // Change port number
        if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
            error("ERROR on binding");
        listen(sockfd, MAX_PENDING);

        // Accept new connection
        client_len = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (newsockfd < 0)
            error("ERROR on accept");

        // Handle client's integers
        int min = INT_MAX;
        while (1) {
            bzero(buffer, BUFFER_SIZE);
            if (recv(newsockfd, buffer, BUFFER_SIZE - 1, 0) < 0)
                error("ERROR reading from socket");
            if (strcmp(buffer, "quit") == 0)
                break;
            int num = atoi(buffer);
            if (num == 0 && strcmp(buffer, "0") != 0) {
                // Invalid input, request again
                if (send(newsockfd, "Invalid input, please enter an integer", 38, 0) < 0)
                    error("ERROR writing to socket");
                continue;
            }
            if (num < min)
                min = num;
            snprintf(buffer, BUFFER_SIZE, "%d", min);
            if (send(newsockfd, buffer, strlen(buffer), 0) < 0)
                error("ERROR writing to socket");
        }
        close(newsockfd);
        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            error("ERROR opening socket");
        server_addr.sin_port = htons(initial_port);
        if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
            error("ERROR on binding");
        listen(sockfd, MAX_PENDING);
    }
    close(sockfd);
    return 0;
}
