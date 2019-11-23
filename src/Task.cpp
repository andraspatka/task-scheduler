#include "headers\Task.h"

size_t Task::MAXCPU=30;
size_t Task::MAXSTART=30;

Task::Task(unsigned int start, unsigned int cpu)
    :start(start), cpu(cpu){
    if( (cpu == 0) || (cpu > MAXCPU) || (start > MAXSTART) ){
        throw "Invalid cpu or start time value";
    }
}
