#include "quicksort.h"

int partition(int *data, int leftBorder, int rightBorder)
{
    int pivot = data[rightBorder];
    int marker = leftBorder;
    int temp = 0;

    for (int j = leftBorder; j < rightBorder; j++)
    {
        if (data[j] <= pivot)
        {
            temp = data[marker];
            data[marker] = data[j];
            data[j] = temp;
            marker++;
        }
    }
    temp = data[marker];
    data[marker] = data[rightBorder];
    data[rightBorder] = temp;
    return marker;
}

void quickSortRecurs(int *data, int leftBorder, int rightBorder)
{
    if (leftBorder < rightBorder)
    {
        int indexPivot = partition(data, leftBorder, rightBorder);
        quickSortRecurs(data, leftBorder, indexPivot - 1);
        quickSortRecurs(data, indexPivot + 1, rightBorder);
    }
}
