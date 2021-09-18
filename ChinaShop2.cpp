#include <iostream>

#define MAXN 8
#define MAXK 10

using namespace std;

int main()

{
    int N, K;
    char original[MAXN][MAXN], pieces[MAXN][MAXN][MAXK];
    cin >> N >> K;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> original[i][j];
    for(int i = 0; i < K; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                cin >> pieces[j][k][i];

}
