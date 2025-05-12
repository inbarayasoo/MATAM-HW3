#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<new>
template<class item>
class Queue {
public:
    Queue();
    Queue(const Queue &);
    Queue &operator=(const Queue &);
    ~Queue();
    void pushBack(const item&);
    void popFront();
    int size() const;
    item& front() const;
    item& front();
    class EmptyQueue{};
    class Iterator;
    Iterator begin();
    Iterator end();
    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;
private:
    item *m_data;
    int m_size;
    int m_maxSize;
    void expand();
    static const int EXPAND_RATE = 2;
    static const int INITIAL_SIZE = 10;
};

template<class item>
Queue<item>::Queue() :
        m_data(new item[INITIAL_SIZE]),
        m_size(0),
        m_maxSize(INITIAL_SIZE)
{}
template<class item>
Queue<item>::Queue(const Queue<item>& queue) :
        m_data(new item[queue.m_maxSize]),
        m_size(queue.m_size),
        m_maxSize(queue.m_maxSize)
{
    try
    {
        for (int i = 0; i < m_size; i++)
        {
            m_data[i] = queue.m_data[i];
        }
    }
    catch(...)
    {
        delete[] m_data;
        throw ;
    }
}
template<class item>
Queue<item>& Queue<item>::operator=(const Queue<item>& queue)
{
    if (this == &queue)
    {
        return *this;
    }
    item* tempData = new item[queue.m_maxSize];
    try
    {
        m_size = queue.m_size;
        m_maxSize = queue.m_maxSize;
        for (int i = 0; i < m_size; ++i)
        {
            tempData[i] = queue.m_data[i];
        }
    }
    catch(...)
    {
        delete[] tempData;
        throw ;
    }
    delete[] m_data;
    m_data = tempData;
    return *this;
}
template<class item>
Queue<item>::~Queue()
{
    delete[] m_data;
}
//Push to the array an element to the end of the queue.
template<class item>
void Queue<item>::pushBack(const item& element)
{
    m_data[m_size] = element;
    m_size++;
    if (m_size >= m_maxSize)
    {
        expand();
    }
}
//Remove the first element of the queue.
template<class item>
void Queue<item>::popFront()
{
    if (m_size <= 0)
    {
        throw EmptyQueue();
    }
    for(int index=0;index < m_size-1;index++)
    {
        m_data[index]=m_data[index+1];
    }
    m_size--;
}
//Returns the amount of elements in the queue
template<class item>
int Queue<item>::size() const
{
    return m_size;
}
//Returns the first element in the queue but without the possibility to change it
template<class item>
item& Queue<item>::front() const
{
    if(m_size <= 0)
    {
        throw EmptyQueue();
    }
    return m_data[0];
}
// Returns the first element in the queue
template<class item>
item& Queue<item>::front()
{
    if(m_size <= 0)
    {
        throw EmptyQueue();
    }
    return m_data[0];
}
//Creates another array as big as 2 times as the current array and copy all the elements to the new array.
template<class item>
void Queue<item>::expand()
{
    int newSize = m_maxSize * EXPAND_RATE;
    item* newData = new item[newSize];
    try
    {
        for (int i = 0; i < m_size; ++i)
        {
            newData[i] = m_data[i];
        }
    }
    catch(...)
    {
        delete[] newData;
        throw;
    }
    delete[] m_data;
    m_data = newData;
    m_maxSize = newSize;
}
//Filtering the elements of the queue by condition and creates another queue for the elements that match the condition.
template<class item,class Condition>
Queue <item> filter(const Queue<item> &queue , Condition condition)
{
    Queue<item> newQueue;
//    for(typename Queue<item>::ConstIterator it=queue.begin();it!=queue.end();++it)
    for(const item& value: queue)
    {
        if(condition(value))
        {
            newQueue.pushBack(value);
        }
    }
    return newQueue;
}
//Changes all the element of the queue with the given function.
template<class item,class Transformer>
void transform(Queue<item> &queue , Transformer function)
{
//    for(typename Queue<item>::Iterator it=queue.begin();it!=queue.end();++it)
    for(item& value : queue)
    {
        function(value);
    }
}
//iterator for queue object
template<class item>
class Queue<item>::Iterator {
public:
    class InvalidOperation{};
    item& operator*();
    Iterator& operator++();
    bool operator!=(const Iterator& iterator) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    ~Iterator()=default;
private:
    const Queue<item>* m_queue;
    int m_index;
    Iterator(const Queue<item>* queue, int index);
    friend class Queue<item>;
};
template<class item>
typename Queue<item>::Iterator Queue<item>::begin()
{
    return Iterator(this, 0);
}
template<class item>
typename Queue<item>::Iterator Queue<item>::end()
{
    return Iterator(this, m_size);
}
template<class item>
Queue<item>::Iterator::Iterator(const Queue<item>* queue, int index) :
        m_queue(queue), m_index(index)
{}
template<class item>
item& Queue<item>::Iterator::operator*()
{
    if(m_index >= m_queue->m_size)
    {
        throw InvalidOperation();
    }
    return m_queue->m_data[m_index];
}
template<class item>
typename Queue<item>::Iterator& Queue<item>::Iterator::operator++()
{
    if(m_index >= m_queue->m_size)
    {
        throw InvalidOperation();
    }
    ++m_index;
    return *this;
}
template<class item>
bool Queue<item>::Iterator::operator!=(const Iterator& iterator) const
{
    return m_index != iterator.m_index;
}
//iterator for const queue object
template<class T>
class Queue<T>::ConstIterator {
public:
    class InvalidOperation{};
    const T& operator*() const;
    ConstIterator& operator++();
    bool operator!=(const ConstIterator& constIterator) const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;
    ~ConstIterator()=default;
private:
    const Queue<T>* m_queue ;
    int m_index;
    ConstIterator(const Queue<T>* queue, int index);
    friend class Queue<T>;
};

template<class item>
typename Queue<item>::ConstIterator Queue<item>::begin() const
{
    return ConstIterator(this, 0);
}
template<class item>
typename Queue<item>::ConstIterator Queue<item>::end() const
{
    return ConstIterator(this, m_size);
}
template<class item>
Queue<item>::ConstIterator::ConstIterator(const Queue<item>* queue, int index) :
        m_queue(queue), m_index(index)
{}
template<class item>
const item& Queue<item>::ConstIterator::operator*() const
{
    if(m_index>=m_queue->m_size)
    {
        throw InvalidOperation();
    }
    return m_queue->m_data[m_index];
}
template<class item>
typename Queue<item>::ConstIterator& Queue<item>::ConstIterator::operator++()
{
    if(m_index>=m_queue->m_size)
    {
        throw InvalidOperation();
    }
    ++m_index;
    return *this;
}
template<class item>
bool Queue<item>::ConstIterator::operator!=(const ConstIterator& constIterator) const
{
    return m_index != constIterator.m_index;
}

#endif