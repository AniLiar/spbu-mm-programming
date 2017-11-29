#include "heapsort.h"

void shiftDown(char *heap, int ind, int count)
{
    while (true)
    {
        int indChildL = 2 * ind + 1;
        int indChildR = 2 * ind + 2;
        int indMaxValue = ind;

        if ((indChildL < count) && (heap[indMaxValue] < heap[indChildL]))
        {
            indMaxValue = indChildL;
        }
        if ((indChildR < count) && (heap[indMaxValue] < heap[indChildR]))
        {
            indMaxValue = indChildR;
        }
        if (indMaxValue == ind)
        {
            break;
        }
        int temp = heap[ind];
        heap[ind] = heap[indMaxValue];
        heap[indMaxValue] = temp;
        ind = indMaxValue;
    }
}

void heapSort(char *heap, int count)
{
    for (int i = count / 2 - 1; i >= 0; i--)
    {
        shiftDown(heap, i, count);
    }

    int lastInd = count - 1;
    while (lastInd > 0)
    {
        int temp = heap[0];
        heap[0] = heap[lastInd];
        heap[lastInd] = temp;

        shiftDown(heap, 0, lastInd);
        lastInd--;
    }
}
