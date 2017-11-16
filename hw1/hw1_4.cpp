#include <iostream>
using namespace std;

int main() {
    const int countSum = 28;
    const int maxNum = 9;
    int a[countSum];
    for (int i = 0; i < countSum; i++)
    {
        a[i] = 0;
    }
    
    for (int i = 0; i <= maxNum; i++)
    {
        for (int j = 0; j <= maxNum; j++)
        {
            for (int k = 0; k <= maxNum; k++)
    	       {
    	           a[i + j + k]++;
    	       }
        }
    }
    
    int result = 0;
    for (int i = 0; i < countSum; i++)
    {
        result += a[i] * a[i];
    }
    printf("The number of happy tickets is %d", result);
    return 0;
}
