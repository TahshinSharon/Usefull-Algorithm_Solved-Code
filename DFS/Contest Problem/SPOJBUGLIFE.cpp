#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define MAX 500000
#define MOD 100000007
#define INF INT_MAX
#define LINF LLONG_MAX
#define pi acos(-1.0)
#define F first
#define S second
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
const int N = 1e6 + 5;
vector<int>g[N];
int vis[N];
int col[N];
int f = 1;
void biper(int ver, int c) {
	col[ver] = c;
	vis[ver] = 1;
	for (auto cld : g[ver]) {
		if (!vis[cld]) {
			biper(cld, c ^ 1);
		}
		else if (col[cld] == c) {
			f = 0;
		}
	}
}
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
		col[i] = 0;
		g[i].clear();
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	f = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			biper(i, 0);
		}
	}
	if (!f) {
		cout << "Suspicious bugs found!" << nline;
	}
	else {
		cout << "No suspicious bugs found!" << nline;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Scenario #" << i << ":" << nline;
		solve();
	}
	return 0;
}
