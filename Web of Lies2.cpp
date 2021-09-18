#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> friends(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        if (v > u)
            friends[u]++;
        else
            friends[v]++;
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (friends[i] == 0)
            ++count;
    }
    int q;
    cin >> q;
    while (q-- > 0) {
        int c;
        cin >> c;
        if (c == 1) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            if (u > v)
                swap(u, v);
            if (friends[u] == 0)
                --count;
            ++friends[u];
        } else if (c == 2) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            if (u > v)
                swap(u, v);
            if (friends[u] == 1)
                ++count;
            --friends[u];
        } else {
            cout << count << "\n";
        }
    }
    return 0;
}
