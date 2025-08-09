#ifndef CONNECTINTERFACE_H
#define CONNECTINTERFACE_H
#include <winsock2.h>

class routingInterface {
private:
    WSADATA Data;


public:
    int serverStartup();
    int clientStartup();
    routingInterface();
};

#endif // CONNECTINTERFACE_H
