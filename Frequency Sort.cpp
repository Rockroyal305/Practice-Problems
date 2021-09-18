#include <iostream>
#include <map>
#include <algorithm>

#define MAXN 1000

using namespace std;

map <int, int> frequencies;
int N, C, numbers[MAXN], reference[MAXN];

bool frequency_sort(int num1, int num2)
{
    if(frequencies[num1] != frequencies[num2])
        return frequencies[num1] > frequencies[num2];
    else
    {
        int loc1, loc2;
        for(int i = 0; i < N; i++)
        {
            if(reference[i] == num1)
            {
                loc1 = i;
                break;
            }
        }
        for(int i = 0; i < N; i++)
        {
            if(reference[i] == num2)
            {
                loc2 = i;
                break;
            }
        }
        return loc1 < loc2;
    }
}

int main()
{
    //cout << frequencies[0] << endl;
    cin >> N >> C;
    for(int i = 0; i < N; i++)
    {
        cin >> numbers[i];
        frequencies[numbers[i]]++;
        reference[i] = numbers[i];
    }
    /*for(int i = 0; i < N; i++)
        cout << numbers[i] << ": " << frequencies[numbers[i]] << endl;*/
    sort(numbers, numbers+N, frequency_sort);
    for(int i = 0; i < N; i++)
        cout << numbers[i] << " ";
}
