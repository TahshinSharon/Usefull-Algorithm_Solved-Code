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
int biper(int ver, int c) {
	col[ver] = c;
	vis[ver] = 1;
	for (auto cld : g[ver]) {
		if (!vis[cld]) {
			biper(cld, c ^ 1);
		}
		else if (col[ver] == c) {
			return 0;
		}
	}
	return 1;
}
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	if (biper(1, 0)) {
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
