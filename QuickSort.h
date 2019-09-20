//
// Created by denislav on 20.08.19 г..
//

#ifndef LIST_QUICKSORT_H
#define LIST_QUICKSORT_H

void quickSort(int* arr, int left, int right)
{
    int i = left;
    int j = right;
    int center = arr[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (arr[i] < center)
        {
            i++;
        }
        while (arr[j] > center)
        {
            j--;
        }
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j--;
            i++;
        }
    }
    if (j > left)
    {
        quickSort(arr, left, j);
    }
    if (i < right)
    {
        quickSort(arr, i, right);
    }
}

#endif //LIST_QUICKSORT_H
