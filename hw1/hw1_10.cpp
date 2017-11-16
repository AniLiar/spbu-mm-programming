#include <iostream>
using namespace std;

int length(char *str)
{
    int size = 0;
    while ((str[size] != '\n') && (str[size] != '\0'))
    {
        size++;
    }
    return size;
}

bool isPalindrome(char *text)
{
    int size = length(text);
    for (int i = 0; i < size / 2; i++)
    {
        if (text[i] != text[size - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main() {
    const int maxSize = 50;
    cout << "Warning: the program is case sensitive. The maximum length is 50.\n";
    cout << "Enter a string that consists only of English letters:\n";
    char text[maxSize];
    fgets(text, maxSize, stdin);
    if (isPalindrome(text))
    {
        cout << "String is polindrom";
    }
    else
    {
        cout << "String is not polindrom";
    }
    return 0;
}
