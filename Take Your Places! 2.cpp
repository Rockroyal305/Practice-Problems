#include <iostream>

using namespace std;

#define MAXN 100000

int main()

{
    int tests, n, a[MAXN];
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int evens = 0, odds = 0, goal[MAXN], distance = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = a[i]%2;
            if(a[i] == 1) odds++;
            else evens++;
        }
        /*for(int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;*/
        {
            if(n == 1)
                cout << 0 << endl;
            else if(evens == 0 || odds == 0)
                cout << -1 << endl;
            else if(n%2 == 0 && evens != odds)
                cout << -1 << endl;
            else if(n%2 == 1 && (evens != n/2 && odds != n/2))
                cout << -1 << endl;
        }
        if(n%2)
        {
            if(odds < evens)
            {
                int op = 1;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] % 2 == 0)
                    {
                        distance += abs(i - op);
                        op += 2;
                    }
                }
                cout << distance << endl;
                continue;
            }
            else
            {
                int op = 1;
                for (int i = 0; i < n; i++)
                {
                    if (a[i] % 2 == 1)
                    {
                        distance += abs(i - op);
                        op += 2;
                    }
                }
                cout << distance << endl;
                continue;
            }
        }
        else
        {
            int op1 = 1, op2 = 2;
            int distance1 = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 2 == 0)
                {
                    distance += abs(i - op1);
                    op1 += 2;
                    distance1 += abs(i - op2);
                    op2 += 2;
                }
            }
            cout << min(distance, distance1) << endl;
            continue;
        }
    }
}
