#include "HTTPResponse.h"


 HTTPResponse::HTTPResponse(){
    headers[protocol] = "HTTP/1.1";
}

 void HTTPResponse::set_code(const string& code){
    headers[protocol].append(" ");
    headers[protocol].append(code);
}

 void HTTPResponse::set_status(const string& status){
    headers[protocol].append(" ");
    headers[protocol].append(status);
    headers[protocol].append("\r\n");
}

 void HTTPResponse::set_content_type(const string& content_type_str){
    headers[content_type].append("Content_type:");
    headers[content_type].append(" ");
    headers[content_type].append(content_type_str);
    headers[content_type].append("\r\n");
}

 void HTTPResponse::set_connection(const string& connection_str){
    headers[connection].append("Connection:");
    headers[connection].append(" ");
    headers[connection].append(connection_str);
}

 void HTTPResponse::set_body(const string& body_str){
    body = body_str;
    headers[content_length].append("Content_length:");
    headers[content_length].append(" ");
    headers[content_length].append(to_string(body_str.size()));
    headers[content_length].append("\r\n");
}

 void HTTPResponse::create_resp_mess(){
    for(int i = 0; i < HEADERS_NUMBER; i++){
        if(!headers[i].empty()){
            resp_mess.append(headers[i]);
        }
    }
     resp_mess.append("\r\n\r\n");

    if(!body.empty()){
        resp_mess.append(body);
        resp_mess.append("\r\n\r\n");
    }
}

 string HTTPResponse::get_resp_mess(){
    return resp_mess;
}
