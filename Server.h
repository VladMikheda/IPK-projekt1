#ifndef IPK_PROJ1CPP_SERVER_H
#define IPK_PROJ1CPP_SERVER_H
#include "Tcp.h"
#include <iostream>
#include <unistd.h>
#include <fstream>
#include "Controller.h"
using namespace std;
const int BUFFER_SIZE = 256;
//const string NEW_NEXT_LINE = "\r\n\r\n";


class Server{
private:
    int port;
    string req_str;
    Tcp server;

    //TODO хз надо ли добавить проверкук на 2 переноса строки

public:
    explicit Server(int p);


    void server_start();
};


#endif //IPK_PROJ1CPP_SERVER_H
