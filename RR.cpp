#include "RR.h"

void RR::schedule(){
    size_t timecounter=0;
    size_t taskcounter=0;
    for(size_t i=0;i<TIMESTEPS;++i){
        for(size_t k=0;k<tasks.size();++k){
            ///Puts all of the tasks which arrive at the given time step into the queue
            if(i==tasks[k].getStart()){
                ///Assigns a row value to the given task (in the output matrix)
                tasks[k].setNr(taskcounter);
                ++taskcounter;
                queue->enqueue(tasks[k]);
            }
        }
        if(!queue->isEmpty()){
            if(timecounter < TIMESLICE){
                ++timecounter;
                --queue->firstElement();
                output->getElement(queue->firstElement().getNr(),i)=true;
                ///If the task is done, remove it
                if(queue->firstElement().getCpu()==0){
                    queue->dequeue();
                    timecounter=0;
                }
            }
            if(timecounter == TIMESLICE){ ///Time's up
                timecounter=0; ///Reset the counter
                if(queue->firstElement().getCpu()>0){ ///If the is not finished yet
                    queue->enqueue(queue->dequeue()); ///Requeue
                }
            }
        }
    }
    Display::displayOutput(output);
}
