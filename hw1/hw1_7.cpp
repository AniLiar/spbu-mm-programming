#include <iostream>
using namespace std;

int main() {
    printf("Enter a positive integer less than 100\n");
    const int maxSize = 100;
    int n = 0;
    scanf("%d", &n);

    if (n < maxSize)
    {
        if (n > 1)
        {
            bool isPrime[maxSize];
            isPrime[0] = false;
            isPrime[1] = false;
            for (int i = 2; i < maxSize; i++)
            {
                isPrime[i] = true;
            }

            for (int i = 2; i * i <= n; i++)
            {
                if (isPrime[i])
                {
                    for (int j = i * i; j <= n; j += i)
                    {
                        isPrime[j] = false;
                    }
                }
            }

            printf("Prime numbers:\n");
            for (int i = 2; i <= n; i++)
            {
                if (isPrime[i])
                {
                    printf("%d ", i);
                }
            }
        }
        else
        {
            printf("There are no prime numbers");
        }
    }
    else
    {
        printf("Incorrect value");
    }
    return 0;
}
