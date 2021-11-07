#ifndef QUEUE_SOURCE
#define QUEUE_SOURCE

template <class DataType>
inline Queue<DataType>::Queue() : begin(0), end(0), size(0){}

template <class DataType>
inline Queue<DataType>::Queue(const Queue<DataType>& other) : begin(0), end(0), size(other.size)
{
    for(int pos = other.begin; pos != other.end; pos = (pos+1) % MAX_SIZE)
    {
        enqueue(other.data[pos]);
    }
}

template <class DataType>
inline Queue<DataType>& Queue<DataType>::operator=(const Queue<DataType>& other)
{
    if(this != &other)
    {
        begin = end = 0;
        size = other.size;

        for(int pos = other.begin; pos != other.end; pos = (pos+1) % MAX_SIZE)
        {
            enqueue(other.data[pos]);
        }   
    }

    return *this;
}

template <class DataType>
inline bool Queue<DataType>::isEmpty() const
{
    return end == begin;
}

template <class DataType>
inline bool Queue<DataType>::isFull() const
{
   return (end + 1) % MAX_SIZE == begin; 
}

template <class DataType>
inline void Queue<DataType>::enqueue(const DataType& elem)
{
    if(!isFull()){
        data[end] = elem;
        end = (end + 1) % MAX_SIZE;
    }
    else
        throw std::overflow_error("Queue is full!");
}

template <class DataType>
inline DataType Queue<DataType>::dequeue()
{
    if(!isEmpty()){
        const DataType &result = data[begin];
        begin = (begin + 1) % MAX_SIZE;
        return result;
    }
    else
        throw std::underflow_error("Queue is empty!");
}

template <class DataType>
inline const DataType& Queue<DataType>::first() const
{
    if(!isEmpty()){
        return data[begin];
    }
    else
        throw std::underflow_error("Queue is empty!");
}

#endif