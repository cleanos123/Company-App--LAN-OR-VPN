#include <iostream>
#include <winsock2.h>
#include "connectinterface.h"
#include <Windef.h>
#include <tchar.h>
#include <string>
#include <ws2tcpip.h>
#include <thread>
#include <mutex>

//HELPER FUNCTIONS/////////////////////////////////////////////////////
void receiveData(SOCKET cliSocket);
bool findSock(const std::vector <SOCKET>& vect, SOCKET aS) {
    for (SOCKET elem : vect) {
        if (elem == aS)
            return true;
    }
    return false;
}

// SERVER SIDE
routingInterface::routingInterface() {
}
routingInterface::~routingInterface() {
    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }
    // Close sockets and WSACleanup
    if (clientSocket != INVALID_SOCKET) closesocket(clientSocket);
    if (serverSocket != INVALID_SOCKET) closesocket(serverSocket);
    if (acceptSocket != INVALID_SOCKET) closesocket(acceptSocket);
    WSACleanup();
}
int routingInterface::serverStartup() {
    deviceType = 0;
    std::cout << "SERVER INITIALIZING" << std::endl;

    WORD wVersionRequested = MAKEWORD(2, 2);
    int wsaerr = WSAStartup(wVersionRequested, &Data);
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
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cout << "listen(): Error listening on socket" << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
    }
    else {
        std::cout << "listen() is OK, I'm waiting for connections..." << std::endl;
    }
    //STEP 5 Accept a connection accept(), connect()
    while (true) {
        SOCKET acceptSock = accept(serverSocket, NULL, NULL);
        std::cout << "accept() returned socket: " << acceptSock << std::endl;
        if (acceptSock == INVALID_SOCKET) {
            std::cout << "accept() failed: " << WSAGetLastError() << std::endl;
            // Depending on design, you may continue or break
            continue;
        }

        threads.emplace_back(receiveData, acceptSock);
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            if (!findSock(queueList, acceptSock)) {
                queueList.push_back(acceptSock);
            }
        }
        std::cout << "New client connected, socket: " << acceptSock << std::endl;
    }

    for (auto& t : threads){
        if (t.joinable()) t.join();
    }
    return 0;
}
//Client Side////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int routingInterface::clientStartup(){
    deviceType = 1;
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
SOCKET routingInterface::getSock(){
    if(!deviceType)
        return serverSocket;
    else
        return clientSocket;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int routingInterface::sendData(const char* metaData, SOCKET sock) {
    if (metaData == nullptr) {
        printf("sendData error: metaData is null\n.");
        return -1;
    }
    if (sock == INVALID_SOCKET) {
        printf("sendData error: Invalid Socket.\n");
        return - 1;
    }
    int byteCount = send(sock, metaData, strlen(metaData), 0);
    if (byteCount == SOCKET_ERROR) {
        printf("Server send error %ld.\n", WSAGetLastError());
        return -1;
    }
    else {
        printf("Server: sent %ld bytes \n", byteCount);
    }
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void receiveData(SOCKET cliSocket) {
    std::cout << "Thread started for socket: " << cliSocket << std::endl;
    char receiveBuffer[1024];
    while (true) {
        int byteCount = recv(cliSocket, receiveBuffer, sizeof(receiveBuffer) - 1, 0);
        if (byteCount > 0) {
            receiveBuffer[byteCount] = '\0';
            printf("[Thread] received login data: %s\n", receiveBuffer);
        }
        else if (byteCount == 0) {
            printf("[Thread] disconnected");
            break;
        }
        else {
            printf("[Thread] recv() failed: %d\n", WSAGetLastError());
            break;
        }
    }
    closesocket(cliSocket);
    std::cout << "Thread ending for socket: " << cliSocket << std::endl;
}
