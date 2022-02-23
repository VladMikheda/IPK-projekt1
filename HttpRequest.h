/**
 * Project: Vytvoření serveru komunikujícího prostřednictvím protokolu HTTP
 *
 * File:     HTTPRequest.h
 * Subject:  IPK 2022
 *
 * @author:  Vladislav Mikheda  xmikhe00
 */

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
    string get_method();
    string get_url();
    string get_protocol();
    string get_protocol_version();
    void set_all(string req);
    void clear_all();
};

#endif //IPK_PROJ1CPP_HTTPREQUEST_H
