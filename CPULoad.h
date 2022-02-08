#ifndef IPK_PROJ1CPP_CPULOAD_H
#define IPK_PROJ1CPP_CPULOAD_H
#include <iostream>
using namespace std;



class CPU_Load{
private:
    unsigned long pos_first_sub;
    unsigned long pos_second_sub;
    unsigned long pos_third_sub;
    unsigned long pos_fourth_sub;
    unsigned long pos_fifth_sub;
    unsigned long pos_sixth_sub;
    unsigned long pos_seventh_sub;
    unsigned long pos_eighth_sub;
    unsigned long pos_ninth_sub;
    unsigned long len_user;
    unsigned long len_nice;
    unsigned long len_system;
    unsigned long len_idle;
    unsigned long len_iowait;
    unsigned long len_irq;
    unsigned long len_softirq;
    unsigned long len_steal;

    string user;
    string nice;
    string system;
    string idle;
    string iowait;
    string irq;
    string softirq;
    string steal;

    string prevuser;
    string prevnice;
    string prevsystem;
    string previdle;
    string previowait;
    string previrq;
    string prevsoftirq;
    string prevsteal;

    void set_load();
    void set_prev_load();

public:
    CPU_Load();
    string get_cpu_load();



};


#endif //IPK_PROJ1CPP_CPULOAD_H
