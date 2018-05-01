#ifndef TASK_H_INCLUDED
#define TASK_H_INCLUDED
#include <stdlib.h>

///Created by Patka Zsolt-András

/**
 * Task class.
 */

class Task{
    unsigned int start;
    unsigned int cpu;
    unsigned int nr; ///Identifier (used for the output matrix)
public:
    static size_t MAXCPU;///Maximum value
    static size_t MAXSTART;///Maximum value

    /**
     * No parameter constructor
     */
    Task(){}
    /**
     * Constructor
     * Sets the start and cpu values
     */
    Task(unsigned int start, unsigned int cpu);
    unsigned int getStart() const{
        return start;
    }
    unsigned int getCpu()const{
        return cpu;
    }
    unsigned int getNr() const{
        return this->nr;
    }
    void setNr(unsigned int nr){
        this->nr=nr;
    }
    /**
     * operator--
     * Decrements the cpu value by one;
     */
    void operator--(){
        if(cpu > 0){
            --cpu;
        }
    }
};

#endif // TASK_H_INCLUDED
