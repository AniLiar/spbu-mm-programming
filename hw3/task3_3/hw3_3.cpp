#include <iostream>
#include "quicksort.h"

using namespace std;

void arrToString(int *data, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

int getNumOfDigits(int number)
{
    int numOfDigits = 1;
    const int decimalPlace = 10;
    while (number / decimalPlace > 0)
    {
        numOfDigits++;
        number /= decimalPlace;
    }

    return numOfDigits;
}

void splitNumber(int *digits, int count, int number)
{
    for (int i = 0; i < count; i++)
    {
        digits[i] = number % 10;
        number /= 10;
    }
}

int convertToNumber(int *digits, int count)
{
    int number = 0;
    int numPosition = 1;
    for (int i = count - 1; i >= 0; i--)
    {
        number += digits[i] * numPosition;
        numPosition *= 10;
    }
    return number;
}

int main()
{
    int number = 0;
    cout << "Enter a positive integer\n";
    cin >> number;
    if (number > 0)
    {
        int numOfDigits = getNumOfDigits(number);
        int *digits = new int[numOfDigits];
        splitNumber(digits, numOfDigits, number);
        arrToString(digits, numOfDigits);
        quickSortRecurs(digits, 0, numOfDigits - 1);
        arrToString(digits, numOfDigits);
        number = convertToNumber(digits, numOfDigits);
        cout << "The smallest number is " << number;
        delete [] digits;
    }
    else
    {
        cout << "Incorrect value";
    }
    return 0;
}
