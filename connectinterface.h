#ifndef CONNECTINTERFACE_H
#define CONNECTINTERFACE_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>

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
    std::string receiveData();
    routingInterface();
    ~routingInterface();
    void cleanup();
};

#endif // CONNECTINTERFACE_H
