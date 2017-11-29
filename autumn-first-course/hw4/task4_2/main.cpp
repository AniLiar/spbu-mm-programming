#include <iostream>
#include <fstream>
#include "avltree.h"

using namespace std;

int main()
{
    ifstream fileStream("input.txt");
    char symbol = ' ';
    AVLTree *dict = createAVLTree();

    if (!fileStream.is_open())
    {
        perror("Can not open file");
        return -1;
    }

    cout << "The original text:\n" << endl;
    while (fileStream.get(symbol))
    {
        cout << symbol;
    }
    fileStream.clear();

    cout << endl << "\nResult:" << endl;
    fileStream.seekg(0, ios_base::beg);
    bool wasSpace = false;
    while (fileStream.get(symbol))
    {        
        if ((symbol >= 'A') && (symbol <= 'Z'))
        {
            symbol += 'z' - 'Z';
        }
        if ((symbol < 'a') || (symbol > 'z'))
        {
            if (!wasSpace)
            {
                cout << " ";
                clearAVLTree(dict);
                wasSpace = true;
            }
        }
        else
        {
            if (!contains(dict, symbol))
            {
                add(dict, symbol);
                cout << symbol;
            }
            wasSpace = false;
        }
    }
    fileStream.close();
    clearAVLTree(dict);
    delete dict;
    return 0;
}
