#include <iostream>

using namespace std;

void decompose(int *terms, int remainingSum, int maxValue, int currInd)
{
    if (remainingSum < 0)
    {
        return;
    }
    if (remainingSum == 0)
    {
        for (int j = 0; j < currInd; j++)
        {
            cout << terms[j] << (j != (currInd - 1) ? " + " : "\n");
        }
    }
    else
    {
        if (remainingSum - maxValue >= 0)
        {
            terms[currInd] = maxValue;
            decompose(terms, remainingSum - maxValue, maxValue, currInd + 1);
        }

        if (maxValue - 1 > 0)
        {
            decompose(terms, remainingSum, maxValue - 1, currInd);
        }
    }
    return;
}

int main()
{
    int number = 0;
    cout << "Enter an positive integer:" << endl;
    cin >> number;
    if (number > 1)
    {
        int *terms = new int[number];
        for (int i = 0; i < number; i++)
        {
            terms[i] = 0;
        }
        cout << "Compositions:" << endl;
        decompose(terms, number, number - 1, 0);
        delete [] terms;
    }
    else
    {
        cout << "Incorrect value";
    }
    return 0;
}
