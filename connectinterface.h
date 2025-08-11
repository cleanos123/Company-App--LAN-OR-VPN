//HEADER FILE
#ifndef CONNECTINTERFACE_H
#define CONNECTINTERFACE_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <vector>
#include <thread>
#include <mutex>

class routingInterface {
private:
    WSADATA Data;
    SOCKET clientSocket;
    SOCKET acceptSocket;
    SOCKET serverSocket;
    std::vector <SOCKET> queueList;
    std::vector <std::thread> threads;
    std::mutex queueMutex;
    int deviceType;


public:
    int serverStartup();
    int clientStartup();
    int sendData(const char* metaData, SOCKET socket);
    routingInterface();
    ~routingInterface();
    SOCKET getSock();
    void cleanup();
};

#endif // CONNECTINTERFACE_H
