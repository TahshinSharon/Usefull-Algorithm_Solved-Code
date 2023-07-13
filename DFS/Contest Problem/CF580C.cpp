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
const int N = 1e5 + 5;
int s = 0;
vector<int>tre[N];
int a[N];
int cur[N];
int vis[N];
int n, m, ans = 0;
void dfs(int ver, int par, int s) {
	if (a[ver]) s++;
	else s = 0;
	if (s > m) return;
	vis[ver] = 1;
	for (auto cld : tre[ver]) {
		if (!vis[cld]) {
			dfs(cld, ver, s);
		}
	}
	if (ver != 1 && tre[ver].size() == 1) {
		ans++;
	}
}
void solve() {
	cin >> n >> m;
	// s = 0;
	// ans = 0;
	// for (int i = 0; i <= n + 1; i++) {
	// 	a[i] = 0;
	// 	cur[i] = 0;
	// 	vis[i] = 0;
	// 	tre[i].clear();
	// }
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		tre[x].push_back(y);
		tre[y].push_back(x);
	}
	dfs(1, 0, 0);
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
