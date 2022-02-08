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
    string server_name;

public:
    explicit HttpRequest(string req);


    string set_method();
    string set_url();
    string set_protocol();
    string set_protocol_version();
};

#endif //IPK_PROJ1CPP_HTTPREQUEST_H
