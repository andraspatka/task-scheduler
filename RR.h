#ifndef RR_H_INCLUDED
#define RR_H_INCLUDED

#include "Display.hpp"
#include "Scheduler.h"

///Created by Patka Zsolt-András

/**
 * Round Robin scheduler.
 * Class which implements the RR algorithm
 * Works with Array<Task> and Matrix<bool> types
 * The tasks are stored in an Array<Task> type collection
 * The output is stored in a Matrix<bool> type collection
 */


class RR: public Scheduler, public Display{
    const size_t TIMESLICE;
public:
    /**
     * One parameter constructor
     * Sets the timeslice
     */
    RR(size_t timeslice): TIMESLICE(timeslice){}
    /**
     * Two parameter constructor
     * Sets the timeslice and the tasks Array
     */
    RR(size_t timeslice, Array<Task> tasks): Scheduler(tasks), TIMESLICE(timeslice){}

    /**
     * schedule
     * Overrides the base class's pure virtual function
     * Implementation of the RR scheduler
     */
    void schedule();

    ~RR(){
    }

};

#endif // RR_H_INCLUDED
