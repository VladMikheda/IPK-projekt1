#ifndef IPK_PROJ1CPP_HTTPRESPONSE_H
#define IPK_PROJ1CPP_HTTPRESPONSE_H
#include <iostream>
using namespace std;

enum e_heders{
    protocol = 0,
    server = 1,
    content_type = 2,
    content_length = 3,
    connection = 4
};

const int HEADERS_NUMBER = 5;

class HTTPResponse{

private:
    string headers[HEADERS_NUMBER];
    string body;
    string resp_mess;

public:
    HTTPResponse();
    void set_code(string code);
    void set_status(string status);
    void set_server_name(string server_name);
    void set_content_type(string content_type);
    void set_connection(string connection);
    void set_body(string body_str);
    void create_resp_mess();
    string get_resp_mess();

};


#endif //IPK_PROJ1CPP_HTTPRESPONSE_H
