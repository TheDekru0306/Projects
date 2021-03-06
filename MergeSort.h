//
// Created by dennykrumov on 6.09.19 г..
//

#ifndef TASKS_MERGESORT_H
#define TASKS_MERGESORT_H

void merge(int *array, int low, int mid, int high)
{
    int temp[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid)
    {
        temp[k++] = array[i++];
    }

    while (j <= high)
    {
        temp[k++] = array[j++];
    }
    k--;
    while (k >= 0)
    {
        array[k + low] = temp[k];
        k--;
    }
}

void mergeSort(int *array, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}


#endif //TASKS_MERGESORT_H
