//HEADER FILE
#ifndef CONNECTINTERFACE_H
#define CONNECTINTERFACE_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>

class routingInterface {
private:
    WSADATA Data;
    SOCKET clientSocket;
    SOCKET acceptSocket;
    SOCKET serverSocket;
    SOCKET pythonSocket;
    std::vector <SOCKET> clients;
    std::mutex queueMutex;
    int deviceType;


public:
    int serverStartup();
    int clientStartup();
    int sendData(const char* metaData, SOCKET socket);
    void receiveData(SOCKET socket);
    bool checkPy(SOCKET socket);
    routingInterface();
    ~routingInterface();
    SOCKET getSock();
    void cleanup();
};

#endif // CONNECTINTERFACE_H
