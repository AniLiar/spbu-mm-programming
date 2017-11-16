#include <iostream>
using namespace std;

void arrToString(int *data, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

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

int main() {
    int size = 0;
    cout << "Enter the size of the array:\n";
    cin >> size;

    int *data = new int[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter value: element[" << i + 1 << "] = ";
        cin >> data[i];
    }
    arrToString(data, size);
    quickSortRecurs(data, 0, size - 1);
    arrToString(data, size);
    delete [] data;

    return 0;
}
