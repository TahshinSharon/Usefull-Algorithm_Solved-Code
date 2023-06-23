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
const int N = 2e3 + 5;
vector<int>tre[N];
int vis[N];
int met[N];
int c = 0;
void dfs(int ver, int par, int dis) {
	met[ver] = dis;
	c = max(c, dis);
	for (auto cld : tre[ver]) {
		if (cld != par) {
			dfs(cld, ver, met[ver] + 1);
		}
	}
}
void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		if (p > 0) {
			tre[i].push_back(p);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (met[i] == 0) {
			dfs(i, -1, 0);
		}
	}
	cout << c + 1 << nline;
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
