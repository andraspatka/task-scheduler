#include "Scheduler.h"

size_t Scheduler::TIMESTEPS=40;

void Scheduler::addTasks(Array<Task> tasks){
    ///If there is memory allocated for the queue, free it
    if(queue!=NULL) delete queue;
    ///If there is memory allocated for the output matrix, free it
    if(output!=NULL) delete output;

    this->tasks = tasks;
    queue = new Queue<Task>(tasks.size());
    output = new Matrix<bool>(tasks.size(),TIMESTEPS);
    output->nullify();
}

Scheduler::Scheduler(Array<Task> tasks){
    this->tasks = tasks;
    queue = new Queue<Task>(tasks.size());
    output = new Matrix<bool>(tasks.size(),TIMESTEPS);
    output->nullify();
}

Scheduler::Scheduler(){
    queue=NULL;
    output=NULL;
}
