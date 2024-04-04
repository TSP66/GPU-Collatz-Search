#include "server.h"

server::server(void){
    server::server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server::server_socket == -1) {
        std::cerr << "Error: Failed to create socket." << std::endl;
        return 1;
    }

    server::server_address.sin_family = AF_INET;
    server::server_address.sin_addr.s_addr = INADDR_ANY;
    server::server_address.sin_port = htons(PORT);

    if (bind(server::server_socket, (struct sockaddr *)&server::server_address, sizeof(server::server_address)) < 0) {
        std::cerr << "Error: Bind failed." << std::endl;
        return 1;
    }
}

std::string server::distributeAndRecieveWork(val * startnumber, val * endnumber){

    listen(server::server_socket, 3);

    std::cout << "Server listening on port " << PORT << std::endl;

    socklen_t client_address_size = sizeof(server::client_address);
    server::client_socket = accept(server::server_socket, (struct sockaddr *)&server::client_address, &server::client_address_size);

    if (server::client_socket < 0) {
        std::cerr << "Error: Accept failed." << std::endl;
        return 1;
    }

    memset(buffer, 0, BUFFER_SIZE);

    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

    if (bytes_received < 0) {
        std::cerr << "Error: Receive failed." << std::endl;
        return "-1";
    } else if (bytes_received == 0) {
        std::cout << "Nothing recieved." << std::endl;
        return "0";
    } else{
        std::string str(startnumber.number_to_string()+','+endnumber.number_to_string())
        const char * c = str.c_str();
        end(server::client_socket, c, sizeof(c), 0);
        return std::string(server::buffer);
    }

    close(server::client_socket);
    close(server::server_socket);
}