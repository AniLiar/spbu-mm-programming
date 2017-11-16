#include <iostream>
using namespace std;

unsigned int getFibNumIter(int indexNum)
{
    unsigned int prevFibNum = 0;
    unsigned int currFibNum = 1;

    if (indexNum == 0)
    {
            return 0;
    }
    else
    {
        for (int i = 2; i <= indexNum; i++)
        {
            int temp = prevFibNum + currFibNum;
            prevFibNum = currFibNum;
            currFibNum = temp;
        }
        return currFibNum;
    }
}

unsigned int getFibNumRecurs(int indexNum)
{
    if (indexNum == 0)
    {
        return 0;
    }
    else
    {
        if (indexNum == 1)
        {
                return 1;
        }
        else
        {
            return getFibNumRecurs(indexNum - 1) + getFibNumRecurs(indexNum - 2);
        }
    }
}

int main() {
    cout << "Enter the index of the Fibonacci number:\n";
    int indexFibNum = 0;
    cin >> indexFibNum;

    unsigned int fibNum = 0;

    if (indexFibNum < 0)
    {
        cout << "Incorrect value";
    }
    else
    {
        fibNum = getFibNumIter(indexFibNum);
        cout << "Iteratively: Fib Number[" << indexFibNum << "] = "  << fibNum << "\n";

        fibNum = getFibNumRecurs(indexFibNum);
        cout << "Recursively: Fib Number[" << indexFibNum << "] = "  << fibNum;
    }
    return 0;
}
