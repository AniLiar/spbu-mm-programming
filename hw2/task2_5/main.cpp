#include <iostream>
#include "heapsort.h"

using namespace std;

void arrToString(int *data, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size = 0;
    cout << "Enter the size of the array:\n";
    cin >> size;

    if (size > 0)
    {
        int *data = new int[size];
        for (int i = 0; i < size; i++)
        {
            cout << "Enter value: element[" << i + 1 << "] = ";
            cin >> data[i];
        }

        heapSort(data, size);
        cout << "Array:\n";
        arrToString(data, size);
        delete [] data;
    }
    else
    {
        cout << "Incorrect value";
    }

    return 0;
}
