#ifndef CONNECTINTERFACE_H
#define CONNECTINTERFACE_H
#include <winsock2.h>

class routingInterface {
private:
    WSADATA Data;
    SOCKET clientSocket;
    SOCKET serverSocket;
    SOCKET acceptSocket;

public:
    int serverStartup();
    int clientStartup();
    int sendData(char metaData[], int type);
    int receiveData();
    routingInterface();
};

#endif // CONNECTINTERFACE_H
