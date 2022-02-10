#ifndef IPK_PROJ1CPP_HTTPREQUEST_H
#define IPK_PROJ1CPP_HTTPREQUEST_H
#include <iostream>


using namespace std;


class HttpRequest{

private:
    string req_mess;
    string method;
    string protocol;
    string protocol_version;
    string url;


public:
    string set_method();
    string set_url();
    string set_protocol();
    string set_protocol_version();
    void set_all(string req);
    void clear_all();
};

#endif //IPK_PROJ1CPP_HTTPREQUEST_H
