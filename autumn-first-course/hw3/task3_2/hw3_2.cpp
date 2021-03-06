#include <iostream>
#include "heapsort.h"

using namespace std;

void toLower(char *str, int length)
{
    for (int i = 0; i < length; i++)
    {
        if ((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            str[i] += 'z' - 'Z';
        }
    }
}

int getLength(char *str)
{
    int size = 0;
    while ((str[size] != '\n') && (str[size] != '\0'))
    {
        size++;
    }
    return size;
}

char *input(int maxSize)
{
    char *text = new char[maxSize];
    cout << "Warning: The maximum length is 50.\n";
    cout << "Enter the string that consists only of English letters:\n";
    return fgets(text, maxSize, stdin);
}

bool isAnagram(char *text1, int lenText1, char *text2, int lenText2)
{
    if (lenText1 != lenText2)
    {
        return false;
    }

    heapSort(text1, lenText1);
    heapSort(text2, lenText2);
    for (int i = 0; i < lenText1; i++)
    {
        if (text1[i] != text2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    const int maxSize = 50;
    char *text1 = input(maxSize);
    char *text2 = input(maxSize);

    int lenText1 = getLength(text1);
    int lenText2 = getLength(text2);

    toLower(text1, lenText1);
    toLower(text2, lenText2);

    char resultTrue[] = "You can get the second line by rearranging the characters in the first line.";
    char resultFalse[] = "You can NOT get the second line by rearranging the characters in the first line.";
    cout << (isAnagram(text1, lenText1, text2, lenText2) ? resultTrue : resultFalse);

    delete [] text1;
    delete [] text2;

    return 0;
}
