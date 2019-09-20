//
// Created by denislav on 21.08.19 г..
//

#ifndef LIST_STACK_H
#define LIST_STACK_H

#include <stdexcept>

template <typename Type>
class Stack
{
private:
    int length, capacity;
    Type* arr;

public:
    Stack();
    ~Stack();
    Type top();
    void pop();
    void add(Type value);
    bool empty();
};

template<typename Type>
Stack<Type>::Stack()
{
    capacity = 4;
    length = 0;
    arr = nullptr;
}

template<typename Type>
void Stack<Type>::add(Type value)
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
void Stack<Type>::pop()
{
    if(length)
    {
        length--;
    }
    else
    {
        throw std::logic_error("No elements in the stack!");
    }
}

template<typename Type>
Type Stack<Type>::top()
{
    if(length)
    {
        return arr[length - 1];
    }
    throw std::logic_error("No elements in the stack!");
}

template<typename Type>
bool Stack<Type>::empty()
{
    return !(bool)length;
}

template<typename Type>
Stack<Type>::~Stack()
{
    delete[] arr;
}

#endif //LIST_STACK_H
