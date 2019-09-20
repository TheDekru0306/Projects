//
// Created by denislav on 13.09.19 г..
//

#ifndef LIST_SUMFINDER_H
#define LIST_SUMFINDER_H
#include <iostream>
void combinations(int arr[], int index, int value, int reducedValue)
{
    int prev;

    if (reducedValue < 0)
        return;

    if (reducedValue == 0)
    {
        for (int i = 0; i < index; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << '\n';
        return;
    }

    if(index == 0)
    {
        prev = 1;
    }
    else
    {
        prev = arr[index - 1];
    }

    for (int i = prev; i <= value ; i++)
    {
        arr[index] = i;
        combinations(arr, index + 1, value,reducedValue - i);
    }
}

void sumFinder(int n)
{
    int arr[n];

    combinations(arr, 0, n, n);
}
#endif //LIST_SUMFINDER_H
