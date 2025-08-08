#include <iostream>
#include <winsock2.h>
#include "connectinterface.h"
#include <Windef.h>

int routingInterface::startup(WSADATA& wsaData){
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2,2);
    wsaerr = WSAStartup(wVersionRequested, &wsaData);
    if (wsaerr !=0){
        std::cout << "The Winsock2 dll not found!" << std::endl;
        return wsaerr;
    }
    else{
        std::cout << "The Winsock2 dll found!" << std::endl;
        std::cout << "The status:" << wsaData.szSystemStatus << std::endl;
        return wsaerr;
    }
}

int routingInterface::createSocket(SOCKET& serverSocket){
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(serverSocket == INVALID_SOCKET){
        std::cout << "Error at socket():" << WSAGetLastError() << std::endl;
        WSACleanup();
        return 0;
    }
    else{
        std::cout << "socket() is OK!"<<std::endl;
    }
    //dont forget to close socket
    //WSACleanup(); and clean up
}
void routingInterface::doSomething(WSADATA& wsaData){
    std::cout << "Something" << std::endl;
}
