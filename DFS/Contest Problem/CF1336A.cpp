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
const int N = 2e5 + 5;
vector<int>tre[N];
int depth[N];
int siz[N];
int dt[N];
int n, k;
long long ans = 0;
int cmp(int a, int b) {
	return a > b;
}
int dfs(int u, int p) {
	depth[u] = depth[p] + 1;
	siz[u] = 1;
	for (auto x : tre[u]) {
		if (x != p) {
			siz[u] += dfs(x, u);
		}
	}
	dt[u] = siz[u] - depth[u];
	return siz[u];
}
void solve() {
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		tre[u].push_back(v);
		tre[v].push_back(u);
	}
	dfs(1, 0);
	// for (int i = 0; i <= n; i++) {
	// 	cout << depth[i] << " ";
	// }
	// cout << nline;
	// for (int i = 0; i <= n; i++) {
	// 	cout << siz[i] << " ";
	// }
	// cout << nline;
	// for (int i = 0; i <= n; i++) {
	// 	cout << dt[i] << " ";
	// }
	// cout << nline;
	nth_element(dt + 1, dt + n - k, dt + n + 1, cmp);
	for (int i = 1; i <= n - k; ++i) {
		ans += dt[i];
	}
	cout << ans << nline;
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
