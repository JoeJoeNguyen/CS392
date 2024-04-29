


#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_BUFFER 2000

int main(int argc, char *argv[]) {
    if(argc < 2) {
        printf("Please provide a port number.\n");
        return 1;
    }
    int port = atoi(argv[1]);
    int sock;
    struct sockaddr_in server;
    char message[MAX_BUFFER], server_reply[MAX_BUFFER];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }
    puts("Socket created");

    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }
    puts("Connected");

    // Send "switch" to the server
    strcpy(message, "switch");
    if(send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive a reply from the server
    if(recv(sock, server_reply, MAX_BUFFER, 0) < 0) {
        puts("recv failed");
        return 1;
    }

    // Close the socket and connect to the new port
    close(sock);
    port = atoi(server_reply);
    server.sin_port = htons(port);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    // Keep communicating with server
    while(1) {
        printf("Enter an integer or 'quit' to terminate: ");
        scanf("%s", message);
        // Add a newline character at the end of the message
        strcat(message, "\n");
        // Send some data
        if(send(sock, message, strlen(message), 0) < 0) {
            puts("Send failed");
            return 1;
        }

        // If user types "quit", terminate the client
        if(strcmp(message, "quit\n") == 0) {
            break;
        }
        // Clear the server_reply buffer
        memset(server_reply, 0, sizeof(server_reply));

        // Receive a reply from the server
        if(read(sock, server_reply, MAX_BUFFER) < 0) {
            puts("recv failed");
            break;
        }
        //int server_reply_int = atoi(server_reply);
        printf("Minimum so far: %s\n", server_reply);
    }

    close(sock);
    return 0;
}