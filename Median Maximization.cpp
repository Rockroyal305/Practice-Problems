#include <iostream>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++)
    {
        int n, s;
        cin >> n >> s;
        if(n == 1)
            cout << s << endl;
        else if(n == 2)
            cout << s/2 << endl;
        else
        {
            if(n%2 == 0)
            {
                cout << s/(n-(n/2-1)) << endl;
            }
            else
            {
                cout << s/(n-n/2) << endl;
            }
        }
    }

}
