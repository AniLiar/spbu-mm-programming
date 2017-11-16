#include <iostream>

using namespace std;

int length(char *str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}

int main()
{
    char text[] = "abaaabbaas";
    char sample[] = "aa";
    const int lengthSample = length(sample);
    const int lengthText = length(text);
    int counter = 0;
    int quantity = 0;

    cout << "text: " << text << endl;
    cout << "sample: " << sample << endl;

    for (int i = 0; i < lengthText - lengthSample; i++)
    {
        for (int j = 0; j < lengthSample; j++)
        {
            if (text[i + j] == sample[j])
            {
                counter++;
            }
            else
            {
                break;
            }
        }
        if (counter == lengthSample)
        {
            quantity++;
        }
        counter = 0;
    }
    cout << "quantity: " << quantity;
    return 0;
}
