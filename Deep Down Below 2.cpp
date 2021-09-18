#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
#define int long long
int n;
#define ii pair<int,int>
ii a[N];
bool cmp (ii a, ii b) {
	return (a.first == b.first ? a.second > b.second : a.first < b.first);
}
void solve () {
	cin >> n;
	for (int i=1; i<=n; i++) {
		a[i].first =0;
		int k; cin >> k;
		int cur = 0;
		for (int j=1; j<=k; j++) {
			int x; cin >> x;
			if (cur <= x) {
				a[i].first += (x+1-cur);
				cur = x + 1;
			}
			cur ++;
		}
		a[i].second = k;
	}
	sort (a+1,a+n+1,cmp);
	int st = 0; int now = st;
	for (int i=1; i<=n; i++) {
		if (now < a[i].first) st += (a[i].first-now), now = a[i].first;
		now += a[i].second;
	}
	cout << st << '\n';
}
signed main( ) {
	int t;
	cin>>t;
	while (t--) {
		solve ();
	}
}
