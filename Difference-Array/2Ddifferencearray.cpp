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
	vector<vector<int>>a(n + 2, vector<int>(m + 2, 0));
	vector<vector<int>>dif(n + 2, vector<int>(m + 2, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			dif[i][j] = a[i][j] + a[i - 1][j - 1] - a[i][j - 1] - a[i - 1][j];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int x1, y1, x2, y2, val;
		cin >> x1 >> y1 >> x2 >> y2 >> val;
		dif[x1][y1] += val;
		dif[x2 + 1][y2 + 1] += val;
		dif[x1][y2 + 1] -= val;
		dif[x2 + 1][y1] -= val;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = dif[i][j] + a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << a[i][j] << " ";
		}
		cout << nline;
	}
	cout << nline;
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