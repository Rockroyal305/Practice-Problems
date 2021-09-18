#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

bool reverse_sort(int num1, int num2)

{
    return num1 >= num2;
}

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int number, numbers[2000], good_pairs = 0;
        cin >> number;
        for(int i = 0; i < number; i++)
            cin >> numbers[i];
        sort(numbers, numbers+number, reverse_sort);
        /*for(int i = 0; i < number; i++)
            cout << numbers[i] << " ";
        cout << endl;*/
        for(int i = 0; i < number-1; i++)
        {
            for(int j = i+1; j < number; j++)
            {
                if(__gcd(numbers[i], 2*numbers[j]) > 1)
                    good_pairs++;
            }
        }
        cout << good_pairs << endl;
    }
}
