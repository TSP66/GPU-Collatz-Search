#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include "bigNumber.h"

#define PORT 8080;
#define BUFFER_SIZE 1024;

class server{
    server(void);

    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    std::string distributeAndRecieveWork(val * startnumber, val * endnumber);
};