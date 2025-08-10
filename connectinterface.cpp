#include <iostream>
#include <winsock2.h>
#include "connectinterface.h"
#include <Windef.h>
#include <tchar.h>
#include <string>
#include <ws2tcpip.h>

// SERVER SIDE
routingInterface::routingInterface() {
}
int routingInterface::serverStartup() {
    std::cout << "SERVER INITIALIZING" << std::endl;
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaerr = WSAStartup(wVersionRequested, &Data);
    if (wsaerr != 0) {
        std::cout << "The Winsock2 dll not found!" << std::endl;
        return 1;
    }
    else {
        std::cout << "The Winsock2 dll found!" << std::endl;
        std::cout << "The status:" << &Data.szSystemStatus << std::endl;
    }

    //STEP 2 CREATE SOCKET
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cout << "Error at socket():" << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "socket() is OK!" << std::endl;
    }
    //dont forget to close socket
    //WSACleanup(); and clean up

    //CREATING BIND STEP 3 bind()
    sockaddr_in serverService;
    serverService.sin_family = AF_INET;
    InetPton(AF_INET, _T("192.168.4.25"), &serverService.sin_addr.s_addr);
    serverService.sin_port = htons(27105);
    if (bind(serverSocket, (SOCKADDR*)&serverService, sizeof(serverService)) == SOCKET_ERROR) {
        std::cout << "bind() failed: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    else {
        std::cout << "bind() is OK!" << std::endl;
    }
    //STEP 4 LISTEN ON THE SOCKET listen()
    if (listen(serverSocket, 1) == SOCKET_ERROR) {
        std::cout << "listen(): Error listening on socket" << WSAGetLastError() << std::endl;
    }
    else {
        std::cout << "listen() is OK, I'm waiting for connections..." << std::endl;
    }
    //STEP 5 Accept a connection accept(), connect()
    acceptSocket = accept(serverSocket, NULL, NULL);
    if (acceptSocket == INVALID_SOCKET) {
        std::cout << "accept failed:" << WSAGetLastError() << std::endl;
        closesocket(acceptSocket);
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }


    return 0;
}


//Client Side
int routingInterface::clientStartup() {
    std::string usrInput = "";
    sockaddr_in clientService;

    std::cout << "CLIENT INITIALIZING" << std::endl;
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaerr = WSAStartup(wVersionRequested, &Data);
    if (wsaerr != 0) {
        std::cout << "The Winsock2 dll not found!" << std::endl;
        return 1;
    }
    else {
        std::cout << "The Winsock2 dll found!" << std::endl;
        std::cout << "The status:" << &Data.szSystemStatus << std::endl;
    }
    //STEP 2 CREATE SOCKET
    while (usrInput == "") {
        clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (clientSocket == INVALID_SOCKET) {
            std::cout << "Error at socket():" << WSAGetLastError() << std::endl;
            WSACleanup();
            return 1;
        }

        else {
            std::cout << "socket() is OK!" << std::endl;
        }

        //STEP 3 CONNECT
        ZeroMemory(&clientService, sizeof(clientService));
        clientService.sin_family = AF_INET;
        InetPton(AF_INET, _T("192.168.4.25"), &clientService.sin_addr.s_addr);
        clientService.sin_port = htons(27105);

        if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
            std::cout << "Client: connect() - Failed to connect." << std::endl;
            std::cout << "Press ENTER to scan again.";
            std::getline(std::cin, usrInput);
            closesocket(clientSocket);
        }

        else {
            std::cout << "Client: connect() is OK." << std::endl;
            std::cout << "Client: Can start sending and recieving data..." << std::endl;
            break;
        }
    }
    return 0;
}
int routingInterface::sendData(char metaData[], int type) {
    int byteCount = 0;
    if (type == 1) {
        byteCount = send(clientSocket, metaData, strlen(metaData), 0);
    }
    else {
        byteCount = send(serverSocket, metaData, strlen(metaData), 0);
    }
    if (byteCount == SOCKET_ERROR) {
        printf("Server send error %ld.\n", WSAGetLastError());
        return -1;
    }
    else {
        printf("Server: sent %ld bytes \n", byteCount);
    }
    return 0;
}

int routingInterface::receiveData() {
    char receiveBuffer[200] = "";
    int byteCount = recv(acceptSocket, receiveBuffer, sizeof(receiveBuffer), 0);
    if (byteCount < 0) {
        printf("Client:erro %ld.\n", WSAGetLastError());
        return 0;
    }
    else {
        printf("Received data: %s \n", receiveBuffer);
    }
    return 0;
}
