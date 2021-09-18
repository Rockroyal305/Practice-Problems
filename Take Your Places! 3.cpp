#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int w[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p1 = 0;
        int p2 = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> w[i];
            if (w[i] % 2 == 1)
            {
                w[i] = 1;
                p1++;
            }
            else
            {
                w[i] = 0;
                p2++;
            }
        }
        if (n % 2 == 0)
        {
            if (p1 * 2 != n)
            {
                cout << -1 << endl;
                continue;
            }
        }
        else
        {
            if (abs(n - p1 - p1) != 1)
            {
                cout << -1 << endl;
                continue;
            }
        }
        int ans = 0;
        if (n % 2)
        {
            if (p1 < p2)
            {
                int op = 1;
                for (int i = 1; i <= n; i++)
                {
                    if (w[i] % 2 == 0)
                    {
                        ans += abs(i - op);
                        op += 2;
                    }
                }
                cout << ans << endl;
                continue;
            }
            else
            {
                int op = 1;
                for (int i = 1; i <= n; i++)
                {
                    if (w[i] % 2 == 1)
                    {
                        ans += abs(i - op);
                        op += 2;
                    }
                }
                cout << ans << endl;
                continue;
            }
        }
        else
        {
            int op1 = 1, op2 = 2;
            int ans1 = 0;
            for (int i = 1; i <= n; i++)
            {
                if (w[i] % 2 == 0)
                {
                    ans += abs(i - op1);
                    op1 += 2;
                    ans1 += abs(i - op2);
                    op2 += 2;
                }
            }
            cout << min(ans, ans1) << endl;
            continue;
        }
    }
}
