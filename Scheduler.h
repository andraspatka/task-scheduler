#ifndef SCHEDULER_H_INCLUDED
#define SCHEDULER_H_INCLUDED

#include "Task.h"
#include "Queue.hpp"
#include "Matrix.hpp"
#include "Array.hpp"

///Created by Patka Zsolt-András

/**
 * Scheduler
 * Schedules tasks which it receives from a Task array
 */
class Scheduler{
protected:
    Array<Task> tasks;
    Queue<Task> * queue; ///The queue used by the scheduling algorithms
    Matrix<bool> * output; ///This stores the output of the scheduler. A matrix in array form
public:
    static size_t TIMESTEPS;
    /**
     * No parameter constructor
     */
    Scheduler();
    /**
     * Constructor
     * @param tasks: Task Array, stores the tasks which are to be scheduled
     */
    Scheduler(Array<Task> tasks);
    /**
     * Replaces the current tasks
     * @param tasks: Task Array, stores the tasks which are to be scheduled
     */
    void addTasks(Array<Task> tasks);
    /**
     * Schedule
     * Purely virtual function
     */
    virtual void schedule()=0;

    virtual ~Scheduler(){
        delete queue;
        delete output;
    }
};



#endif // SCHEDULER_H_INCLUDED
