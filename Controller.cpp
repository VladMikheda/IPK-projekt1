#include "Controller.h"



 HTTPResponse Controller::page_hostname(HttpRequest& request, HTTPResponse& response){
    response.set_code("200");
    response.set_status("OK");
    response.set_content_type("text/plain");
    response.set_connection("Close");

    if(request.set_method() == "GET"){
        response.set_body(ServerInfo::get_host_name());
    }
    response.create_resp_mess();
    return response;
}

 HTTPResponse Controller::page_cpuname(HttpRequest& request, HTTPResponse& response){
     response.set_code("200");
     response.set_status("OK");
     response.set_content_type("text/plain");
     response.set_connection("Close");

     if(request.set_method() == "GET"){
         response.set_body(ServerInfo::get_cpu_name());
     }
     response.create_resp_mess();
     return response;
}

 HTTPResponse Controller::page_load(HttpRequest& request, HTTPResponse& response){
     response.set_code("200");
     response.set_status("OK");
     response.set_content_type("text/plain");
     response.set_connection("Close");

     if(request.set_method() == "GET"){
         ServerInfo cpuLoad;
         response.set_body(cpuLoad.get_cpu_load());
     }
     response.create_resp_mess();
     return response;
}


 HTTPResponse Controller::not_content(HTTPResponse& response){
    response.set_code("204");
    response.set_status("No content");
    response.set_connection("Close");
    response.create_resp_mess();
    return response;
}


 HTTPResponse Controller::page_notfound(HTTPResponse& response){
    response.set_code("404");
    response.set_status("Not Found");
    response.set_connection("Close");
    response.create_resp_mess();
    return response;
}

 HTTPResponse Controller::method_not_valid(HTTPResponse& response){
     response.set_code("400");
     response.set_status("Bad Request");
     response.set_connection("Close");
     response.create_resp_mess();
     return response;
}

 HTTPResponse Controller::method_not_allowed(HTTPResponse& response){
     response.set_code("405");
     response.set_status("Method Not Allowed");
     response.set_connection("Close");
     response.create_resp_mess();
     return response;

}

 Controller::Controller(){
    METHOD[0] = "POST";
    METHOD[1] = "PUT";
    METHOD[2] = "DELETE";
    METHOD[3] = "PATH";
    METHOD[4] = "OPTIONS";
    METHOD[5] = "CONNECT";
}
 HTTPResponse Controller::selection(HttpRequest request){
    HTTPResponse response;

    for(int i = 0; i < METHOD_NUMBER; i++){
        if(request.set_method() == METHOD[i]){
            return method_not_allowed(response);
        }
    }

    if(!(request.set_method() == "GET" || request.set_method() == "HEAD")){
        return method_not_valid(response);;
    }


    if(request.set_url() == "/hostname"){
        return page_hostname(request,response);
    }
    else if(request.set_url() == "/cpu-name"){
        return page_cpuname(request,response);
    }
    else if(request.set_url() == "/favicon.ico"){
        return not_content(response);
    }
    else if(request.set_url() == "/load")
        return page_load(request,response);
    else
        return page_notfound(response);

}




