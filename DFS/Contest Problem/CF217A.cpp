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
const int N = 1e3 + 5;
vector<int>g[N];
int vis[N];
int n;
void dfs(int ver) {
	vis[ver] = 1;
	for (int i = 1; i <= n; i++) {
		if (!vis[i] && (g[i][0] == g[ver][0] || g[i][1] == g[ver][1])) {
			dfs(i);
		}
	}
}
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		g[i].push_back(x);
		g[i].push_back(y);
	}
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);
			c++;
		}
	}
	cout << c - 1 << nline;
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
