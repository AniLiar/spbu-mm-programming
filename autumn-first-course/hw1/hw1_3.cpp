#include <iostream>
using namespace std;

void arrToString(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", array[i]);
    }
}

void arrInvert(int *array, int n)
{
    for (int i = 0; i < n/2 ; i++)
    {
        int temp = array[i];
        array[i] = array[n - i - 1];
        array[n - i - 1] = temp;
    }
}

int main() {
    int n = 3;
    int m = 6;
    int count = n + m;
    int data[count] = {-2, -7, -1, 1, 6, 1, 8, 0, 3};
    
    printf("Array:\n");
    arrToString(data, count);
    
    arrInvert(&data[0], n);
    arrInvert(&data[n], m);
    arrInvert(&data[0], count);

    printf("\nInverted array:\n");    
    arrToString(data, count);
    return 0;
}
