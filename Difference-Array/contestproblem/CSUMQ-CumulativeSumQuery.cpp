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
	int n;
	cin >> n;
	vector<int>a(n + 1, 0);
	vector<int>pre(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	int q;
	cin >> q;
	while (q--) {
		int i, j;
		cin >> i >> j;
		cout << pre[j + 1] - pre[i] << nline;
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
//problem link:https://www.spoj.com/problems/CSUMQ/en/
