#include<bits/stdc++.h>
using namespace std;
#define ll                  long long
#define ull                 unsigned long long LL
#define md                  10000007
#define pb                  push_back
#define mp                  make_pair
#define pp                  pair<LL,LL>
#define nline "\n"
vector<int>dif(200005, 0);
vector<int>a(200005, 0);
vector<int>pre(200005, 0);
void solve() {
	int n, k, q;
	cin >> n >> k >> q;
	// vector<int>v(200005, 0);
	// vector<int>dif(200005, 0);
	// vector<int>a(200005, 0);
	// vector<int>pre(200005, 0);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		dif[x]++;
		dif[y + 1]--;
	}
	for (int i = 1; i <= 200005; i++) {
		a[i] = dif[i] + a[i - 1];
	}
	for (int i = 1; i <= 200005; i++) {
		if (a[i] < k) {
			a[i] = 0;
		}
		else {
			a[i] = 1;
		}
	}
	for (int i = 1; i <= 200005; i++) {
		pre[i] = a[i] + pre[i - 1];
	}
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << pre[b] - pre[a - 1] << nline;
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
// https://codeforces.com/problemset/problem/816/B
