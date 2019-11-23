#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

/**
 * Generic Queue class
 * Implementation of the queue data structure using a circular array
 * Template: <typename>
 * 
 * Created by Patka Zsolt-Andr�s
 */
template <typename T>
class Queue
{
    T *elements;
    size_t first, rear, size;
    const size_t capacity;

public:
    /**
     * Queue constructor without parameters
     * Creates the queue and initializes the data members
     */
    Queue(size_t capacity = 10) : capacity(capacity)
    {
        elements = new T[capacity];
        rear = capacity - 1;
        size = 0;
        first = 0;
    }

    /**
     * Queue is empty function
     * @return true if the queue is empty, false if not
     */
    bool isEmpty()
    {
        return size == 0;
    }

    /**
     * Queue is full function
     * @return true if the queue is full, false if not
     */
    bool isFull()
    {
        return size == capacity;
    }

    /**
     * Enqueue
     * Enqueue an element
     * @throw const char * exception if the queue is full
     */
    void enqueue(T elem)
    {
        if (isFull())
        {
            throw "Queue is full";
        }
        rear = (rear + 1) % capacity;
        elements[rear] = elem;
        ++size;
    }

    /**
     * Dequeue
     * Dequeues an element
     * @throw const char * exception if the queue is empty
     */
    T dequeue()
    {
        if (isEmpty())
        {
            throw "Queue is empty";
        }
        --size;
        T item = elements[first];
        first = (first + 1) % capacity;
        return item;
    }
    /**
     * First Element.
     * @returns a reference to the first element (without dequeueing)
     */
    T &firstElement()
    {
        return elements[first];
    }

    /**
     * Queue destructor
     */
    ~Queue()
    {
        delete[] elements;
    }
};

#endif // QUEUE_HPP_INCLUDED
