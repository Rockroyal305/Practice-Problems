#include <iostream>

using namespace std;

int main()

{
    int convertFromCopy, digit, convertTo;
    unsigned int convertFrom;
    string stringDigit, answer;

    //cout << "Num (base 10): ";
    cin >> convertFrom;
    //cout << "Base: ";
    cin >> convertTo;

    convertFromCopy = convertFrom;

    while (convertFrom != 0){
        digit = convertFrom % convertTo;

        if (digit < 10)
            stringDigit = '0' + digit;
        else
            stringDigit = digit - 10 + 'A';

        answer = stringDigit + answer;

        convertFrom /= convertTo;
    }
    //cout << convertFromCopy << " written in base " << convertTo << " is: " << answer;
    cout << answer << endl;
    return 0;
}
