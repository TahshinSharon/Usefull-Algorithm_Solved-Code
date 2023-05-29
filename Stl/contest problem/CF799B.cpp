#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  1000007
#define mod                 998244353
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
void solve() {
	int n;
	cin >> n;
	vector<int>v(n + 1);
	multiset<pair<int, int>>st[5];
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int>a(n);
	vector<int>b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		st[a[i]].insert({v[i], b[i]});
		st[b[i]].insert({v[i], a[i]});
	}
	int m;
	cin >> m;
	while (m--) {
		int x;
		cin >> x;
		if (st[x].empty()) {
			cout << -1 << nline;
		}
		else {
			cout << st[x].begin()->first << " ";
			int y = st[x].begin()->second;
			int z = st[x].begin() ->first;
			st[y].erase({z, x});
			st[x].erase({z, y});
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) {
		//cout<<"Case "<<i<<": ";
		solve();
	}
	return 0;
}
