//
// Created by denislav on 19.08.19 г..
//

#ifndef LIST_DOUBLELINKEDLIST_H
#define LIST_DOUBLELINKEDLIST_H

#include <stdexcept>

template <typename DataType>
class Node{
public:
    DataType data;
    Node* next;
    Node* prev;
};

template <class Type>
class DLL{
private:
    Node<Type>* findElement(int position);
    Node<Type>* head;
    Node<Type>* tail;
    Node<Type>* current;
    int length = 0;

public:
    DLL();
    explicit DLL(Type value);
    ~DLL();
    void add(Type value);
    void remove(int position);
    void edit(int position, Type value);
    bool isEmpty();
    int find(Type element);
    Type getValue(int position);
    void display();
};

template<class Type>
DLL<Type>::DLL() {
    head = nullptr;
    tail = nullptr;
}

template<class Type>
DLL<Type>::DLL(Type value) {
    current = new Node<Type>();
    current->prev = nullptr;
    head = current;
    tail = current;
}

template<class Type>
DLL<Type>::~DLL()
{
    auto temp = tail;

    for (int i = length; i > 0; i--)
    {
        temp = temp->prev;
        delete tail;
        tail = temp;
    }
    delete tail;
}

template<class Type>
void DLL<Type>::add(Type value)
{
    current = new Node<Type>();
    current->data = value;
    if(isEmpty())
    {
        current->next = nullptr;
        head = current;
        tail = current;
    }
    else
    {
        current->prev = tail;
        current->next = nullptr;
        tail->next = current;
        tail = current;
    }
    length++;
}

template<class Type>
void DLL<Type>::remove(int position)
{
    auto temp = head;

   if(position >= 0 && position <= length)
   {
       for (int i = 1; i <= position; ++i)
       {
           temp = temp->next;
       }

       temp->prev->next = temp->next;

       if(temp->next)
       {
           temp->next->prev = temp->prev;
       }

       if(temp->next == nullptr)
       {
           tail = temp->prev;
       }
       if(temp->prev == nullptr)
       {
           head = temp->next;
       }
       delete temp;
       length--;
   }
   else
   {
       throw std::logic_error("No element on position: " + position);
   }
}

template<class Type>
void DLL<Type>::edit(int position, Type value)
{
    auto temp = findElement(position);

    temp->data = value;
}

template<class Type>
int DLL<Type>::find(Type element)
{
    auto temp = head;

    for (int position = 1; position <= length; ++position)
    {
       if(temp->data == element)
       {
           return position;
       }
       temp = temp->next;
    }

    return -1;
}

template<class Type>
bool DLL<Type>::isEmpty() {
    return head == nullptr;
}

template<class Type>
Node<Type> *DLL<Type>::findElement(int position)
{
    auto temp = head;
    if(position >= 0 && position <= length)
    {
        for (int i = 1; i < position; ++i)
        {
            temp = temp->next;
        }

        return temp;
    }
    throw std::logic_error("No element on position: " + position);
}

template<class Type>
Type DLL<Type>::getValue(int position)
{
    return findElement(position)->data;
}

template<class Type>
void DLL<Type>::display()
{
    auto temp = head;
    for (int i = 0; i < length; ++i) {
        std::cout<<temp->data<< " ";
        temp = temp->next;
    }
    std::cout<<"\n";
}

#endif //LIST_DOUBLELINKEDLIST_H
