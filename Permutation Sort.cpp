#include <iostream>

using namespace std;

int min(int num1, int num2)
{
    if(num1 <= num2)
        return num1;
    return num2;
}

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int number, numbers[50];
        bool working = true;
        cin >> number;
        for(int i = 0; i < number; i++)
        {
            cin >> numbers[i];
        }
        for(int i = 0; i < number-1; i++)
        {
            if(numbers[i] == i+1)
                continue;
            else
                working = false;
        }
        if(working)
            cout << 0 << endl;
        else
        {
            if(numbers[0] == 1 || numbers[number-1] == number)
            {
                cout << 1 << endl;
            }
            else if(numbers[0] == number && numbers[number-1] == 1)
                cout << 3 << endl;
            else
                cout << 2 << endl;
        }
    }
}
