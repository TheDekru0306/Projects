//
// Created by denislav on 21.08.19 г..
//

#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include <stdexcept>

template <typename Type>
class Queue
{
private:
    int length, capacity;
    Type* arr;

public:
    Queue();
    ~Queue();
    Type back();
    Type front();
    void pop();
    int size();
    void add(Type value);
    bool empty();
};

template<typename Type>
Queue<Type>::Queue()
{
    capacity = 4;
    length = 0;
    arr = nullptr;
}

template<typename Type>
void Queue<Type>::add(Type value)
{
    if(length + 1 == capacity)
    {
        capacity *= 2;
        Type* newArr = new Type[capacity];

        for (int i = 0; i < length; ++i)
        {
            newArr[i] = arr[i];
        }

        newArr[length] = value;
        length++;
        delete arr;
        arr = newArr;
    }
    else
    {
        arr[length] = value;
        length++;
    }
}

template<typename Type>
void Queue<Type>::pop()
{
    if(length)
    {
        Type* newArr = new Type[capacity];

        for (int i = 1; i < size(); ++i)
        {
            newArr[i - 1] = arr[i];
        }

        length--;
        delete[] arr;
        arr = newArr;
    }
    else
    {
        throw std::logic_error("No elements in the queue!");
    }
}

template<typename Type>
Type Queue<Type>::back()
{
    if(length)
    {
        return arr[length - 1];
    }
    throw std::logic_error("No elements in the queue!");
}

template<typename Type>
bool Queue<Type>::empty()
{
    return !(bool)length;
}

template<typename Type>
Queue<Type>::~Queue()
{
    delete[] arr;
}

template<typename Type>
int Queue<Type>::size() {
    return length;
}

template<typename Type>
Type Queue<Type>::front() {
    if(length)
    {
        return arr[0];
    }
    throw std::logic_error("No elements in the queue!");
}

#endif //LIST_QUEUE_H
