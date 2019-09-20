//
// Created by denislav on 21.08.19 г..
//

#ifndef LIST_INSERTIONSORT_H
#define LIST_INSERTIONSORT_H

template <class Type>
class Sort
{
public:
    static void insertionSort(Type* arr, int size)
    {
        Type current, j;
        for (int i = 1; i < size; i++)
        {
            current = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > current)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = current;
        }
    }
};

#endif //LIST_INSERTIONSORT_H
