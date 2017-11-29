#include <iostream>
using namespace std;

unsigned int getFactorialIter(int n)
{
   unsigned int result = 1;

   if (n < 2)
   {
       return result;
   }
   else
   {
       for (int i = 2; i <= n; i++)
       {
           result *= i;
       }
       return result;
   }
}

unsigned int getFactorialRecurs(int n)
{
    if (n < 2)
    {
        return 1;
    }
    else
    {
         return n * getFactorialRecurs(n - 1);
    }
}

int main() {

    cout << "Enter a positive integer\n";
    int n = 0;
    unsigned int result = 0;

    cin >> n;

    if (n < 0)
    {
        cout << "Incorrect value";
    }
    else
    {
        result = getFactorialIter(n);
        cout << "Iteratively: Factorial(" << n << ") = "  << result << "\n";

        result = getFactorialRecurs(n);
        cout << "Recursively: Factorial(" << n << ") = "  << result;
    }
    return 0;
}
