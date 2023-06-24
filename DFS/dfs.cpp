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
const int N = 1e5 + 7;
vector<int>g(N);
int vis[N];
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
void dfs(int ver) {
	/* Take action on vertex after entering the vertex */
	vis[ver] = 1;
	for (auto cld : g[ver]) {
		if (vis[cld]) continue;
		/* Take action on child before entering the child node */
		dfs(cld);
		/* Take action on child after existing the child node */
	}
	/* Take action on child before existing the vertex */
}
void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	dfs(1)
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		//cout<<"Case "<<i<<": ";
		solve();
	}
	return 0;
}
