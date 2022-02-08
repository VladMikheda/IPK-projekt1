#include "HttpRequest.h"


 HttpRequest::HttpRequest(string req){
    req_mess = req;

    string part;
    part = req_mess.substr(0, req_mess.find("\r\n\r\n"));

    string line[2];
    line[0] = part.substr(0,part.find('\n'));
    line[1] = part.substr(part.find('\n') + 1 , part.find('\n',part.find('\n') + 1) - part.find('\n'));
    cout << line[1] << endl;
    //TODO забрать от сюда servername

    int pos_first_sub = (int)part.find(' ');
    int pos_sec_sub = (int)part.find(' ', pos_first_sub + 1);
    int len_to_sec_sub = (int)pos_sec_sub - (pos_first_sub + 1);
    int pos_sec_slash = (int)part.find('/', pos_sec_sub + 1);
    int len_to_sec_slash = (int)pos_sec_slash - (pos_sec_sub + 1);
    int pos_first_lb = (int)part.find('\n');

    method = line[0].substr(0,pos_first_sub);
    url = line[0].substr(pos_first_sub + 1, len_to_sec_sub);
    protocol = line[0].substr(pos_sec_sub + 1, len_to_sec_slash);
    protocol_version = line[0].substr(pos_sec_slash + 1, pos_first_lb);
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
