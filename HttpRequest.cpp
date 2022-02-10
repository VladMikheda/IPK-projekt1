#include "HttpRequest.h"


 void HttpRequest::set_all(string req){
     req_mess = req;

     string part;
     part = req_mess.substr(0, req_mess.find("\r\n\r\n"));

     string line;
     line = part.substr(0,part.find('\n'));

     int pos_first_sub = (int)part.find(' ');
     int pos_sec_sub = (int)part.find(' ', pos_first_sub + 1);
     int len_to_sec_sub = (int)pos_sec_sub - (pos_first_sub + 1);
     int pos_sec_slash = (int)part.find('/', pos_sec_sub + 1);
     int len_to_sec_slash = (int)pos_sec_slash - (pos_sec_sub + 1);
     int pos_first_lb = (int)part.find('\n');

     method = line.substr(0,pos_first_sub);
     url = line.substr(pos_first_sub + 1, len_to_sec_sub);
     protocol = line.substr(pos_sec_sub + 1, len_to_sec_slash);
     protocol_version = line.substr(pos_sec_slash + 1, pos_first_lb);
}
 string HttpRequest::set_method(){
    return method;
}
 string HttpRequest::set_url(){
    return url;
}
 string HttpRequest::set_protocol(){
    return protocol;
}
 string HttpRequest::set_protocol_version(){
    return protocol_version;
}
void HttpRequest::clear_all(){
     req_mess.clear();
     method.clear();
     protocol.clear();
     protocol_version.clear();
     url.clear();
}
