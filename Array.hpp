#ifndef ARRAY_HPP_INCLUDED
#define ARRAY_HPP_INCLUDED

#include <algorithm>
#include <iostream>

///Created by Patka Zsolt-András

/**
 * Generic dynamic Array class
 */

template <typename T>
class Array{
    T * data;
    size_t capacity;
public:
    /**
     * Constructor
     * Sets the size to the given amount
     */
    Array(size_t capacity=10):capacity(capacity){
        data = new T[capacity];
    }
    ///Copy constructor
    Array(const Array& arr){
        capacity=arr.size();
        data = new T[capacity];
        for(size_t i=0;i<capacity;++i){
            data[i]=arr[i];
        }
    }
    /**
     * Index operator
     * @param index: the index to the element
     * @returns a reference to the given element
     */
    T& operator[](size_t index)const{
        if(index >= capacity){
            throw "nem megfelelo index";
        }
        return data[index];
    }
    /**
     * Assignment operator
     */
    Array& operator=(const Array& a){
        if(&a != this){
            delete[] data;
            capacity=a.size();
            data = new T[capacity];
            for(size_t i=0;i<capacity;++i){
                data[i]=a[i];
            }
        }
        return *this;
    }
    /**
     * Size.
     * @returns the size of the array
     */
    size_t size()const{
        return capacity;
    }

    ~Array(){
        delete[] data;
    }
};

#endif // ARRAY_HPP_INCLUDED
