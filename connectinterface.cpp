#include <iostream>
#include <winsock2.h>
#include "connectinterface.h"
#include <Windef.h>

WSADATA routingInterface::startup(WSADATA& wsaData){
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2,2);
    wsaerr = WSAStartup(wVersionRequested, &wsaData);
    if (wsaerr !=0){
        std::cout << "The Winsock dll not found!" << std::endl;
        return wsaData;
    }
    else{
        std::cout << "The Winsock dll found!" << std::endl;
        std::cout << "The status:" << wsaData.szSystemStatus << std::endl;
        return wsaData;
    }
}

createSocket(){


}
WSADATA routingInterface::doSomething(WSADATA& wsaData){
    std::cout << "Something" << std::endl;
    return wsaData;
}
