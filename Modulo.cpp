#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main()

{
    int numbers[10];
    int comparison_number;
    set <int> distinct_numbers;
    for(int i = 0; i < 10; i++)
    {
        cin >> numbers[i];
        numbers[i] = numbers[i] % 42;
        //cout << numbers[i] << endl;
    }
    for(int i = 0; i < 10; i++)
    {
        distinct_numbers.insert(numbers[i]);
    }
    cout << distinct_numbers.size();
}
