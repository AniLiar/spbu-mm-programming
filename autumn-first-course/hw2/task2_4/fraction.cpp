#include "fraction.h"

int partition(Fraction *data, int leftBorder, int rightBorder)
{
    double pivot = data[rightBorder].value;
    int marker = leftBorder;
    Fraction temp;

    for (int j = leftBorder; j < rightBorder; j++)
    {
        if (data[j].value <= pivot)
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

void quickSortRecurs(Fraction *data, int leftBorder, int rightBorder)
{
    if (leftBorder < rightBorder)
    {
        int indexPivot = partition(data, leftBorder, rightBorder);
        quickSortRecurs(data, leftBorder, indexPivot - 1);
        quickSortRecurs(data, indexPivot + 1, rightBorder);
    }
}
