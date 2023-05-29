#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
void solve() {
	int n, m;
	cin >> n >> m;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	set<int>s;
	vector<int>v(n + 1, 0);
	for (int i = n; i > 0; i--) {
		s.insert(a[i]);
		v[i] = s.size();
	}
	while (m--) {
		int l;
		cin >> l;
		cout << v[l] << nline;
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
