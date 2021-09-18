#include <iostream>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if(k == 0)
        {
            if(n % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if(m >= 2*k)
        {
            cout << "YES" << endl;
        }
        else if(n >= k && m >= 2)
            cout << "YES" << endl;
        else if()
        else
            cout << "NO" << endl;
    }
}
