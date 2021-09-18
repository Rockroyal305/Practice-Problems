#include <iostream>

#define MAXN 100000

using namespace std;

struct horizontal
{
    int row, column1, column2;
};

int main()

{
    int n, m, verticals[MAXN];
    horizontal horizontals[MAXN];
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> verticals[i];
    for(int i = 0; i < m; i++)
        cin >> horizontals[i].row >> horizontals[i].column1 >> horizontals[i].column2;
}


