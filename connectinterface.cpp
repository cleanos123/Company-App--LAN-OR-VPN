#include <iostream>
#include <winsock2.h>
#include "connectinterface.h"
#include <Windef.h>
#include <tchar.h>
#include <ws2tcpip.h>

// CLIENT SIDE
int routingInterface::startup(WSADATA& wsaData){
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2,2);
    wsaerr = WSAStartup(wVersionRequested, &wsaData);
    if (wsaerr !=0){
        std::cout << "The Winsock2 dll not found!" << std::endl;
        return 1;
    }
    else{
        std::cout << "The Winsock2 dll found!" << std::endl;
        std::cout << "The status:" << wsaData.szSystemStatus << std::endl;
    }
    //STEP 2 CREATE SOCKET
    SOCKET serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serverSocket == INVALID_SOCKET){
        std::cout << "Error at socket():" << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }
    else{
        std::cout << "socket() is OK!"<<std::endl;
    }
    //dont forget to close socket
    //WSACleanup(); and clean up
    //CREATING BIND STEP 3 bind()
    sockaddr_in service;
    service.sin_family = AF_INET;
    InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
    if (bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR){
        std::cout << "bind() failed: " << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    else{
        std::cout << "bind() is OK!" << std::endl;
    }
    //STEP 4 LISTEN ON THE SOCKET listen()
    if(listen(serverSocket, 1)== SOCKET_ERROR){
        std::cout << "listen(): Error listening on socket" << WSAGetLastError() << std::endl;
    }
    else{
        std::cout << "listen() is OK, I'm waiting for connections..." << std::endl;
    }
    //STEP 5 Accept a connection accept(), connect()
    SOCKET acceptSocket;
    acceptSocket = accept(serverSocket, NULL, NULL);
        if(acceptSocket == INVALID_SOCKET){
            std::cout << "accept failed:" << WSAGetLastError() << std::endl;
            WSACleanup();
            return -1;
    }


    return 0;
}

void routingInterface::doSomething(WSADATA& wsaData){
    std::cout << "Something" << std::endl;
}
