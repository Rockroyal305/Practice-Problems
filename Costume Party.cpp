#include <iostream>

#define MAXN 100000

using namespace std;

int main()

{
    int N, S, cows[MAXN], pairs = 0;
    cin >> N >> S;
    for(int i = 0; i < N; i++)
        cin >> cows[i];
    for(int i = 0; i < N-1; i++)
    {
        for(int j = i+1; j < N; j++)
        {
            if(cows[i]+cows[j] <= S)
                pairs++;
        }
    }
    cout << pairs << endl;
}
