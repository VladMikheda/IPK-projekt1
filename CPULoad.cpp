#include "CPULoad.h"
#include <unistd.h>
#include <fstream>
using namespace std;



 void CPU_Load::set_load(){
    ifstream in("/proc/stat"); //todo
    string cpu_info;
    getline(in,cpu_info);
    user = cpu_info.substr(pos_first_sub+1, len_user);
    nice = cpu_info.substr(pos_second_sub+1, len_nice);
    system = cpu_info.substr(pos_third_sub+1, len_system);
    idle = cpu_info.substr(pos_fourth_sub+1, len_idle);
    iowait = cpu_info.substr(pos_fifth_sub+1, len_iowait);
    irq = cpu_info.substr(pos_sixth_sub+1, len_irq);
    softirq = cpu_info.substr(pos_seventh_sub+1, len_softirq);
    steal = cpu_info.substr(pos_eighth_sub+1, len_steal);
}

 void CPU_Load::set_prev_load(){
    ifstream in("/proc/stat"); //todo
    string cpu_info;
    getline(in,cpu_info);
    prevuser = cpu_info.substr(pos_first_sub+1, len_user);
    prevnice = cpu_info.substr(pos_second_sub+1, len_nice);
    prevsystem = cpu_info.substr(pos_third_sub+1, len_system);
    previdle = cpu_info.substr(pos_fourth_sub+1, len_idle);
    previowait = cpu_info.substr(pos_fifth_sub+1, len_iowait);
    previrq = cpu_info.substr(pos_sixth_sub+1, len_irq);
    prevsoftirq = cpu_info.substr(pos_seventh_sub+1, len_softirq);
    prevsteal = cpu_info.substr(pos_eighth_sub+1, len_steal);
}


 CPU_Load::CPU_Load(){
    ifstream in("/proc/stat"); //todo
    string cpu_info;
    getline(in,cpu_info);
    pos_first_sub = cpu_info.find(' ') + 1;
    pos_second_sub = cpu_info.find(' ', pos_first_sub + 1);
    pos_third_sub = cpu_info.find(' ', pos_second_sub + 1);
    pos_fourth_sub = cpu_info.find(' ', pos_third_sub + 1);
    pos_fifth_sub = cpu_info.find(' ', pos_fourth_sub + 1);
    pos_sixth_sub = cpu_info.find(' ', pos_fifth_sub + 1);
    pos_seventh_sub = cpu_info.find(' ', pos_sixth_sub + 1);
    pos_eighth_sub = cpu_info.find(' ', pos_seventh_sub + 1);
    pos_ninth_sub = cpu_info.find(' ', pos_eighth_sub + 1);

    len_user = pos_second_sub - (pos_first_sub + 1);
    len_nice = pos_third_sub - (pos_second_sub + 1);
    len_system = pos_fourth_sub - (pos_third_sub + 1);
    len_idle = pos_fifth_sub - (pos_fourth_sub + 1);
    len_iowait = pos_sixth_sub - (pos_fifth_sub + 1);
    len_irq = pos_seventh_sub - (pos_sixth_sub + 1);
    len_softirq = pos_eighth_sub - (pos_seventh_sub + 1);
    len_steal  = pos_ninth_sub - (pos_eighth_sub + 1);
}

 string CPU_Load::get_cpu_load(){

    set_load();
    sleep(1);
    set_prev_load();

    long long prevIdle =  atoll(previdle.data())  + atoll(previowait.data());
    long long Idle =  atoll(idle.data())  + atoll(iowait.data());
    long long prevNonIdle =  atoll(prevuser.data())  + atoll(prevnice.data()) + atoll(prevsystem.data())                                                                                 + atoll(prevnice.data());
    + atoll(previrq.data()) + atoll(prevsoftirq.data()) + atoll(prevsteal.data());
    long long NonIdle =  atoll(user.data())  + atoll(nice.data()) + atoll(system.data())                                                                                 + atoll(prevnice.data());
    + atoll(irq.data()) + atoll(softirq.data()) + atoll(steal.data());

    long long prevTotal = prevIdle + prevNonIdle;
    long long Total = Idle + NonIdle;

    long long totald = Total - prevTotal;
    long long idled = Idle - prevIdle;

    return to_string(((totald - idled)*100 / totald)).append("%");
}


