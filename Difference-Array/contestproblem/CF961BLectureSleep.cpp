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
	int n, k;
	cin >> n >> k;
	int a[n + 2];
	int tn[n + 2];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int res = 0;
	vector<int>s(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> tn[i];
		s[i] = s[i - 1];
		if (tn[i]) {
			res += a[i];
		}
		else {
			s[i] = s[i - 1] + a[i];
		}
	}
	int mx = 0;
	for (int i = 0; i <= n - k; i++) {
		mx = max(mx, (s[i + k] - s[i]));
	}
	cout << res + mx << nline;
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
