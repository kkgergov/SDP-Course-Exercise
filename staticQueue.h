#pragma once

#ifndef QUEUE_HEADER
#define QUEUE_HEADER

#include <stdexcept>
#define MAX_SIZE 1000

template <class DataType>
class Queue
{
public:
    Queue();
    Queue(const Queue<DataType>&);
    Queue<DataType>& operator=(const Queue<DataType>&);

    bool isEmpty() const;
    bool isFull() const;

    void enqueue(const DataType&);
    DataType dequeue();
    const DataType& first() const;

private:
    DataType data[MAX_SIZE];
    int begin, end, size;    
};

#include "staticQueue.inl"

#endif