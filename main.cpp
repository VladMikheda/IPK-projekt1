//#include <iostream>
//#include <unistd.h>
//#include <fstream>
//#include "Tcp.h"
//#include "HttpRequest.h"
//#include "HTTPResponse.h"
#include "Server.h"
#include <cstdlib>
using namespace std;



int main(int argc, char **argv) {
    if(argc != 2){
        std::cerr << "ERROR: Port not specified" << std::endl;
        exit(ERROR_PORT);
    }
    if(argv[1][0] == '+'){
        std::cerr << "ERROR: The port is incorrect or not specified" << std::endl;
        std::cerr << "start program: \n .\\hinfosvc <port>" << std::endl;
        exit(ERROR_PORT);
    }
    int port = 0;
    try{
        port = stoi(argv[1],nullptr,10);
    }
    catch(exception const& e ) {
        std::cerr << "ERROR: The port is incorrect or not specified" << std::endl;
        std::cerr << "start program: \n .\\hinfosvc <port>" << std::endl;
        exit(ERROR_PORT);
    }

    if(port == 0 || port > 65535 || port < 1){
        std::cerr << "ERROR: The port is incorrect or not specified" << std::endl;
        std::cerr << "start program: \n .\\hinfosvc <port>" << std::endl;
        exit(ERROR_PORT);
    }



//    ifstream in("/proc/stat"); //todo
//    string cpu_load;
//    getline(in,cpu_load);
//    unsigned long pos_first_sub = cpu_load.find(' ') + 1;
//    unsigned long pos_second_sub = (int)  cpu_load.find(' ', pos_first_sub + 1);
//    unsigned long pos_third_sub = (int)  cpu_load.find(' ', pos_second_sub + 1);
//    unsigned long pos_fourth_sub = (int)  cpu_load.find(' ', pos_third_sub + 1);
//    unsigned long pos_fifth_sub = (int)  cpu_load.find(' ', pos_fourth_sub + 1);
//    unsigned long pos_sixth_sub = (int)  cpu_load.find(' ', pos_fifth_sub + 1);
//    unsigned long pos_seventh_sub = (int)  cpu_load.find(' ', pos_sixth_sub + 1);
//    unsigned long pos_eighth_sub = (int)  cpu_load.find(' ', pos_seventh_sub + 1);
//    unsigned long pos_ninth_sub = (int)  cpu_load.find(' ', pos_eighth_sub + 1);
//
//    unsigned long len_user = pos_second_sub - (pos_first_sub + 1);
//    unsigned long len_nice = pos_third_sub - (pos_second_sub + 1);
//    unsigned long len_system = pos_fourth_sub - (pos_third_sub + 1);
//    unsigned long len_idle = pos_fifth_sub - (pos_fourth_sub + 1);
//    unsigned long len_iowait = pos_sixth_sub - (pos_fifth_sub + 1);
//    unsigned long len_irq = pos_seventh_sub - (pos_sixth_sub + 1);
//    unsigned long len_softirq = pos_eighth_sub - (pos_seventh_sub + 1);
//    unsigned long len_steal  = pos_ninth_sub - (pos_eighth_sub + 1);
//
//    string user = cpu_load.substr(pos_first_sub+1, len_user);
//    string nice = cpu_load.substr(pos_second_sub+1, len_nice);
//    string system = cpu_load.substr(pos_third_sub+1, len_system);
//    string idle = cpu_load.substr(pos_fourth_sub+1, len_idle);
//    string iowait = cpu_load.substr(pos_fifth_sub+1, len_iowait);
//    string irq = cpu_load.substr(pos_sixth_sub+1, len_irq);
//    string softirq = cpu_load.substr(pos_seventh_sub+1, len_softirq);
//    string steal = cpu_load.substr(pos_eighth_sub+1, len_steal);
//
//    sleep(2);
//    ifstream il("/proc/stat");
//    getline(il,cpu_load);
//
//
//    string prevuser = cpu_load.substr(pos_first_sub+1, len_user);
//    string prevnice = cpu_load.substr(pos_second_sub+1, len_nice);
//    string prevsystem = cpu_load.substr(pos_third_sub+1, len_system);
//    string previdle = cpu_load.substr(pos_fourth_sub+1, len_idle);
//    string previowait = cpu_load.substr(pos_fifth_sub+1, len_iowait);
//    string previrq = cpu_load.substr(pos_sixth_sub+1, len_irq);
//    string prevsoftirq = cpu_load.substr(pos_seventh_sub+1, len_softirq);
//    string prevsteal = cpu_load.substr(pos_eighth_sub+1, len_steal);
//
//    long long prevIdle =  atoll(previdle.data())  + atoll(previowait.data());
//    long long Idle =  atoll(idle.data())  + atoll(iowait.data());
//
//    long long prevNonIdle =  atoll(prevuser.data())  + atoll(prevnice.data()) + atoll(prevsystem.data())                                                                                 + atoll(prevnice.data());
//    + atoll(previrq.data()) + atoll(prevsoftirq.data()) + atoll(prevsteal.data());
//    long long NonIdle =  atoll(user.data())  + atoll(nice.data()) + atoll(system.data())                                                                                 + atoll(prevnice.data());
//    + atoll(irq.data()) + atoll(softirq.data()) + atoll(steal.data());
//
//    long long prevTotal = prevIdle + prevNonIdle;
//    long long Total = Idle + NonIdle;
//
//    long long totald = Total - prevTotal;
//    long long idled = Idle - prevIdle;
//
//
//
//    int cpuld = (totald - idled)*100 / (int)totald;
//    cout << (totald - idled )/ totald<< endl;
//    cout << idle << endl;
//
//    cout << cpu_load << endl;
//    cout << user + " " << nice + " " << system  + " "<< idle  + " "<<  iowait + " " << irq  + " "<< softirq  + " "<<  steal + " " <<  endl;
//    cout << prevuser + " " << prevnice + " " << prevsystem  + " "<< previdle  + " "<<  previowait + " " << previrq  + " "<< prevsoftirq  + " "<<  prevsteal + " " <<  endl;
//    cout << cpuld << endl;
//    exit(0);
    Server server(port);
    server.server_start();


//    Tcp server;
//    server.set_port(12345);
//    server.set_domian(AF_INET);
//    server.set_type(SOCK_STREAM);
//
//    server.set_sin_addr(AF_INET);
//    server.Socket();
//    server.Bind();
//    server.Listen();
//    int socket_desk = server.Accept();
//
//    string s;
////    char s1[256];
//    int n;
//    while(1) {
//        char s1[256] = {'\0'};
//        read(socket_desk, s1, 256);
//        s.append(s1);
//        //TODO buffer min nez 256
//        if (s[s.size() - 1] == '\n' && s[s.size() - 2] == '\r' && s[s.size() - 3] == '\n' && s[s.size() - 4] == '\r') {
//            break;
//        }
//    }
//
//    HttpRequest request(s);
//    HTTPResponse response;
//
//    char hostname[255];
//    gethostname(hostname,255);
//    string cpu_info;
////    FILE* f = fopen("/proc/cpuinfo", "r");
//    ifstream in("/proc/cpuinfo");
//    while (getline(in,cpu_info)){
//        if(-1 != cpu_info.find("model name")){
//            break;
//        }
//    }
//
//    //pars CPU name
//    cpu_info = cpu_info.substr(cpu_info.find(':') + 2, cpu_info.find('\n') -cpu_info.find(':') - 1 );
//    //
//    cout << cpu_info << endl;
//    response.set_code("200");
//    response.set_status("OK");
//    response.set_server_name("localhost");
//    response.set_content_type("text/plain");
//    response.set_connection("Close");
//    response.set_body(hostname);
//    response.create_resp_mess();
//
//
//
//    write(socket_desk,response.get_resp_mess().data(),response.get_resp_mess().size());




    return 0;
}
