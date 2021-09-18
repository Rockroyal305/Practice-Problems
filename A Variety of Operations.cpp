#include <iostream>

using namespace std;

int main()

{
    int tests, a = 0, b = 0;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int c, d;
        cin >> c >> d;
        if(c == 0 && d == 0)
            cout << 0 << endl;
        else if(c == d)
            cout << 1 << endl;
        else if((c-d)%2 == 0)
            cout << 2 << endl;
        else
            cout << -1 << endl;
    }
}
