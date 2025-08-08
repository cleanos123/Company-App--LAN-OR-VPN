#ifndef CONNECTINTERFACE_H
#define CONNECTINTERFACE_H
#include <winsock2.h>

class routingInterface{

public:
    void doSomething(WSADATA& wsaData);


private:
    int startup(WSADATA& wsaData);
    int createSocket(SOCKET& serverSocket);
};

#endif // CONNECTINTERFACE_H
