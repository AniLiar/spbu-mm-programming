#include <iostream>

using namespace std;

int main()
{
    string text = "";
    int counter = 0;
    cout << "Enter an expression without spaces" << endl;
    cin >> text;
    int length = text.length();
    for(int i = 0; i < length; i++)
    {
        if (text[i] == '(')
        {
            counter++;
        }
        else
        {
            if ((counter == 0) && (text[i] == ')'))
            {
                counter--;
                break;
            }
            else
            {
                if (text[i] == ')')
                {
                    counter--;
                }
            }
        }
    }

    if (counter == 0)
    {
        cout << "The expression is correct";
    }
    else
    {
        cout << "The expression is incorrect";
    }
    return 0;
}
