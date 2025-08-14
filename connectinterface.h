//HEADER FILE
#ifndef CONNECTINTERFACE_H
#define CONNECTINTERFACE_H
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
//#include <vector>
#include <mutex>
#include <unordered_map>

class routingInterface {
private:
    WSADATA Data;
    SOCKET clientSocket;
    SOCKET acceptSocket;
    SOCKET serverSocket;
    SOCKET pythonSocket;
    // NOT NEEDED FOR NOW MAYBE TO SAVE PAST CLIENTS IP ETC.
    //std::vector <SOCKET> clients;
    std::mutex socketMapMutex;
    std::unordered_map<SOCKET, SOCKET> pythonReplyMap;
    int deviceType;


public:
    int serverStartup();
    int clientStartup();
    std::string sendData(const char* metaData, SOCKET socket);
    void receiveData(SOCKET socket);
    bool checkPy(SOCKET socket);
    routingInterface();
    ~routingInterface();
    SOCKET getSock();
    void cleanup();
};

#endif // CONNECTINTERFACE_H
