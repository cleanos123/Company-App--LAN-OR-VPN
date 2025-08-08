#ifndef CONNECTINTERFACE_H
#define CONNECTINTERFACE_H
#include <winsock2.h>

class routingInterface{

public:
    WSADATA doSomething(WSADATA& wsaData);


private:
    WSADATA startup(WSADATA& wsaData);

};

#endif // CONNECTINTERFACE_H
