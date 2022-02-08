#include "Controller.h"



 void Controller::page_hostname(HttpRequest request){
    response.set_code("200");
    response.set_status("OK");
    response.set_server_name("localhost"); //todo
    response.set_content_type("text/plain");
    response.set_connection("Close");

    if(request.set_method() == "GET"){
        int max_len_hostname = 255;
        char hostname[max_len_hostname];
        gethostname(hostname,max_len_hostname);
        response.set_body(hostname);
    }
    response.create_resp_mess();
}

 void Controller::page_cpuname(HttpRequest request){
     response.set_code("200");
     response.set_status("OK");
     response.set_server_name("localhost"); //todo
     response.set_content_type("text/plain");
     response.set_connection("Close");

     if(request.set_method() == "GET"){
         string cpu_info;
         ifstream in("/proc/cpuinfo"); //todo

         while (getline(in,cpu_info)){
             if(-1 != cpu_info.find("model name")){
                 break;
             }
         }
         int pos_start = (int)cpu_info.find(':') + 2;
         int len_cpu_name =(int) (cpu_info.find('\n') - (cpu_info.find(':') + 1));
         cpu_info = cpu_info.substr(pos_start,len_cpu_name);
         response.set_body(cpu_info);
     }
     response.create_resp_mess();
}

 void Controller::page_load(HttpRequest request){
     response.set_code("200");
     response.set_status("OK");
     response.set_server_name("localhost"); //todo
     response.set_content_type("text/plain");
     response.set_connection("Close");

     if(request.set_method() == "GET"){
         CPU_Load cpuLoad;
         response.set_body(cpuLoad.get_cpu_load());
     }
     response.create_resp_mess();
}


void Controller::not_content(){
    response.set_code("204");
    response.set_status("No content");
    response.set_server_name("localhost"); //todo
    response.set_connection("Close");
    response.create_resp_mess();
}

//
 void Controller::page_notfound(){
    response.set_code("404");
    response.set_status("Not Found");
    response.set_server_name("localhost"); //todo
    response.set_connection("Close");
    response.create_resp_mess();
}

 void Controller::method_not_valid(HttpRequest request){
     response.set_code("400");
     response.set_status("Bad Request");
     response.set_server_name("localhost"); //todo
     response.set_connection("Close");
     response.create_resp_mess();
}

 void Controller::method_not_allowed(HttpRequest request){
     response.set_code("405");
     response.set_status("Method Not Allowed");
     response.set_server_name("localhost"); //todo
     response.set_connection("Close");
     response.create_resp_mess();
}

 HTTPResponse Controller::set_response(){
     return response;
}


 Controller::Controller(HttpRequest& request){

    for(int i = 0; i < METHOD_NUMBER; i++){
        if(request.set_method() == METHOD[i]){
            method_not_allowed(request);
            return;
        }
    }

    if(!(request.set_method() == "GET" || request.set_method() == "HEAD")){
        method_not_valid(request);
        return;
    }

    if(request.set_url() == HOSTNAME){
        page_hostname(request);
    }
    else if(request.set_url() == CPUNAME){
        page_cpuname(request);
    }
    else if(request.set_url() == "/favicon.ico"){
        not_content();
    }
    else if(request.set_url() == LOAD)
      page_load(request);
    else
      page_notfound();
}


