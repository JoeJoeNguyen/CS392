#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>

#define MAX_BUFFER 2000

int main (int argc, char *argv[]){
     static int min = INT_MAX;
    if(argc < 2) {
        printf("Please provide a port number.\n");
        return 1;
    }
    int initial_port = atoi(argv[1]);
    int socket_desc, client_sock, c, read_size;
    struct sockaddr_in server, client;
    char client_message[MAX_BUFFER];

    // Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1) {
        printf("Could not create socket");
        return 1;
    }
    puts("Socket created");

    // Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(initial_port);

    // Bind
    if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    // Listen
    listen(socket_desc , 3);

    // Accept an incoming connection
    puts("Waiting for incoming connections...");
    c = sizeof(struct sockaddr_in);

    // Accept connection from a client
    client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }
    puts("Connection accepted");

    // Receive a message from client
    while( (read_size = recv(client_sock , client_message , MAX_BUFFER , 0)) > 0 ) {
        // If client sends "switch", select a new port and send it to the client
        if(strcmp(client_message, "switch") == 0) {
            srand(time(NULL));
            int new_port = rand() % (65535 - 1024 + 1) + 1024;
            char port_str[6];
            sprintf(port_str, "%d", new_port);
            write(client_sock , port_str , strlen(port_str));
            close(client_sock);
            close(socket_desc);
            socket_desc = socket(AF_INET, SOCK_STREAM,0);
            if (socket_desc == -1) {
                printf("Could not create socket");
                return 1;
            }
            server.sin_port = htons(new_port);
            if(bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0) {
                perror("bind failed. Error");
                return 1;
            }
            listen(socket_desc , 3);
            client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
            if (client_sock < 0) {
                perror("accept failed");
                return 1;
            }
        } else {
            // If client sends an integer, maintain the minimum value and send it back

            int num = atoi(client_message);
            if(num < min) {
                min = num;
            }
            char min_str[12];
            sprintf(min_str, "%d", min);
            write(client_sock , min_str , strlen(min_str));
        }
    }

    if(read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    } else if(read_size == -1) {
        perror("recv failed");
    }

    return 0;
}