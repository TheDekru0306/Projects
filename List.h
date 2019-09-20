#include <iostream>

#define DEFAULT_CAPACITY 4

template <class Type>
class List{
private:
    int capacity, length;
    Type* arr;

public:
    List();
    explicit List(int size);
    ~List();
    void add(Type value);
    void remove(int index);
    void swap(int addr_One, int addr_Two);
    int getLength();
    Type& operator[](int index);
    friend std::ostream& operator<<(std::ostream& os, Type& value);
    Type& operator=(Type value);
};

template<class Type>
List<Type>::List() {
    capacity = DEFAULT_CAPACITY;
    arr = new Type[capacity];
    length = 0;
}

template<class Type>
List<Type>::List(int size) {
    capacity = size * 2;
    Type* newArr[capacity];
    arr = newArr;
    length = size;
}

template<class Type>
void List<Type>::add(Type value) {
    if(length + 1 == this->capacity)
    {
        capacity *= 2;
        Type* newArr = new Type[capacity];

        for (int i = 0; i < length; ++i) {
            newArr[i] = arr[i];
        }

        newArr[length] = value;
        delete[] arr;
        arr = newArr;
        length++;
    }
    else
    {
        arr[length] = value;
        length++;
    }
}

template<class Type>
void List<Type>::remove(int index) {
    if(length - 1 < 0)
    {
        std::cout<<"No elements to remove."<<"\n";
    }
    else if(index >= length)
    {
        std::cout<<"No such address."<<"\n";
    }
    else
    {
        for (int i = index; i < length - 1; ++i) {
            swap(i, (i + 1));
        }
        length--;
    }
}

template<class Type>
void List<Type>::swap(int addr_One, int addr_Two) {
    try {
        Type temp = this->arr[addr_One - 1];
        this->arr[addr_One] = this->arr[addr_Two];
        this->arr[addr_Two] = temp;
    }
    catch(const std::exception&){
        std::cout<<"Invalid address's.";
    }
}

template<class Type>
Type &List<Type>::operator[](int index) {
    if(index < length && index >= 0)
    {
        return arr[index];
    }
    else
    {
        std::cout<<"Invalid Address."<<"\n";
    }
}

template<class Type>
List<Type>::~List() {
    delete[] arr;
}

template <class Type>
std::ostream &operator<<(std::ostream &os, Type &value) {
    return os << value;
}

template<class Type>
Type &List<Type>::operator=(Type value) {
    return value;
}

template<class Type>
int List<Type>::getLength() {
    return length;
}
