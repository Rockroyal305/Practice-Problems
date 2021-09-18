#include <iostream>

using namespace std;

#define MAXN 100000

int main()

{
    int tests, n, a[MAXN];
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int evens = 0, odds = 0, goal[MAXN], differences = 0;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = a[i]%2;
            if(a[i] == 1) odds++;
            else evens++;
        }
        if(n == 1)
            cout << 0 << endl;
        else if(evens == 0 || odds == 0)
            cout << -1 << endl;
        else if(n%2 == 0 && evens != odds)
            cout << -1 << endl;
        else if(n%2 == 0)
        {
            if(a[0] == 0)
            {
                for(int i = 0; i < n; i+=2)
                {
                    goal[i] = 0;
                }
                for(int i = 1; i < n; i+=2)
                {
                    goal[i] = 1;
                }
            }
            else
            {
                for(int i = 0; i < n; i+=2)
                {
                    goal[i] = 1;
                }
                for(int i = 1; i <= n; i+=2)
                {
                    goal[i] = 0;
                }
            }
            for(int i = 0; i < n; i++)
            {
                if(goal[i] != a[i])
                    differences++;
            }
            cout << differences/2 + differences%2 << endl;
        }
        else
        {
            if(odds == n%2 || evens == n%2)
            {
                if(odds > evens)
                {
                    for(int i = 0; i < n; i+=2)
                    {
                        goal[i] = 1;
                    }
                    for(int i = 1; i < n; i+=2)
                    {
                        goal[i] = 0;
                    }
                }
                else
                {
                    for(int i = 0; i < n; i+=2)
                    {
                        goal[i] = 0;
                    }
                    for(int i = 1; i < n; i+=2)
                    {
                        goal[i] = 1;
                    }
                }
                for(int i = 0; i < n; i++)
                {
                    if(goal[i] != a[i])
                        differences++;
                }
                cout << differences/2 + differences%2 << endl;
            }
            else
                cout << -1 << endl;
        }
    }
}
