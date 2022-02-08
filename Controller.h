#ifndef IPK_PROJ1CPP_CONTROLER_H
#define IPK_PROJ1CPP_CONTROLER_H


#include <unistd.h>
#include <fstream>
#include "HttpRequest.h"
#include "HTTPResponse.h"
#include "CPULoad.h"

const string HOSTNAME = "/hostname";
const string CPUNAME = "/cpu-name";
const string LOAD = "/load";
const int METHOD_NUMBER = 6;
const string METHOD[METHOD_NUMBER] ={
        "POST",
        "PUT",
        "DELETE",
        "PATH",
        "OPTIONS",
        "CONNECT"
};


class Controller{
private:
    string page;
    HTTPResponse response;

    void page_hostname(HttpRequest request);

    void page_cpuname(HttpRequest request);

    void page_load(HttpRequest request);

    void page_notfound();

    void method_not_valid(HttpRequest request);
    void method_not_allowed(HttpRequest request);

    void not_content();

public:
    HTTPResponse set_response();


public:
    Controller(HttpRequest& request);


};


#endif //IPK_PROJ1CPP_CONTROLER_H
