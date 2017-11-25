#include <iostream>
#include "matrix.h"

using namespace std;

int **createSquareMatrix(int size)
{
    int **ptrArray = new int *[size];
    for (int i = 0; i < size; i++)
    {
        ptrArray[i] = new int [size];
    }
    return ptrArray;
}

void initSquareMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Enter value: element[" << i + 1 << ", " << j + 1 << "] = ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int **matrix, int size)
{
    cout << "The initial matrix:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << ((matrix[i][j] / 10 == 0) ? " " : "") << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void destructMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}
