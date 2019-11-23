#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <iomanip>
#include <iostream>
#include "Matrix.hpp"

///Created by Patka Zsolt-András

/**
 * Display class.
 * Can be changed to any class which implements the displayOutput function and can work with the output Matrix
 */

using std::cout;

class Display{
public:
    /**
     * Displays the output matrix to the standard output
     * @param output: this contains the output of the scheduling algorithm
     */
    void displayOutput(Matrix<bool> * output){
        std::cout<<std::endl<<std::endl;
        for(size_t i=0;i<output->getX();++i){
            for(size_t j=0;j<output->getY();++j){
                std::cout<<std::setw(2)<<  std::setfill(' ')<<output->getElement(i,j)<<" ";
            }
            std::cout<<std::endl;
        }
        for(size_t i=0; i<output->getY();++i){
            cout<<std::setw(2)<<  std::setfill(' ')<<i<<" ";
        }
    }
};

#endif // DISPLAY_H_INCLUDED
