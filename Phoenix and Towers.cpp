#include <iostream>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int n, m, x, blocks[100000];
        cin >> n >> m >> x;
        for(int i = 0; i < n; n++)
        {
            cin >> blocks[i];
        }
        sort(blocks, blocks+n);
        if(blocks[n-1] - blocks[0] <= x)
        {
            cout << "YES" << endl;
            for(int i = 1; i <= n; i++)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if()
        {

        }
    }
}
