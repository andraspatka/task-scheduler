#include <iostream>
#include <fstream>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "headers\Queue.hpp"
#include "headers\FCFS.h"
#include "headers\Task.h"
#include "headers\Scheduler.h"
#include "headers\Matrix.hpp"
#include "headers\Array.hpp"
#include "headers\RR.h"

using namespace std;

/**
 * Handling endline characters on different systems
 */
std::istream &safeGetLine(std::istream &is, std::string &t)
{
    t.clear(); //clears the string
    int c;

    while (1)
    {
        c = is.get();
        switch (c)
        {
            case '\n':
                return is;
            case '\r':
                is >> c;
                return is;
            case -1: //In the case of eof
                // Handles the case when the last line has no line ending
                if (t.empty())
                    is.setstate(std::ios::eofbit);
                return is;
            default:
                t += (char)c;
        }
    }
}

int main()
{
    //Path to the input file
    string path = "input.txt";
    //Input file stream
    ifstream ifs(path.c_str());
    if (!ifs)
    {
        cout << "Failed to open the file." << endl;
        return -1;
    }

    string t;
    string all;
    //Read the file contents to a string
    while (!safeGetLine(ifs, t).eof())
    {
        all += t;
        all += " "; //Separate the fields by a space character
    }
    stringstream ss(all);
    //Scheduler type
    string sch_type;

    while (ss >> sch_type)
    {
        //Make the sch_type string upper case
        std::transform(sch_type.begin(), sch_type.end(), sch_type.begin(), ::toupper);
        size_t timeslice = 2;
        Scheduler *sch;       //Base class pointer
        if (sch_type == "RR") //In the case of an RR scheduler
        {
            ss >> timeslice;         //The timeslice needs to be read
            sch = new RR(timeslice); //Create the appropriate derived class
        }
        else if (sch_type == "FCFS") //In the case of an FCFS scheduler
        {
            sch = new FCFS(timeslice); //Create the appropriate derived class
        }
        else
        {
            cout << "Error: " << sch_type << " undefined scheduler";
            return -1;
        }

        size_t taskno;
        ss >> taskno;              //Read the number of tasks
        Array<Task> tasks(taskno); //Create an Array of appropriate size
        for (size_t i = 0; i < taskno; ++i)
        { //Read all the tasks and put them into the array
            size_t cpu, start;
            ss >> start;
            ss >> cpu;
            Task t(start, cpu);
            tasks[i] = t; //Building up the task array
        }
        sch->addTasks(tasks);
        sch->schedule();
        delete sch;
    }

    //Close the input file
    ifs.close();
    return 0;
}
