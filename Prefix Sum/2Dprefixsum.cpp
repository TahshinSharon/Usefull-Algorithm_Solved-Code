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
	int n, m, q;
	cin >> n >> m;
	vector<vector<int>>v(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>>pre(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + v[i][j] - pre[i - 1][j - 1];
		}
	}
	cin >> q;
	while (q--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll ans = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 - 1][y1 - 1];
		cout << ans << nline;
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