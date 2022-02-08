#include "Server.h"


 Server::Server(int p){
    port = p;
}


 void Server::server_start(){
    server.set_port(port);
    server.set_domian(AF_INET);
    server.set_type(SOCK_STREAM);

    server.set_sin_addr(AF_INET,INADDR_ANY);
    server.Socket();
    server.Bind();
    server.Listen();
    char buffer[BUFFER_SIZE] = {0};
    while(1){
        int socket_desk = server.Accept();
        cout << "Start reading" << endl;
        while(1){
            memset(buffer,'\0', sizeof(buffer));
            int buffer_real_size = read(socket_desk, buffer, BUFFER_SIZE-1);
            buffer[buffer_real_size++] = '\0';
            req_str.append(buffer);

            if (buffer_real_size < BUFFER_SIZE) {
                break;
            }
        }

        cout<< req_str << endl;
        HttpRequest request(req_str);
        Controller controller(request);

        write(socket_desk,controller.set_response().get_resp_mess().data(),controller.set_response().get_resp_mess().size());
        close(socket_desk);
        req_str.clear();
    }

}
