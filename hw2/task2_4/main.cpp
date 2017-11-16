#include <iostream>
#include "fraction.h"

using namespace std;

int getGCD(int firstNum, int secNum)
{
    while ((firstNum != 0) && (secNum != 0))
    {
        if (firstNum > secNum)
        {
            firstNum %= secNum;
        }
        else
        {
            secNum %= firstNum;
        }
    }
    return firstNum + secNum;
}

void fractionToSting(Fraction *fractions, int size)
{
    cout << "The simple irreducible fractions:\n";
    for (int i = 0; i < size; i++)
    {
        cout << fractions[i].numerator << "/" << fractions[i].denominator << endl;
    }

}

int main()
{
    cout << "Enter a positive integer:" << endl;
    int denom = 0;
    cin >> denom;

    if (denom > 0)
    {
        if (denom == 1)
        {
            cout << "No fractions";
        }
        else
        {
            Fraction *fractions = new Fraction[denom * denom / 2];
            int lastInd = 0;

            for (int j = 2; j <= denom; j++)
            {
                for (int i = 1; i < j; i++)
                {
                    if (getGCD(j, i) == 1)
                    {
                        fractions[lastInd].numerator = i;
                        fractions[lastInd].denominator = j;
                        fractions[lastInd].value = i / (double)j;
                        lastInd++;
                    }
                }
            }
            quickSortRecurs(fractions, 0, lastInd - 1);
            fractionToSting(fractions, lastInd);
            delete [] fractions;
        }
    }
    else
    {
        cout << "Incorrect value";
    }
    return 0;
}
