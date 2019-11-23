#ifndef FIFO_H_INCLUDED
#define FIFO_H_INCLUDED

#include "Display.hpp"
#include "Scheduler.h"


///Created by Patka Zsolt-András

/**
 * First Come First Served.
 * Class which implements the FCFS algorithm
 * Works with Array<Task> and Matrix<bool> types
 * The tasks are stored in an Array<Task> type collection
 * The output is stored in a Matrix<bool> type collection
 */

class FCFS: public Scheduler, public Display{
public:
    /**
     * One parameter constructor.
     * @param tasks : An Array of Tasks
     */
    FCFS(Array<Task> tasks):Scheduler(tasks){}
    /**
     * Schedule
     * Overrides the base class's pure virtual function
     * Implements an FCFS scheduler
     */
    void schedule();
    /**
     * Destructor
     */
    ~FCFS(){}
};


#endif // FIFO_H_INCLUDED
