#include "headers\FCFS.h"
#include "headers\Display.hpp"

void FCFS::schedule()
{
    size_t taskcounter = 0;
    for (size_t i = 0; i < TIMESTEPS; ++i)
    {
        for (size_t k = 0; k < tasks.size(); ++k)
        {
            //Puts all of the tasks which arrive at the given timestep into the queue
            if (i == tasks[k].getStart())
            {
                //Assigns a row value to the given task (in the output matrix)
                tasks[k].setNr(taskcounter);
                taskcounter++;
                //Puts the element into the queue
                queue->enqueue(tasks[k]);
            }
        }
        if (!queue->isEmpty()) //If there are tasks in the queue
        { 
            //If the task is not finished yet
            --queue->firstElement();
            output->getElement(queue->firstElement().getNr(), i) = true;
            if (queue->firstElement().getCpu() == 0)
            {
                queue->dequeue();
            }
        }
    }
    //Displays the output
    Display::displayOutput(output);
}
