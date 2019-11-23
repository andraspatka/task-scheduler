#ifndef MATRIX_HPP_INCLUDED
#define MATRIX_HPP_INCLUDED

#include <iostream>

///Created by Patka Zsolt-András

/**
 * Generic Matrix data structure.
 * Represented in the memory as a one dimensional array
 */

template <typename T>
class Matrix{
private:
    size_t sizeX;
    size_t sizeY;
    T * data;
public:
    /**
     * Constructor.
     * @param x: number of rows
     * @param y: number of columns
     */
    Matrix(size_t sizeX, size_t sizeY): sizeX(sizeX),sizeY(sizeY){
        data = new T[sizeX*sizeY];
    }
    /**
     * Copy constructor.
     * @param rhv: right hand value
     */
    Matrix(const Matrix& rhv){
        sizeX=rhv.getX();
        sizeY=rhv.getY();
        data = new T[sizeX * sizeY];
        for(size_t i=0; i<sizeX*sizeY;++i){
            data[i]=rhv[i];
        }
    }
    /**
     * getElement.
     * Gets the element at the given index
     * @param x: x axis (row)
     * @param y: y axis (column)
     * @return a reference to the element
     * @throws const char* exception in case of an incorrect index
     */
    T& getElement(size_t x, size_t y){
        if( (x<sizeX)&&(y<sizeY) )
            return data[x * sizeY + y];
        else{
            throw "Incorrect index";
        }
    }
    /**
     * nullify.
     * Sets all of the elements of the Matrix to 0
     * Only use if storing 0 in your type doesn't result in undefined behaviour
     * @return the number of rows
     */
    void nullify(){
        for(size_t i=0;i<sizeX*sizeY;++i){
            data[i]=0;
        }
    }
    /**
     * operator[].
     * Makes the Matrix class behave like an array with a size of sizeX*sizeY
     * @param index: the index to the desired element
     * @return reference to the given element
     * @throws const char * exception in the case of an incorrect index
     */
    T& operator[](size_t index)const{
        if((index >= 0) && (index < sizeX * sizeY)){
            return data[index];
        }else throw "Incorrect index";
    }

    /**
     * @return the number of rows
     */
    size_t getX() const{
        return sizeX;
    }
    /**
     * @return the number of columns
     */
    size_t getY() const{
        return sizeY;
    }
    ~Matrix(){
        delete []data;
    }
};

#endif // MATRIX_HPP_INCLUDED
