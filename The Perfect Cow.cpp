#include <iostream>
#include <algorithm>

#define MAXN 99
#define MAXM 197

using namespace std;

int main()

{
    int number, ratings[MAXN][MAXN], medians[MAXM];
    cin >> number;
    for(int i = 0; i < number; i++)
        for(int j = 0; j < number; j++)
            cin >> ratings[i][j];
    for(int i = 0; i < number; i++)
    {
        int temp[MAXN];
        for(int j = 0; j < number; j++)
        {
            temp[j] = ratings[i][j];
        }
        sort(temp, temp+number);
        medians[i] = temp[(number-1)/2];
        //cout << medians[i] << endl;
    }
    sort(medians, medians+number);
    cout << medians[(number-1)/2] << endl;
}
