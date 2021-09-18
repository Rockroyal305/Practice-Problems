#include <iostream>

using namespace std;

int main()

{
    int size, consecutive_brackets[1000];
    int64_t subsequences = 0;
    vector <char> sequence;
    cin >> size;
    for(int i = 0; i < size; i++)
        cin >> consecutive_brackets[i];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < consecutive_brackets[i]; j++)
        {
            if(i%2) sequence.push_back(')');//cout << ')';
            else sequence.push_back('(');//cout << '(';

        }
    }
    for(int i = 0; i < sequence.size(); i++)
}
