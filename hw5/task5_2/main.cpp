#include <iostream>

using namespace std;

const int numOfBitsInByte = 8;
const int sizeOfInt = sizeof(int) * numOfBitsInByte;

bool *convertToBinary(int value)
{
    bool *bits = new bool[sizeOfInt];
    unsigned int bitMask = 1 << (sizeOfInt - 1);
    for (int i = 0; i < sizeOfInt; i++)
    {
        bits[i] = (value & bitMask);
        bitMask = bitMask >> 1;
    }
    return bits;
}

void printToBinary(bool *binaryNum)
{
    for (int i = 0; i < sizeOfInt; i++)
    {
        cout << (binaryNum[i] ? "1" : "0");
    }
}

bool *getBinarySum(bool *firstNum, bool *secondNum)
{
    bool *result = new bool[sizeOfInt];
    bool memory = false;
    for (int i = sizeOfInt - 1; i >= 0; i--)
    {
        result[i] = firstNum[i] ^ secondNum[i] ^ memory;
        memory = ((firstNum[i] || secondNum[i]) && memory) || (firstNum[i] && secondNum[i]);
    }
    return result;
}

int getNumBySignMagnitude(bool *signMagnitudeOfNum)
{
    int decimal = signMagnitudeOfNum[sizeOfInt - 1] ? 1 : 0;
    int multiplier = 2;
    for (int i = sizeOfInt - 2; i > 0; i--)
    {
        if (signMagnitudeOfNum[i])
        {
            decimal += multiplier;
        }
        multiplier = multiplier << 1;
    }
    if (signMagnitudeOfNum[0])
    {
        decimal = 0 - decimal;
    }
    return decimal;
}

int convertToDecimal(bool *twosComplementOfNum)
{
    if (twosComplementOfNum[0])
    {
        bool *addBit = convertToBinary(-1);
        bool *onesComplementOfNum = getBinarySum(twosComplementOfNum, addBit);
        for (int i = sizeOfInt - 1; i > 0; i--)
        {
            onesComplementOfNum[i] = !onesComplementOfNum[i];
        }
        int decimal = getNumBySignMagnitude(onesComplementOfNum);
        delete[] onesComplementOfNum;
        delete[] addBit;
        return decimal;
    }
    else
    {
        return getNumBySignMagnitude(twosComplementOfNum);
    }
}

int main()
{
    int firstNum = 0;
    int secondNum = 0;

    cout << "Enter the first number:" << endl;
    cin >> firstNum;
    bool *firstNumBits = convertToBinary(firstNum);
    printToBinary(firstNumBits);

    cout << "\nEnter the second number:" << endl;
    cin >> secondNum;
    bool *secondNumBits = convertToBinary(secondNum);
    printToBinary(secondNumBits);

    cout << "\nBinary sum:" << endl;
    bool *result = getBinarySum(firstNumBits, secondNumBits);
    printToBinary(result);

    int decimal = convertToDecimal(result);
    cout << "\nDecimal sum:\n" << decimal;

    delete[] firstNumBits;
    delete[] secondNumBits;
    delete[] result;
    return 0;
}
