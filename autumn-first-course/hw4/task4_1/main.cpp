#include <iostream>
#include "matrix.h"

using namespace std;

void print(int element)
{
    cout << element << " ";
}

void printInSpiral(int **matrix, int size)
{
    if (size == 0)
    {
        return;
    }

    const int maxStep = size / 2;
    int step = 1;
    int iStep = 0;
    int jStep = 0;
    int iCenter = size / 2;
    int jCenter = size / 2;

    cout << "Output of array elements in a spiral:" << endl;
    cout << matrix[iCenter][jCenter] << " ";
    while (step <= maxStep)
    {
        while (iStep < step)
        {
            iStep++;
            print(matrix[iCenter + iStep][jCenter + jStep]);
        }
        while (jStep < step)
        {
            jStep++;
            print(matrix[iCenter + iStep][jCenter + jStep]);
        }
        while (iStep > -step)
        {
            iStep--;
            print(matrix[iCenter + iStep][jCenter + jStep]);
        }
        while (jStep > -step)
        {
            jStep--;
            print(matrix[iCenter + iStep][jCenter + jStep]);
        }
        while (iStep < step)
        {
            iStep++;
            print(matrix[iCenter + iStep][jCenter + jStep]);
        }
        step++;
    }
}

void testOffline()
{
    const int size1 = 3;
    cout << "Test #1" << endl;
    cout << "The size of the array where size is an odd number = " << size1 << endl;
    int **matrix1 = new int *[size1];
    matrix1[0] = new int [size1] {3, 4, 5};
    matrix1[1] = new int [size1] {2, 9, 6};
    matrix1[2] = new int [size1] {1, 8, 7};
    printMatrix(matrix1, size1);
    printInSpiral(matrix1, size1);
    destructMatrix(matrix1, size1);
    cout << "\n\n\n";

    const int sizeTest2 = 5;
    cout << "Test #2" << endl;
    cout << "The size of the array where size is an odd number = " << sizeTest2 << endl;
    int **matrix2 = new int *[sizeTest2];
    matrix2[0] = new int [sizeTest2] {21, 20, 19, 18, 17};
    matrix2[1] = new int [sizeTest2] {22,  7,  6,  5, 16};
    matrix2[2] = new int [sizeTest2] {23,  8,  1,  4, 15};
    matrix2[3] = new int [sizeTest2] {24,  9,  2,  3, 14};
    matrix2[4] = new int [sizeTest2] {25, 10, 11, 12, 13};
    printMatrix(matrix2, sizeTest2);
    printInSpiral(matrix2, sizeTest2);
    destructMatrix(matrix2, sizeTest2);
}

void testOnline()
{
    int size = 0;
    cout << "Enter the size of the array where size is an odd number:\n";
    cin >> size;

    if ((size > 0) && (size % 2 == 1))
    {
        int **matrix = createSquareMatrix(size);
        initSquareMatrix(matrix, size);
        printInSpiral(matrix, size);
        destructMatrix(matrix, size);
    }
    else
    {
        cout << "Incorrect value";
    }
}

int main()
{
    int mode = -1;
    cout << "Choose the program mode: offline or online testing" << endl;
    cout << "Enter 0 for offline, enter 1 for online:" << endl;
    cin >> mode;
    switch (mode) {
    case 0:
        testOffline();
        break;
    case 1:
        testOnline();
        break;
    default:
        cout << "Incorrect value";
        break;
    }
    return 0;
}
