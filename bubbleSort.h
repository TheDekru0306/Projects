//
// Created by denislav on 16.08.19 г..
//

#ifndef LIST_BUBBLESORT_H
#define LIST_BUBBLESORT_H

void bubbleSort(int* arr, int n)
{
    int temp;
    int i;
    int j;

    for (i = 1; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

#endif //LIST_BUBBLESORT_H
