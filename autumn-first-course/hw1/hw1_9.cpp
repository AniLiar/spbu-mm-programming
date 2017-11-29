#include <iostream>

using namespace std;

int main()
{
    int baseNum = 0;
    int powerExp = 0;
    int result = 1;

    cout << "Enter the integer base number\n";
    cin >> baseNum;
    cout << "Enter the positive integer value of the power to which you want to raise the expression\n";
    cin >> powerExp;

    if (baseNum == 0)
    {
        if (powerExp == 0)
        {
            cout << "You can't do this";
        }
        else
        {
            cout << "Result = 0";
        }
    }
    else
    {
        if (powerExp > 0)
        {
            for (int i = 1; i <= powerExp; i++)
            {
                result *= baseNum;
            }
            cout << "Result = " << result;
        }
        else
        {
            if (powerExp == 0)
            {
                cout << "Result = 1";
            }
            else
            {
                cout << "Incorrect value of the power";
            }
        }
    }
    return 0;
}
